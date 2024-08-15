/*
*    Author: ShreyashxDON
*    Created: Saturday, 10.08.2024 11:31 AM (GMT+5:30)
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int>cost(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	vector<int>pre(n + 2, 0);
	vector<int>sortedPre(n + 2, 0);

	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + cost[i];
	}

	sort(cost.begin(), cost.end());

	for (int i = 1; i <= n; i++) {
		sortedPre[i] = sortedPre[i - 1] + cost[i];
	}

	int m;
	cin >> m;
	while (m--) {
		int type, l, r;
		cin >> type >> l >> r;

		if (type == 1) {
			cout << pre[r] - pre[l - 1] << endl;
		} else {
			cout << sortedPre[r] - sortedPre[l - 1] << endl;
		}
	}

	return 0;
}