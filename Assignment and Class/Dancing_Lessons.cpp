#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		a[i] = {k, i + 1};
	}

	vector<pair<int, int>> result;
	while (true) {
		int diff = INT_MAX;
		pair<int, int> ans1 = {0, 0};
		int index = -1;

		for (int i = 0; i < n - 1; ++i) {
			if ((s[i] == 'B' && s[i + 1] == 'G') || (s[i] == 'G' && s[i + 1] == 'B')) {
				if (abs(a[i].first - a[i + 1].first) < diff) {
					ans1 = {min(a[i].second, a[i + 1].second), max(a[i].second, a[i + 1].second)};
					diff = abs(a[i].first - a[i + 1].first);
					index = i;
				}
			}
		}

		if (ans1.first == 0 && ans1.second == 0) {
			break;
		}

		result.push_back(ans1);
		s.erase(index, 2);
		a.erase(a.begin() + index, a.begin() + index + 2);
		n -= 2;
	}

	cout << result.size() << endl;
	for (const auto& p : result) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}
