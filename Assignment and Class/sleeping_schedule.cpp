#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, h, l, r;
vector<int> a;

vector<vector<int>> dp;

int solveDP(int i, int WH) {
	if (i == n) {
		return 0;
	}

	if (dp[i][WH] != -1) {
		return dp[i][WH];
	}

	int Sleep1 = (WH + a[i]) % h;
	int Sleep2 = (WH + a[i] - 1) % h;

	int ans1 = (Sleep1 >= l && Sleep1 <= r);
	int ans2 = (Sleep2 >= l && Sleep2 <= r);

	int op1 = ans1 + solveDP(i + 1, Sleep1);
	int op2 = ans2 + solveDP(i + 1, Sleep2);

	dp[i][WH] = max(op1, op2);
	return dp[i][WH];
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> h >> l >> r;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	dp.assign(n + 1, vector<int>(h, -1));

	int goodSleeps = solveDP(0, 0);
	cout << goodSleeps << endl;

	return 0;
}
