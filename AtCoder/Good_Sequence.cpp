#include <bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int32_t main() {
	IOS;

	int n;
	cin >> n;

	vector<int>a(n, 0);
	unordered_map<int, int>mp;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mp[a[i]]++;
	}

	int ans = 0;
	for (auto x : mp) {
		if (x.first > x.second) {
			ans += x.second;
		} else if (x.first < x.second) {
			ans += (x.second - x.first);
		}
	}

	cout << ans << endl;

}