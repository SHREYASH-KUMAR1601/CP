#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int s;
	cin >> s;

	int t;
	cin >> t;

	int p[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	int ans = 0;
	bool flag = false;
	if (s == t) {
		cout << 0 << endl;
		return 0;
	}
	if (s == p[s - 1]) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (s == t) {
			cout << ans << endl;
			return 0;
		} else {
			s = p[s - 1];
			ans += 1;
		}
	}

	if (!flag) {
		cout << -1 << endl;
	}


}