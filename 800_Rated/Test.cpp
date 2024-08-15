#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int ans = 0;

	while (n--) {
		vector<int>a(3, 0);

		int count = 0;
		for (int i = 0; i < 3; ++i)
		{
			cin >> a[i];
			if (a[i] == 1) {
				count++;
			}
		}

		if (count >= 2) {
			ans++;
		}
	}

	cout << ans << endl;
}