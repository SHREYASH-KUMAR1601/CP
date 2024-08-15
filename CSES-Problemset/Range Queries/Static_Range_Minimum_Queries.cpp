#include <bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
	IOS;

	int n , q;
	cin >> n >> q;

	vector<int>x(n);
	for (int i = 1; i <= n; i++) {	//1-based indexing
		cin >> x[i];
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		int ans = INT_MAX;
		for (int i = a; i <= b; ++i) {
			ans = min(ans, x[i]);
		}
		cout << ans << endl;
	}

}