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
		int n, c;
		cin >> n >> c;
		vector<int>a(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}

		if (n == 1) {
			cout << "0" << endl;
			continue;
		}

		int mx = INT_MIN;
		for (int i = 1; i <= n; ++i) {
			mx = max(mx, a[i]);
		}
		int mxc = max(mx, a[1] + c);
		int winner = (mxc == a[1] + c) ? 1 : find(a.begin() + 2, a.end(), mx) - a.begin();

		int sum = c;
		for (int i = 1; i <= n; ++i) {
			int ans;
			if (i == winner) {
				ans = 0;
			} else if (sum + a[i] >= mx) {
				ans = i - 1;
			} else if (sum + a[i] < mx) {
				ans = i;
			}

			cout << ans << " ";
			sum += a[i];
		}

		cout << endl;
	}

}