/*
*    Author: ShreyashxDON
*    Created: Saturday, 28.09.2024 10:04 AM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int N = 0;
const int MOD = 1e9 + 7;


void solve() {
	int n;
	cin >> n;

	vector<int>a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int m1 = 0, n1 = 0, m2 = 0, n2 = 0;

	for (int i = 0; i < n; i += 2) {
		n1++;
		m1 = max(m1, a[i]);
	}

	for (int i = 1; i < n; i += 2) {
		n2++;
		m2 = max(m2, a[i]);
	}

	cout << max(m1 + n1 , m2 + n2) << endl;
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