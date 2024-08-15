#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

	int t;
	cin >> t;

	while (t--) {
		int n , a , b;
		cin >> n >> a >> b;

		if (b < a) {
			cout << n*a << endl;
		} else {
			int x = min(n, b - a);
			int y = n - x;
			int c = b - x;
			int ans = y * a + (b * (b + 1) / 2) - (c * (c + 1) / 2);
			cout << ans << endl;
		}

	}
}