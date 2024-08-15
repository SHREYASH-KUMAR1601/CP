#include<bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {

	int n , m;
	cin >> n >> m;
	int ans = 0;
	if (m >= n) {
		cout << n << endl;
		return 0 ;
	}

	//Define the Search space
	int s = 0 ;
	int e = 1e10;	//1*10^10
	while (s <= e) {
		int mid = (s + e ) / 2;
		int value = (mid) * (mid + 1) / 2 ;
		if (value >= n - m) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	//Final ans : m+k
	cout << m + ans << endl;

}