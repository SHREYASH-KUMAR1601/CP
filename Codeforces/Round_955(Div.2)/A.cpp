#include <bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define IOS ios_base::sync_with_stdio(0)

void solve() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 > y1) {
		if (x2 > y2) {
			cout << "YES" << endl;
			return;
		} else {
			cout << "NO" << endl;
			return;
		}
	} else {
		if (x2 > y2) {
			cout << "NO" << endl;
			return;
		} else {
			cout << "YES" << endl;
			return;
		}
	}
	return;
}

int32_t main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}
