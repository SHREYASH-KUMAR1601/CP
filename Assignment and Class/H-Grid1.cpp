/*
*    Author: ShreyashxDON
*    Created: Sunday, 18.08.2024 12:44 PM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1e9 + 7;

// Use sqrtl() instead of sqrt() for long long
char grid[1005][1005];
int h, w;

// int Find_Paths() {
// 	int dp[1005][1005] {{0}};

// 	dp[1][1] = 1;
// 	for (int i = 1; i <= h; i++) {
// 		for (int j = 1; j <= w; j++) {

// 			if (i == 1 and j == 1) {
// 				continue;
// 			}

// 			if (grid[i][j] == '#') {
// 				dp[i][j] = 0;
// 			} else {
// 				if (j == 1) {
// 					dp[i][j] = dp[i - 1][j] % MOD;
// 				} else if (i == 1) {
// 					dp[i][j] = dp[i][j - 1] % MOD;
// 				} else {
// 					dp[i][j] = (dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD;
// 				}
// 			}
// 		}
// 	}

// 	return dp[h][w];
// }

int Find_Paths1() {
	int dp[1005][1005] {{0}};

	dp[h][w] = 1;
	for (int i = h; i >= 1; i--) {
		for (int j = w; j >= 1; j--) {

			if (i == h and j == w) {
				continue;
			}

			if (grid[i][j] == '#') {
				dp[i][j] = 0;
			} else {
				if (j == w) {
					dp[i][j] = dp[i + 1][j] % MOD;
				} else if (i == h) {
					dp[i][j] = dp[i][j + 1] % MOD;
				} else {
					dp[i][j] = (dp[i + 1][j] % MOD + dp[i][j + 1] % MOD) % MOD;
				}
			}
		}
	}

	return dp[1][1] % MOD;
}

void solve() {
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> grid[i][j];
		}
	}

	cout << Find_Paths1() << endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}