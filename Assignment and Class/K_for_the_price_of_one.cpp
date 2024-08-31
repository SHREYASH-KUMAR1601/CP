/*
*    Author: ShreyashxDON
*    Created: Saturday, 31.08.2024 07:46 PM (GMT+5:30)

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
	int n, p, k;
	cin >> n >> p >> k;

	int cost[n];
	int dp[200005];

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	sort(cost + 1, cost + n + 1);

	for (int i = 1; i <= n; i++) {
		if (i < k) {
			dp[i] = dp[i - 1] + cost[i];
		} else if (i == k) {
			dp[i] = cost[i];
		} else {
			dp[i] = dp[i - k] + cost[i];
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (dp[i] <= p) {
			ans = i;
		}
	}

	cout << ans << endl;

}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}