#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;


int main() {

	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int ans = 0;
		if (b > a) {
			ans += 1;
		}
		if (c > a) {
			ans += 1;
		}
		if (d > a) {
			ans += 1;
		}

		cout << ans << endl;
	}
}

