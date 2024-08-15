#include <bits/stdc++.h>
using namespace std;
const int N = 0;
const long long MOD = 100;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
int fastModExpo(int a, int b) {

	int res = 1;

	while (b > 0) {

		if (b & 1) {
			res = (res * a) % MOD;
		}

		b = b >> 1;
		a = (a * a) % MOD;
	}

	return res % MOD;
}
int32_t main() {
	IOS;

	int a, b;
	cin >> a >> b;

	cout << fastModExpo(a, b) << endl;

}