#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<vector<int>> pos = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
	IOS;

	int n, m;
	char c;
	cin >> n >> m >> c;

	vector<vector<char>> grid(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}

	set<char> uniqueColors;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == c) {
				for (int k = 0; k < 4; ++k) {
					int i_new = i + pos[k][0];
					int j_new = j + pos[k][1];

					if (i_new >= 0 && i_new < n && j_new >= 0 && j_new < m && grid[i_new][j_new] != c && grid[i_new][j_new] != '.') {
						uniqueColors.insert(grid[i_new][j_new]);
					}
				}
			}
		}
	}


	cout << uniqueColors.size() << endl;
	return 0;
}
