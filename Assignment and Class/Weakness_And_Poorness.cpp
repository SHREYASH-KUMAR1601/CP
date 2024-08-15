/*
*    Author: ShreyashxDON
*    Created: Monday, 12.08.2024 12:06 PM (GMT+5:30)
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

// Common Mistakes:
// 1. Use sqrtl() instead of sqrt() for long long
// 2. if a[i] goes to 10^9, you only need to check for primes till sqrt(10^9) i.e. 31623
// 3. GCD of |x-y|?
// 4. should parity of x and y be equal?
// 5. Huffman Coding? Merging 2 smallest elements?
// 6. Coordinate Compression?
// 7. Min/Max Spanning Tree.
// 8. Topo sort? if there is something related to relative ordering.
// 9. Try calculating it in reverse order?

int n;
vector<int> a;

double func(double x) {
	double max1 = 0, max2 = 0, sum = 0;

	for (int i = 0; i < n; i++) {
		sum += (a[i] - x);
		if (sum < 0) {
			sum = 0;
		}
		max1 = max(max1, sum);
	}

	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (x - a[i]);
		if (sum < 0) {
			sum = 0;
		}
		max2 = max(max2, sum);
	}

	return max(max1, max2);
}

void solve() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	double s = -10000;
	double e = 10000;
	// double ans = 0;

	while (e - s >= 1e-12) {	//Increase precision for more accurate answer
		double m1 = s + (e - s) / 3;
		double m2 = e - (e - s) / 3;

		double fm1 = func(m1);
		double fm2 = func(m2);

		if (fm1 < fm2) {
			e = m2;
		} else {
			s = m1;
		}
	}


	cout << fixed << setprecision(6) << func(s) << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
