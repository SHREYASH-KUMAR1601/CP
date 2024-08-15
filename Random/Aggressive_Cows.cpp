#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool canPlaceCows(vector<int>&stalls, int n, int c, int min_sep) {

	int lastPlaced = stalls[0];
	int cnt = 1;
	for (int i = 1; i < n; ++i)
	{
		if (stalls[i] - lastPlaced >= min_sep) {
			lastPlaced = stalls[i];
			cnt++;
			if (cnt == c) {
				return true;
			}
		}
	}

	return false;
}
int min_distance(vector<int>&stalls, int n, int c) {
	int s = 0;
	int e = stalls[n - 1] - stalls[0];
	int ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2;
		//Check if cows can be placed at 'mid' distance
		if (canPlaceCows(stalls, n, c, mid)) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}

	return ans;
}
int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n , c;
		cin >> n >> c;

		vector<int>stalls(n, 0);
		for (int i = 0; i < n; i++) cin >> stalls[i];
		sort(stalls.begin(), stalls.end());
		cout << min_distance(stalls, n, c) << endl;

	}

}