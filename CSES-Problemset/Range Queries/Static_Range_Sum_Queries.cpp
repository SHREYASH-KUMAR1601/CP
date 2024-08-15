#include <bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
	IOS;

	int n , q;
	cin >> n >> q;

	vector<int>x(n) , pre(n + 1, 0);
	for (int i = 1; i <= n; i++) {	//1-based indexing
		cin >> x[i];
	}

	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + x[i];
	}
	while (q--) {
		int a, b;
		cin >> a >> b;

		cout << pre[b] - pre[a - 1] << endl;
	}

}