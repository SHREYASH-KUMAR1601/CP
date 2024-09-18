/*
*    Author: ShreyashxDON
*    Created: Wednesday, 18.09.2024 08:45 AM (GMT+5:30)

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

int solve() {
	int n;
	cin >> n;
	vector<int> h(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	vector<int> dp(n + 1, 0);

	dp[1] = 0;
	if (n >= 2) {
		dp[2] = abs(h[2] - h[1]);
	}

	for (int i = 3; i <= n; i++) {
		int op1 = abs(h[i] - h[i - 1]) + dp[i - 1];
		int op2 = abs(h[i] - h[i - 2]) + dp[i - 2];

		dp[i] = min(op1, op2);
	}

	return dp[n];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		cout << solve() << endl;
	}

	return 0;
}
