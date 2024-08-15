#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;

int main() {

	int n;
	cin >> n;

	int k;
	cin >> k;
	int total_time = 240; //in minutes
	int rem_time = total_time - k;

	int ans = 0;
	int s = 0 , e = n ;

	while (s <= e) {
		int mid = (s + e) / 2;
		int time_needed = 5 * mid * (mid + 1) / 2;
		if (time_needed <= rem_time) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}

	cout << ans << endl;
	return 0;
}