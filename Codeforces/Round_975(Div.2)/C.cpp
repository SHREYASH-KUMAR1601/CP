/*
*    Author: ShreyashxDON
*    Created: Saturday, 28.09.2024 10:53 AM (GMT+5:30)

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
	int n, k;
	cin >> n >> k;

	vector<int>a(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int max_el = *max_element(a.begin(), a.end());
	int sum = accumulate(a.begin(), a.end(), 0LL);	//Minimum possible cards

	int m = n;	//Maximum size of group
	int c = sum + k;	//Maximum possible cards

	while (m > 1) {
		int temp1 = c / m;	//No. of decks formed
		if (m * temp1 >= sum and temp1 >= max_el) {	//Check if minimum cards can be accomodated and no. of decks is greater than maximum element
			cout << m << endl;
			return;
		}
		m--;
	}

	cout << "1" << endl;
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