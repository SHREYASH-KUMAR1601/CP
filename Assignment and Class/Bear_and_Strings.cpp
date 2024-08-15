#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	string s;
	cin >> s;
	int n = s.length();
	int ans = 0;
	int prev = 0;

	for (int i = 0; i <= n - 4; ++i) {
		if (s.substr(i, 4) == "bear") {
			ans += (i - prev + 1) * (n - (i + 3));
			prev = i + 1;
		}
	}

	cout << ans << endl;
	return 0;
}
