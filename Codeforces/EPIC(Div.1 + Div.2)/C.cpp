#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;

#define IOS ios_base::sync_with_stdio(0)
int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n ;
		vector<int>heights(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> heights[i];
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, heights[i] + i);

		}

		cout << ans << endl;

	}

}