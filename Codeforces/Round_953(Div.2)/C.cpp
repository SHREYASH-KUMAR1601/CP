#include <bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		int maxk = 0;
		for (int i = 1; i <= n / 2; ++i) {
			maxk += 2 * (n - i + 1 - i);
		}

		if (k % 2 == 1 || k > maxk) {
			cout << "NO" << endl;
			continue;
		} else {
			cout << "YES" << endl;

			vector<int> perm(n + 1);
			for (int i = 1; i <= n; ++i) {
				perm[i] = i;
			}

			for (int i = 1; k > 0; i++) {
				if (k >= 2 * (n - i + 1 - i)) {
					swap(perm[i], perm[n + 1 - i]);
					k -= 2 * (n - i + 1 - i);
				} else {
					swap(perm[i], perm[(k / 2) + i]);
					k = 0;
				}
			}

			for (int i = 1; i <= n; ++i) {
				cout << perm[i] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
