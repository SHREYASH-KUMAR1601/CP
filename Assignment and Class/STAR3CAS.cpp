#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int min_steps = INT_MAX;
vector<int>vis;
vector<int>a;

int n;
void minimimum_steps(int i, int count) {

	if (i == n) {
		min_steps = min(min_steps, count);
		return;
	}

	vis[i] = 1;

	if (i + 1 <= n and vis[i + 1] == 0) {
		minimimum_steps(i + 1, count + 1);
	}

	if (i + a[i] <= n and i + a[i] >= 0 and vis[i + a[i]] == 0) {
		minimimum_steps(i + a[i], count + 1);
	}


	vis[i] = 0;

}

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {

		cin >> n;
		a.resize(n);
		vis.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			vis[i] = 0;
		}
		minimimum_steps(0, 0);
		cout << min_steps << endl;
	}

}