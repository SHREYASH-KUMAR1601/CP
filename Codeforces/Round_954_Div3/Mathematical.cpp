#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;
#define IOS ios_base::sync_with_stdio(0)
#define int long long

void solve() {
	int n;
	string s;
	cin >> n >> s;

	if (n == 2) {
		cout << stoi(s) << endl;
		return;
	}

	int ans = INT_MAX;
	for (int i = 0; i < n - 1; ++i) {
		vector<int> a;
		for (int j = 0; j < i; ++j) {
			a.push_back(s[j] - '0');
		}
		a.push_back(stoi(s.substr(i, 2)));
		for (int j = i + 2; j < n; ++j) {
			a.push_back(s[j] - '0');
		}
		sort(a.begin(), a.end());
		if (a[0] == 0) {
			cout << 0 << endl;
			return;
		}
		int sum = 0;
		for (auto &el : a) {
			if (el != 1) {
				sum += el;
			}
		}
		if (sum == 0) {
			sum = 1;
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
}

int32_t main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}