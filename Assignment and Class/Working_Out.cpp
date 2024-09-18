/*
*    Author: ShreyashxDON
*    Created: Saturday, 07.09.2024 10:26 AM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'
const int N = 101;
const int MOD = 1000000007;

// Use sqrtl() instead of sqrt() for long long

int dp1[N][N];	//(1,1) -> (x,y)
int dp2[N][N];	//(n,m) -> (x,y)
int dp3[N][N];	//(n,1) -> (x,y)
int dp4[N][N];	//(1,m) -> (x,y)

int n, m;
void solve() {
	cin >> n >> m;
	vector<vector<int>>mat(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}

	//DP1

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 and j == 1) {
				dp1[i][j] = mat[i][j];
			} else if (i == 1) {
				dp1[i][j] = dp1[i][j - 1] + mat[i][j];
			} else if (j == 1) {
				dp1[i][j] = dp1[i - 1][j] + mat[i][j];
			} else {
				dp1[i][j] = max(dp1[i][j - 1], dp1[i - 1][j]) + mat[i][j];
			}
		}
	}

	//DP2
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			if (i == n and j == m) {
				dp2[i][j] = mat[i][j];
			} else if (i == n) {
				dp2[i][j] = dp2[i][j + 1] + mat[i][j];
			} else if (j == m) {
				dp2[i][j] = dp2[i + 1][j] + mat[i][j];
			} else {
				dp2[i][j] = max(dp2[i][j + 1], dp2[i + 1][j]) + mat[i][j];
			}
		}
	}

	//DP3
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			if (i == n and j == 1) {
				dp3[i][j] = mat[i][j];
			} else if (i == n) {
				dp3[i][j] = dp3[i][j - 1] + mat[i][j];
			} else if (j == 1) {
				dp3[i][j] = dp3[i + 1][j] + mat[i][j];
			} else {
				dp3[i][j] = max(dp3[i][j - 1], dp3[i + 1][j]) + mat[i][j];
			}
		}
	}

	//DP4
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (i == 1 and j == m) {
				dp4[i][j] = mat[i][j];
			} else if (i == 1) {
				dp4[i][j] = dp4[i][j + 1] + mat[i][j];
			} else if (j == m) {
				dp4[i][j] = dp4[i - 1][j] + mat[i][j];
			}
			dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + mat[i][j];
		}
	}

	int ans = INT_MIN;

	for (int i = 2; i <= n - 1; i++) {
		for (int j = 2; j <= m - 1; j++) {
			int op1 = dp1[i][j - 1] + dp3[i + 1][j] + dp2[i][j + 1] + dp4[i - 1][j];
			int op2 = dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1];

			ans = max(ans, max(op1, op2));
		}
	}


	cout << ans << endl;

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