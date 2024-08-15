#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	int n, h;
	cin >> n >> h;

	vector<int>height(n, 0);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> height[i];
		if (height[i] > h) {
			ans = ans + 2;
		} else {
			ans = ans + 1;
		}
	}

	cout << ans << endl;

}