/*
*    Author: ShreyashxDON
*    Created: Wednesday, 21.08.2024 08:00 PM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

// Use sqrtl() instead of sqrt() for long long

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;

	int ax = 0 , ay = 0;
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') ax++;
		else if (s[i] == 'L') ax--;
		else if (s[i] == 'U') ay++;
		else ay--;

		if (abs(ax - x) + abs(ay - y) == i + 1) {	//Bob can reach directly to alice position at any point of time
			check = true;
		}
	}

	int d = abs(ax - x) + abs(ay - y);
	if (d == n || check) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
