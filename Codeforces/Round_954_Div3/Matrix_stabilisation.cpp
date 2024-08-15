#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
vector<vector<int>> diff = {{0, -1}, { -1, 0}, {1, 0}, {0, 1}};

int getMaximumNeighbor(const vector<vector<int>>& matrix, int row, int col, int n, int m) {
	int currentValue = matrix[row][col];
	int maxNeighbor = INT_MIN;

	bool strictlyGreater = true;

	for (const auto& d : diff) {
		int newRow = row + d[0];
		int newCol = col + d[1];

		if (newRow >= 1 && newRow <= n && newCol >= 1 && newCol <= m) {
			if (!(currentValue > matrix[newRow][newCol])) {
				strictlyGreater = false;
				break;
			}
			if (matrix[newRow][newCol] > maxNeighbor) {
				maxNeighbor = matrix[newRow][newCol];
			}
		}
	}

	if (strictlyGreater) {
		return maxNeighbor;
	} else {
		return -1;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n , m;
		cin >> n >> m;

		vector<vector<int>>mat(n + 1, vector<int>(m + 1));

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> mat[i][j];
			}
		}

		//Stabilization of matrix
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				int max_ne = getMaximumNeighbor(mat, i, j, n, m);
				if (max_ne != -1) {
					mat[i][j] = max_ne;
				}
			}

		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}

	}

	return 0;
}
