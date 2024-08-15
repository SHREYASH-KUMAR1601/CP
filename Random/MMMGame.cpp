// 	Misere version of nim game   // All piles are of size 1 ---> Exceptional case   else  nim game result

#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(vector<int>& s, int n) {
	int nim_sum = 0;
	bool all_ones = true;
	for (int i = 0; i < n; ++i) {
		nim_sum ^= s[i];
		if (s[i] != 1) {
			all_ones = false;
		}
	}

	if (all_ones) {
		if (n % 2 == 0) {
			cout << "John" << endl;
		} else {
			cout << "Brother" << endl;
		}
	} else {
		if (nim_sum == 0) {
			cout << "Brother" << endl;
		} else {
			cout << "John" << endl;
		}
	}
}

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> s(n);
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}

		solve(s, n);
	}
	return 0;
}
