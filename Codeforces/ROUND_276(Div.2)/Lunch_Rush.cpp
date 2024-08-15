#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	int n;
	cin >> n;

	int k;
	cin >> k;

	int f[n];
	int t[n];

	for (int i = 0; i < n ; i++) {
		cin >> f[i] >> t[i];
	}

	int maxJoy = INT_MIN;

	for (int i = 0; i < n; ++i)
	{
		if (t[i] > k) {
			maxJoy = max(maxJoy, (f[i] - t[i] + k));
		} else {
			maxJoy = max(maxJoy, f[i]);
		}
	}

	cout << maxJoy << endl;
}