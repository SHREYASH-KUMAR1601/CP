#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>a(n, 0);

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		if (a[0] == a[n - 1]) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			string s(n, 'R');
			s[1] = 'B';
			cout << s << endl;

		}
	}

}