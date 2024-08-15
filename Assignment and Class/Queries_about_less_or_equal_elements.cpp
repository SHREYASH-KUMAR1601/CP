#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int n , m;
	cin >> n >> m;

	vector<int> a(n);
	vector<int> b(m);

	for (int &x : a) {
		cin >> x;
	}
	sort(a.begin() , a.end());
	for (int &x : b) {
		cin >> x;

		int s = 0 , e = n - 1 , ans = n;

		while (s <= e) {
			int mid = s + (e - s) / 2;
			if (a[mid] > x) {
				ans = mid;
				e = mid - 1;
			} else {
				s = mid + 1;
			}
		}

		cout << ans << " ";
	}

	return 0;
}
