#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		// int ans = sum(n, k) - sum(1, m);

		// int ans =  ((n + k) * (n - k + 1) - m * (m + 1)) / 2;  max value of f(n) - g(n);

		for (int i = 0; i <= n - k; i++) {
			cout << n - i << " ";
		}

		for (int i = m + 1; i <= k - 1; ++i)
		{
			cout << i << " ";
		}

		for (int i = 1; i <= m; ++i) {
			cout << i << " ";
		}

		cout << endl;
	}

}