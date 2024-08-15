/*
*    Author: ShreyashxDON
*    Created: Saturday, 10.08.2024 11:56 AM (GMT+5:30)
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

	int n, r, avg;
	cin >> n >> r >> avg;

	int totalPoint = avg * n;
	vector<pair<int, int>> ba(n + 1);
	int point = 0;
	for (int i = 1; i <= n; i++) {
		cin >> ba[i].second >> ba[i].first;
		point += ba[i].second;
	}

	int pointReq = totalPoint - point;


	sort(ba.begin(), ba.end());
	int essay = 0;
	for (int i = 1; i <= n; i++) {
		if (pointReq <= 0) {
			break;
		} else {

			int poss = min(pointReq, (r - ba[i].second));
			// cout << poss << endl;
			essay += (ba[i].first) * poss;

			pointReq -= poss;

		}
	}

	cout << essay << endl;

	return 0;
}