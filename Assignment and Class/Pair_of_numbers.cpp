#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int solve(int x, int y, int steps) {
	if (x == 1 && y == 1) {
		return steps;
	}

	if (x > y) {
		return solve(x - y, y, steps + 1);
	} else if (y > x) {
		return solve(x, y - x, steps + 1);
	}

	return INT_MAX;
}

int pair_of_numbers(int n) {

	if (n == 1) {
		return 0;
	}

	int min_steps = INT_MAX;

	for (int i = 1; i <= n / 2; ++i) {
		int steps = solve(i, n - i, 1);
		min_steps = min(min_steps, steps);
	}

	return min_steps;
}

int main() {
	IOS;

	int n;
	cin >> n;

	cout << pair_of_numbers(n) << endl;

	return 0;
}
