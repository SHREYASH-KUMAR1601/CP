/*
*    Author: ShreyashxDON
*    Created: Sunday, 11.08.2024 05:48 PM (GMT+5:30)
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int N = 1e5 + 7;
const int MOD = 1000000007;

vector<int>dp;
vector<int>pre(N);
int k;
int solve(int n) {

	if (n == 0) {
		return dp[n] = 1;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int op1 = solve(n - 1);
	int op2 = 0;
	if (n - k >= 0) {
		op2 = solve(n - k);
	}

	return dp[n] = (op1 + op2) % MOD;
}

void Precompute() {
	dp.resize(N, -1);

	pre[0] = 0;

	for (int i = 1; i <= N; i++) {
		pre[i] = pre[i - 1] + solve(i);
		pre[i] %= MOD;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t >> k;
	Precompute();
	while (t--) {
		int a, b;
		cin >> a >> b;
		// solve(n, k);
		cout << (pre[b] - pre[a - 1] + MOD) % MOD << endl;
	}

	return 0;
}