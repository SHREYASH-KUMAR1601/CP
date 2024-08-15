#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int maxPages = INT_MIN;
		int last = a[n - 1];
		for (int i = 0; i < n - 1; ++i)
		{
			maxPages = max(maxPages, a[i]);
		}

		cout << maxPages + last << endl;
	}

	return 0;
}
