#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 100000;	//Minimum value of sum
int n, k;
vector<int> a, b;


vector<vector<int>> dp(100, vector<int>(2 * N));

int solveDP(int i, int sum) {
	if (i == n) {
		return sum == 0 ? 0 : -1e12;
	}

	if (dp[i][sum + N] != -1) {
		return dp[i][sum + N];//Shifted sum to avoid negative value in dp;
	}

	int op1 = a[i] + solveDP(i + 1, sum + (a[i] - k * b[i]));
	int op2 = solveDP(i + 1, sum);

	dp[i][sum + N] = max(op1, op2);
	return dp[i][sum + N];
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	a.resize(n); b.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	dp.assign(n + 1, vector<int>(200001, -1));

	int taste = solveDP(0, 0);
	if (taste <= 0) {
		cout << -1 << endl;
	} else {
		cout << taste << endl;
	}
}
