#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

void solve() {
	int n; cin >> n;
	vector<int> arr(n); for (int i = 0; i < n; ++i) cin >> arr[i];
	ll sum = 0, mn = 0;
	for (int i = 0; i < n; ++i) sum += arr[i], mn = min(mn, sum);
	cout << sum - 2 * mn << '\n';
}

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}