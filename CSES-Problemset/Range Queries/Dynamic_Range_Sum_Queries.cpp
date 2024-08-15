#include <bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n , q;
vector<int>x(n), pre(n + 1);
void update(vector<int>&pre , int k , int u) {
	for (int i = k; i <= n; ++i) {
		pre[i] = pre[i] - x[k] + u;
	}
}

int32_t main() {
	IOS;


	cin >> n >> q;
	x.resize(n);
	pre.resize(n + 1);

	for (int i = 1; i <= n; i++) {	//1-based indexing
		cin >> x[i];
	}

	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + x[i];
	}

	while (q--) {
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 1) {
			update(pre, a, b);
		} else {
			cout << pre[b] - pre[a - 1] << endl;
		}
	}

}