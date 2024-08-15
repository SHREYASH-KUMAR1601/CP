#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0)

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n + 1, 0); // for 1 based indexing
		map<int, vector<int>> mp;
		for (int i = 1; i < n + 1; ++i) {
			cin >> a[i];
			mp[a[i] % k].push_back(a[i] / k);
		}

		int rem = n % 2;
		int ans = 0;
		for (auto p : mp) {
			vector<int>& vec = p.second;
			int sz = vec.size();
			sort(vec.begin(), vec.end());

			if (sz % 2) {
				if (rem == 0) {
					cout << -1 << endl;
					goto next_case; // To continue with the next test case
				}
				rem--;
				if (sz == 1) {
					continue;
				}

				vector<int> pre(sz, 0), suff(sz, 0);
				pre[1] = vec[1] - vec[0];

				for (int i = 3; i < sz; i += 2) {
					pre[i] = pre[i - 2] + vec[i] - vec[i - 1];
				}

				suff[sz - 2] = vec[sz - 1] - vec[sz - 2];

				for (int i = sz - 4; i >= 0; i -= 2) {
					suff[i] = suff[i + 2] + vec[i + 1] - vec[i];
				}

				int mn = INT_MAX;

				for (int i = 0; i < sz; i += 2) {
					int sum = 0;
					if (i > 0) {
						sum += pre[i - 1];
					}

					if (i < sz - 1) {
						sum += suff[i + 1];
					}

					mn = min(mn, sum);
				}
				ans += mn;
				continue;
			}
			for (int i = 1; i < sz; i += 2) {
				ans += vec[i] - vec[i - 1];
			}
		}
		cout << ans << endl;

next_case:
		continue;
	}

	return 0;
}
