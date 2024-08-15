#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		vector<int>num(3);
		cin >> num[0] >> num[1] >> num[2];

		for (int i = 0; i < 5; ++i) {
			sort(num.begin(), num.end());
			num[0] += 1;
		}

		long long int banana = num[0] * num[1] * num[2];
		cout << banana << endl;
	}

}