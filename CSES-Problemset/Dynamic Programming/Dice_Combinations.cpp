/*
*    Author: ShreyashxDON
*    Created: Saturday, 14.09.2024 12:03 PM (GMT+5:30)

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


// int solve(int n) {

// 	if (n < 0) {
// 		return 0;
// 	}

// 	if (n == 0) {
// 		return 1;
// 	}

// 	int op1 = solve(n - 1);
// 	int op2 = solve(n - 2);
// 	int op3 = solve(n - 3);
// 	int op4 = solve(n - 4);
// 	int op5 = solve(n - 5);
// 	int op6 = solve(n - 6);

// 	return  (op1 + op2 + op3 + op4 + op5 + op6);
// }


// int solve(int n, vector<int>& dp) {
// 	if (n < 0) {
// 		return 0;
// 	}

// 	if (n == 0) {
// 		return 1;
// 	}

// 	if (dp[n] != -1) {
// 		return dp[n];
// 	}

// 	int op1 = solve(n - 1, dp);
// 	int op2 = solve(n - 2, dp);
// 	int op3 = solve(n - 3, dp);
// 	int op4 = solve(n - 4, dp);
// 	int op5 = solve(n - 5, dp);
// 	int op6 = solve(n - 6, dp);

// 	return dp[n] = (op1 + op2 + op3 + op4 + op5 + op6) % MOD;
// }

int solve(int n) {
	vector<int> dp(n + 1, 0);

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) {
				dp[i] = dp[i] + dp[i - j] % MOD;
			}
		}
	}

	return dp[n] % MOD;
}



signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		int n;
		cin >> n;
		// vector<int>dp(n + 1, -1);
		cout << solve(n);
	}

	return 0;
}