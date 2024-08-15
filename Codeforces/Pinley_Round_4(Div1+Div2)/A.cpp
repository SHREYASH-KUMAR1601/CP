#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxValue(vector<int>& a) {
	int n = a.size();

	int mx = INT_MIN;
	for (int i = 0; i < n; i = i + 2)
	{
		mx = max(mx, a[i]);
	}

	return mx;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		if (n == 1) {
			cout << a[0] << endl;
			continue;
		}

		cout << getMaxValue(a) << endl;
	}
	return 0;
}
