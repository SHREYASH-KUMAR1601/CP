#include<bits/stdc++.h>
using namespace std;

int main() {

	int n , k;
	cin >> n >> k;

	vector<int>score(n);
	int ans = 0;
	for (int i = 0 ; i < n; i++) {
		cin >> score[i];
		if (score[i] > 0 and i <= k - 1) {
			ans++;
		} else {
			if (score[i] > 0 and score[i] >= score[k - 1]) {
				ans++;
			}
		}
	}

	cout << ans << endl;
}