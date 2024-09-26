#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
const ll MOD = 998244353;

vector<int> a;
int n, k;
ll countWays;
vector<vector<ll>> dp1, dp2;
const int OFFSET = 10000; // To handle negative sums

// Function to find the maximum value that can be achieved
ll Max_Val(int i, int c) {
	if (i > n) {
		return dp1[i][c + OFFSET] = c % MOD;  // Apply MOD here
	}

	if (dp1[i][c + OFFSET] != -1) {
		return dp1[i][c + OFFSET];
	}

	ll op1 = Max_Val(i + 1, (c + a[i]) % MOD);  // Apply MOD to the sum
	ll op2 = Max_Val(i + 1, abs((c + a[i]) % MOD));  // Apply MOD to abs value

	return dp1[i][c + OFFSET] = max(op1, op2) % MOD;  // Apply MOD to the result
}

// Function to count the number of ways to achieve target value using dp2 memoization
ll Solve(int i, int current_sum, int target) {
	if (i > n) {
		return (current_sum == target) ? 1 : 0;
	}

	if (dp2[i][current_sum + OFFSET] != -1) {
		return dp2[i][current_sum + OFFSET];
	}

	// Option 1: Add a[i] to the current sum
	ll op1 = Solve(i + 1, (current_sum + a[i]) % MOD, target) % MOD;

	// Option 2: Add abs(a[i]) to the current sum
	ll op2 = Solve(i + 1, abs((current_sum + a[i]) % MOD), target) % MOD;

	return dp2[i][current_sum + OFFSET] = (op1 + op2) % MOD;  // Apply MOD to the sum of both options
}

int main() {
	IOS;

	int t;
	cin >> t;  // Read the number of test cases

	while (t--) {
		cin >> n;
		a.resize(n + 1);

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		// Initialize dp tables for each test case
		dp1.assign(n + 2, vector<ll>(2 * OFFSET + 1, -1));
		dp2.assign(n + 2, vector<ll>(2 * OFFSET + 1, -1));

		// Reset the count of ways for each test case
		countWays = 0;

		// Maximum value K
		k = Max_Val(1, 0);

		// Count the ways to achieve this maximum value using Solve with DP
		countWays = Solve(1, 0, k);

		// Output the result for the current test case
		cout << countWays % MOD << endl;  // Apply MOD when outputting the result
	}

	return 0;
}
