/*
*    Author: ShreyashxDON
*    Created: Saturday, 31.08.2024 06:33 PM (GMT+5:30)

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
	int n, m;
	cin >> n >> m;

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	while (m--) {
		int x, y;
		cin >> x >> y;
		dp[x][y] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j] + dp[i][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j] + dp[i - 1][j];
		}
	}

	int global_ans = INT_MIN;	//Max of minimums

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int op1 = dp[i][j];
			int op2 = dp[i][n] - op1;
			int op3 = dp[n][j] - op1;
			int op4 = dp[n][n] - op1 - op2 - op3;

			int local_ans = min({op1, op2, op3, op4});

			global_ans = max(local_ans, global_ans);
		}
	}


	cout << global_ans << endl;
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