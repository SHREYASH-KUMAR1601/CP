/*
*    Author: ShreyashxDON
*    Created: Wednesday, 07.08.2024 08:01 PM (GMT+5:30)
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
// 4. should pairity of x and y be equal?
// 5. Huffman Coding? Merging 2 smallest elements?
// 6. Coordinate Compression?
// 7. Min/Max Spanning Tree.
// 8. Topo sort ? if there is something related to relative ordering.
// 9. Try calculating it in reverse order?

void solve() {
	int a, b, c, m;
	cin >> a >> b >> c >> m;

	if (a == b || b == c || a == c) {
		cout << "YES" << endl;
		return;
	} else {
		if (abs(a - b) <= m || abs(b - c) <= m || abs(a - c) <= m) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}