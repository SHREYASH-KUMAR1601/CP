/*
*    Author: ShreyashxDON
*    Created: Wednesday, 18.09.2024 09:42 AM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int N = 110;
const int MOD = 1e9 + 7;

// Use sqrtl() instead of sqrt() for long long

int w[N], v[N];

void solve() {
	int n, wt;
	cin >> n >> wt;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(wt + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= wt; j++) {
			if (w[i] <= j) {
				dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][wt] << endl;
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
