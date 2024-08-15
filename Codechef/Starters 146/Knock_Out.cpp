/*
*    Author: ShreyashxDON
*    Created: Thursday, 08.08.2024 11:17 AM (GMT+5:30)
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
// 8. Topo sort ? if there is something related to relative ordering.
// 9. Try calculating it in reverse order?

void solve() {
	vector<int> skills(17);
	for (int i = 1; i <= 16; i++) {
		cin >> skills[i];
	}

	vector<int> sorted_skills = skills;
	sort(sorted_skills.begin(), sorted_skills.end());

	for (int i = 1; i <= 16; i++) {
		int rank = lower_bound(sorted_skills.begin(), sorted_skills.end(), skills[i]) - sorted_skills.begin();
		// cout << rank << " ";
		if (rank == 1) {
			cout << "0" << " ";
		} else if (rank == 16) {
			cout << "4" << " ";
		} else if (rank >= 8) {
			cout << "3" << " ";
		} else if (rank >= 4) {
			cout << "2" << " ";
		} else if (rank > 1) {
			cout << "1" << " ";
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
