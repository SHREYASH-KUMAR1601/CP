/*
*    Author: ShreyashxDON
*    Created: Monday, 12.08.2024 02:10 PM (GMT+5:30)
*/
#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

// #if __cplusplus < 201703L
// #error "C++17 or later is required"
// #endif

const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;

	vector<pair<pair<int, int>, int>> inc; // ai < bi
	vector<pair<pair<int, int>, int>> dec; // ai > bi

	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < y) {
			inc.push_back({{x, y}, i});
		} else {
			dec.push_back({{x, y}, i});
		}
	}

	sort(inc.rbegin(), inc.rend(), [](const auto & lhs, const auto & rhs) {
		return lhs.first.first < rhs.first.first;
	});

	sort(dec.begin(), dec.end(), [](const auto & lhs, const auto & rhs) {
		return lhs.first.second < rhs.first.second;
	});

	if (inc.size() > dec.size()) {
		cout << inc.size() << endl;
		for (auto p : inc) {
			cout << p.second << " ";
		}
	} else {
		cout << dec.size() << endl;
		for (auto p : dec) {
			cout << p.second << " ";
		}
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
