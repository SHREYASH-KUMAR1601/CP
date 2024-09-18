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
	int n, k;
	cin >> n >> k;
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
		int local_ans = LLONG_MAX;
		for (int j = 1; j <= k and i - j >= 1; j++) {
			local_ans = min({local_ans, dp[i - j] + abs(h[i] - h[i - j])});
		}
		dp[i] = local_ans;
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
