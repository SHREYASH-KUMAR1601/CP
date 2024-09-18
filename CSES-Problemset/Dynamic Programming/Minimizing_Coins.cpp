#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, x;
vector<int> val;
vector<int> dp;

int solve(int v) {
	if (v == 0) {
		return 0;
	}

	if (dp[v] != -1) {
		return dp[v];
	}

	int ans = INT_MAX;

	for (int i = 1; i <= n; i++) {
		if (v - val[i] >= 0) {
			int subproblem = solve(v - val[i]);
			if (subproblem != INT_MAX) {
				ans = min(ans, 1 + subproblem);
			}
		}
	}

	dp[v] = (ans == INT_MAX) ? INT_MAX : ans;
	return dp[v];
}

const int INF = 1e9;

int minCoins(int n) {
	vector<int> dp(n + 1, INF);
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int coin : val) {
			if (i - coin >= 0) {
				dp[i] = min(dp[i], dp[i - coin] + 1);
			}
		}
	}

	return dp[n] == INF ? -1 : dp[n];
}


int main() {
	cin >> n >> x;
	val.resize(n + 1);
	// dp.resize(x + 1, -1);

	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}

	// int result = solve(x);
	int result = minCoins(x);

	if (result == INT_MAX) {
		cout << -1 << endl;
	} else {
		cout << result << endl;
	}

	return 0;
}
