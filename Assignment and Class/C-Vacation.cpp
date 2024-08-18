/*
*    Author: ShreyashxDON
*    Created: Sunday, 18.08.2024 01:28 PM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥

*/
#include <bits/stdc++.h>
using namespace std;

// #define int long long int
#define double long double
#define endl '\n'
const int N = 1e5 + 10;
const int MOD = 1000000007;


int a[N], b[N], c[N];
int n;

/*

	dp[i][ch] : Maximum happiness till ith day by performing ch activity on ith day

*/

int Max_Happiness() {

	int dp[N][3];

	dp[1][0] = a[1];
	dp[1][1] = b[1];
	dp[1][2] = c[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = a[i] + max(dp[i - 1][1] , dp[i - 1][2]);
		dp[i][1] = b[i] + max(dp[i - 1][2] , dp[i - 1][0]);
		dp[i][2] = c[i] + max(dp[i - 1][1] , dp[i - 1][0]);
	}

	return max({dp[n][0], dp[n][1], dp[n][2]});
}

void solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	cout << Max_Happiness() << endl;
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