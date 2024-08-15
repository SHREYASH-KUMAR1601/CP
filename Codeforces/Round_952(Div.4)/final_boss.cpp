#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;

// Custom Defines (consider organizing alphabetically for clarity)

#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORI(i, n) for (int i = 1; i <= n; ++i)
#define IOS ios_base::sync_with_stdio(0)

const int N = 2e5 + 10;
int a[N] = {0} , c[N] = {0};
// Main function
int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int h , n;
		cin >> h >> n;
		long long int sum = 0;
		FORI(i, n) {
			cin >> a[i];
			sum += a[i];
		}
		FORI(i, n) cin >> c[i];
		long long int s = 1, e = 1e11;
		long long int ans = -1;

		if (h <= sum) {
			cout << 1 << endl;
			continue;
		}
		while (s <= e) {
			long long int mid = (s + e) / 2;

			long long int damage = 0;
			FORI(i, n) {
				damage += ((mid + c[i] - 1) / c[i]) * a[i] ;
			}
			if (damage >= h) {
				e = mid - 1;
				ans = mid;
			} else {
				s = mid + 1;
			}
		}

		cout << ans << endl;
	}
	return 0;
}