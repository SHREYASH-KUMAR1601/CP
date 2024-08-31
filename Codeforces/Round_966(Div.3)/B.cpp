/*
*    Author: ShreyashxDON
*    Created: Thursday, 22.08.2024 04:39 PM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

// Use sqrtl() instead of sqrt() for long long


void solve() {
	int n;
	cin >> n;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	set<int>available;

	for (int i = 1; i <= n; i++) {

		if (i == 1) {
			available.insert((a[i] - 1 + n)) % n;
			available.insert((a[i] + 1)) % n;
		} else {
			if (available.find(a[i]) != available.end) {
				available.remove(a[i]);
				available.insert((a[i] - 1 + n)) % n;
				available.insert((a[i] + 1)) % n;
			} else {
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;
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