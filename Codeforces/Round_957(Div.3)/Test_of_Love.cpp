// #include <bits/stdc++.h>
// using namespace std;

// const int N = 0;

// #define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// int n, m, k;
// string a;

// bool solve(int i, int swam) {
// 	if (i == n) {
// 		return true;
// 	}
// 	if (i > n) {
// 		return false;
// 	}

// 	bool op1 = false, op2 = false;

// 	if (i < n && a[i] == 'L') {
// 		if (i + m <= n) {
// 			op1 = solve(i + m, swam);
// 		}
// 	}

// 	if (i < n && a[i] == 'W') {
// 		if (swam + 1 <= k) {
// 			op2 = solve(i + 1, swam + 1);
// 		}
// 	}

// 	// Check the current position
// 	if (i < n && a[i] == 'C') {
// 		return false;
// 	}

// 	return op1 || op2;
// }

// int main() {
// 	IOS;

// 	int t;
// 	cin >> t;
// 	while (t--) {
// 		cin >> n >> m >> k;
// 		cin >> a;

// 		if (n < m) {
// 			cout << "YES" << endl;
// 			continue;
// 		}

// 		a += 'L';

// 		if (solve(0, 0)) {
// 			cout << "YES" << endl;
// 		} else {
// 			cout << "NO" << endl;
// 		}
// 	}

// 	return 0;
// }
