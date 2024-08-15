#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;

#define IOS ios_base::sync_with_stdio(0)
int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n ;
		vector<int>a(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		long long ans = 0;
		int diff = 0;

		for (int i = 1; i < n; ++i)
		{
			if (a[i] < a[i - 1]) {
				ans = ans + (a[i - 1] - a[i]);
				diff = max(diff, a[i - 1] - a[i]);
				a[i] = a[i - 1];
			}
		}


		cout << ans + diff << endl;

	}

}