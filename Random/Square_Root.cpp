#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

float square_root(int n, int p) {

	int s = 0;
	int e = n;
	float ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (mid * mid == n) {
			return mid;
		}
		else if (mid * mid < n) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}


	float inc = 0.1;
	for (int i = 1; i <= p; ++i) {

		while (ans * ans <= n) {
			ans += inc;
		}
		ans = ans - inc;
		inc = inc / 10;
	}

	return ans;
}
int main() {
	IOS;

	int n;
	cin >> n;

	cout << square_root(n, 5) << endl;

}