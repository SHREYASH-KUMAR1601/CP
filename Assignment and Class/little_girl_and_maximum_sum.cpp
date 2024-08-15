#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;

int arr[N] = {0};
int posCount[N] = {0};
int l[N] = {0};
int r[N] = {0};

int32_t main() {
	int n;
	cin >> n;

	int q;
	cin >> q;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);

	for (int i = 1; i <= q; ++i) {
		cin >> l[i] >> r[i];
		posCount[l[i]]++;
		posCount[r[i] + 1]--;
	}

	for (int i = 1; i <= n; ++i) {
		posCount[i] += posCount[i - 1];
	}

	sort(posCount + 1 , posCount + n + 1);

	int maxSum = 0;
	for (int i = 1; i <= n; i++) {
		maxSum += (posCount[i] * arr[i]);
	}

	cout << maxSum << endl;
	return 0;
}
