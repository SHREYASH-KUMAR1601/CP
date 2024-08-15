#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define int long long

int32_t main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;

		int dg = x % 10;
		if (dg > 8) {
			cout << "NO" << endl;
			continue;
		}
		x = x / 10;
		bool flag = false;
		while (x / 10 != 0) {
			dg = x % 10;
			if (dg == 0) {
				cout << "NO" << endl;
				flag = true;
				break;
			}
			x = x / 10;
		}

		if (flag) {
			continue;
		}

		dg = x % 10;
		if (dg != 1) {
			cout << "NO" << endl;
			continue;
		} else {
			cout << "YES" << endl;
		}
	}

}