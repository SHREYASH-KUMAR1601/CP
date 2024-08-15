#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, m, k;

int a[N] = {0}, l[N] = {0}, r[N] = {0}, d[N] = {0}, opcount[N] = {0}, diff[N] = {0};

int32_t main() {

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> d[i];
	}

	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		opcount[x]++;
		opcount[y + 1]--;
	}

	// Prefix sum of opcount array
	for (int i = 1; i <= m; i++) {
		opcount[i] += opcount[i - 1];
	}

	// Apply operations to diff array
	for (int i = 1; i <= m; i++) {
		diff[l[i]] += d[i] * opcount[i];
		diff[r[i] + 1] -= d[i] * opcount[i];
	}

	// Prefix sum of diff array
	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}

	// Apply diff to array a
	for (int i = 1; i <= n; i++) {
		a[i] += diff[i];
		cout << a[i] << " ";
	}

	return 0;
}
