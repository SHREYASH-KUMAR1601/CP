#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(vector<int>&s , int n) {
	//Even no. of coins are ignored because they xor upto 0;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] % 2 != 0) {
			res = res ^ i;
		}
	}

	if (res == 0) {
		cout << "Hanks Wins" << endl;
	} else {
		cout << "Tom Wins" << endl;
	}
}
int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int>s(n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> s[i];

		solve(s, n);
	}

}