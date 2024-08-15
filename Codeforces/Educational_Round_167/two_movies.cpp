#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0)

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int>a(n);
		vector<int>b(n);

		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		int x = 0, y = 0, pos = 0 , neg = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > b[i]) x += a[i];
			else if (b[i] > a[i]) y += b[i];
			else {
				neg += (a[i] < 0);
				pos += (b[i] > 0);
			}
		}
		int ans = INT_MIN;
		for (int i = -neg; i <= pos; ++i) {
			ans = max(ans, min(x + i, y + pos - neg - i));
		}

		cout << ans << endl;
	}

}