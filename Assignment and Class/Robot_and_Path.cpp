/*
*    Author: ShreyashxDON
*    Created: Sunday, 18.08.2024 10:28 AM (GMT+5:30)

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

int grid[1005][1005] {{0}};	//Reduce size of grid to run the code
int n, m, p;

int Find_Paths1(int i, int j) {
	int dp[1005][1005] {{0}};	//F(x,y) = no. of ways to reach (x,y) from (1,1)

	if (grid[1][1] == -1 or grid[m][n] == -1) {
		return 0;
	}

	dp[1][1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 and j == 1) {
				continue;
			}
			if (grid[i][j] == -1) {
				dp[i][j] = 0;
			} else {
				if (j == 1) {
					dp[i][j] = dp[i - 1][j] % MOD;
				} else if (i == 1) {
					dp[i][j] = dp[i][j - 1] % MOD;
				} else {
					dp[i][j] = (dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD;
				}
			}
		}
	}

	return dp[m][n];
}


int dp[105][105];
int Find_Paths2(int x, int y) {
	// Base case: If the cell is out of bounds or blocked, return 0 paths
	if (x < 1 || y < 1 || grid[x][y] == -1) {
		return dp[x][y] = 0;
	}

	// If the value is already computed, return it
	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	// If we are at the starting cell (1, 1), there's only one way to reach here
	if (x == 1 && y == 1) {
		return dp[x][y] = 1;
	}

	// Recursively calculate the number of paths from the top or left cell
	return dp[x][y] = (Find_Paths2(x - 1, y) + Find_Paths2(x, y - 1)) % MOD;
}


void solve() {
	cin >> m >> n >> p;
	while (p--) {
		int x, y;
		cin >> x >> y;
		grid[x][y] = -1;
	}

	cout << Find_Paths1(m, n) << endl;
	memset(dp, -1, sizeof(dp));
	cout << Find_Paths2(m, n) << endl;


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