#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<string> grid(n);

		for (int i = 0; i < n; ++i) {
			cin >> grid[i];
		}

		int newRC = n / k;
		vector<string> reducedGrid(newRC);

		for (int i = 0; i < newRC; ++i) {
			string row = "";
			for (int j = 0; j < newRC; ++j) {
				row += grid[i * k][j * k];
			}
			reducedGrid[i] = row;
		}

		for (int i = 0; i < newRC; ++i) {
			cout << reducedGrid[i] << endl;
		}
	}

	return 0;
}
