#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {

		int n, d;
		cin >> n >> d;

		vector<int>a(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int ans = 0;

		bool shorte = true;
		for (int i = 0; i < n; ++i) {
			if (a[i] > d and shorte == true) {
				ans++;
				shorte = false;
			} else if (a[i] <= d and shorte != true) {
				ans++;
				shorte = true;
			}
		}

		cout << ans << endl;

	}

}