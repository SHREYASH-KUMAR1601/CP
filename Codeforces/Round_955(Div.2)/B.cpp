#include <bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define IOS ios_base::sync_with_stdio(0)

int solve(int x, int y, int k) {

	while (k > 0 and x != 1) {
		long long rem = y - x % y;

		if (rem > k) {
			return x + k;
		} else {
			x += rem;
			k -= rem;
		}
		while (x % y == 0) {
			x /= y;
		}
	}

	if (k > 0) {
		k = k % (y - 1);
		x += k;
		while (x % y == 0) {
			x /= y;
		}
	}
	return x;
}

int32_t main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int x, y, k;
		cin >> x >> y >> k;

		// for (int i = 0; i < k; ++i)
		// {
		// 	x++;
		// 	while (x % y == 0) {
		// 		x /= y;
		// 	}
		// }

		cout << solve(x, y, k) << endl;
	}

}
