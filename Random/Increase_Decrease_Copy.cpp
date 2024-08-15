#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using li = long long;

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<li> a(n), b(n + 1);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n + 1; ++i) {
			cin >> b[i];
		}

		li sum = 0, ext = 1e18;
		for (int i = 0; i < n; ++i) {
			sum += abs(a[i] - b[i]);
			ext = min(ext, abs(a[i] - b[n]));
			ext = min(ext, abs(b[i] - b[n]));
			if (min(a[i], b[i]) <= b[n] && b[n] <= max(a[i], b[i]))
				ext = 0;
		}

		cout << sum + ext + 1 << '\n';
	}

	return 0;
}
