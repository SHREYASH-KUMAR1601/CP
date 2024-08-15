/*
*    Author: ShreyashxDON
*    Created: Monday, 12.08.2024 01:01 PM (GMT+5:30)
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

// void solve() {
// 	int n, m;
// 	cin >> n >> m;

// 	vector<int> a(n), b(m);
// 	for (int i = 0; i < n; i++) {
// 		cin >> a[i];
// 	}
// 	for (int i = 0; i < m; i++) {
// 		cin >> b[i];
// 	}

// 	sort(a.begin(), a.end());
// 	sort(b.rbegin(), b.rend());

// 	int ans = 0;
// 	for (int i = 0; i < min(n, m) and a[i] < b[i]; i++) {
// 		ans += (b[i] - a[i]);
// 	}

// 	cout << ans << endl;
// }


//Using Ternary Search

int n, m;
vector<int> a, b;

int func(int k) {
	//All elements of a should be greater than k
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < k) {
			ans += (k - a[i]);
		}
	}

	//All elements of b should be less than k
	for (int i = 0; i < m; i++) {
		if (b[i] > k) {
			ans += (b[i] - k);
		}
	}

	return ans;
}

void solve() {
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int s = 1 , e = 1e9;
	while (s < e) {
		int m1 = s + (e - s) / 3;
		int m2 = e - (e - s) / 3;

		if (func(m1) < func(m2)) {
			e = m2 - 1;
		} else {
			s = m1 + 1;
		}
	}

	cout << func((s + e) / 2) << endl;

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
