#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int>ind(m, 0);
		for (int i = 0; i < m; ++i) {
			cin >> ind[i];
		}
		string c;
		cin >> c;

		sort(ind.begin(), ind.end());
		sort(c.begin(), c.end());
		int j = 0;
		for (int i = 0; i < m; ++i) {
			if (i > 0 and ind[i - 1] == ind[i]) {
				continue;
			} else {
				s[ind[i] - 1] = c[j];
				j++;
			}
		}

		cout << s << endl;
	}

	return 0;
}
