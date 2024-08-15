#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int ans = n / 4;
		if (n % 4 != 0) {
			ans += 1;
		}

		cout << ans << endl;
	}

	return 0;
}
