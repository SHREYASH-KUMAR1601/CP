/*
*    Author: ShreyashxDON
*    Created: Monday, 19.08.2024 09:13 AM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	string s;
	cin >> s;

	vector<int> logs;

	// Collect positions of all logs
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'L') {
			logs.push_back(i);
		}
	}
	logs.push_back(n); // Add the position of the right bank

	int i = -1;       // Starting position (before the first segment)
	int next_log = 0; // Index for logs in the logs vector

	while (i < n - 1) {
		// Check if we can jump directly to the next log or to the bank
		if (m >= logs[next_log] - i) {
			i = logs[next_log];
		} else {
			// Move forward by jumping up to `m` meters
			i += m;
			if (i > n - 1) { // If we can reach the bank
				cout << "YES" << endl;
				return;
			}
			// Swim or encounter crocodile
			while (i < n && i < logs[next_log]) {
				if (s[i] != 'C' && k > 0) {
					++i;
					--k;
				} else {
					cout << "NO" << endl;
					return;
				}
			}
		}
		next_log++;
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