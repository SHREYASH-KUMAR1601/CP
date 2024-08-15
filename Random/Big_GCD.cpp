#include <bits/stdc++.h>
using namespace std;
const int N = 0;
// const long long MOD = 100;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
int fastModExpo(int a, int b, int MOD) {

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

int Big_GCD(string &m , string &n) {

	int res = 0;
	int len = m.length();
	int n_new = stoll(n);
	for (int i = 0; i < len; ++i) {
		res += (m[i] - '0') % n_new * (fastModExpo(10, len - i - 1, n_new)) % n_new;
	}

	return __gcd(res, n_new);
}

int32_t main() {
	IOS;

	string m, n;
	cin >> m >> n;

	cout << Big_GCD(m, n) << endl;


}