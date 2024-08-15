#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int>a(k);
		int m = -1;
		for (int i = 0; i < k; ++i) {
			cin >> a[i];
			m = max(m, a[i]);
		}

		cout << 2 * (n - m) - k + 1 << endl;
	}

}