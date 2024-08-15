#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;

#define IOS ios_base::sync_with_stdio(0)
int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		int ans = 1;

		if (n == 1) {
			cout << 1 << endl;
			continue;
		}

		for (int i = 1; i < n; ++i)
		{

			ans = ans + k;

		}
		cout << ans << endl;

	}

}