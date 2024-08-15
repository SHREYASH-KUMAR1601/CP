#include <bits/stdc++.h>
using namespace std;
const int N = 40001;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int a, b, q;
		cin >> a >> b >> q;

		vector<int>pre(a * b + 1, 0);
		vector<int>flag(a * b + 1, 0);
		for (int i = 0; i < a * b; ++i) {
			if ((i % a) % b != (i % b) % a) {
				flag[i] = 1;
			}

			if (i == 0) {
				pre[i] = flag[i];
			} else {
				pre[i] = pre[i - 1] + flag[i];
			}

		}
		int count1 = 0; //count for upto [0,l-1]
		int count2 = 0; //count for upto [0,r]

		while (q--) {
			int l, r;
			cin >> l >> r;

			l--;

			int m = l / (a * b);
			int n = l % (a * b);
			count1 = (m * pre[(a * b - 1)]) + pre[n];

			int m1 = r / (a * b);
			int n1 = r % (a * b);
			count2 = (m1 * pre[(a * b - 1)]) + pre[n1];


			cout << count2 - count1 << " ";
		}
		cout << endl;
	}

}