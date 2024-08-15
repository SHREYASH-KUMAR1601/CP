#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void process(int t, vector<vector<vector<int>>>& cases) {
	for (int test = 0; test < t; ++test) {
		int n = cases[test][0][0];
		int m = cases[test][0][1];
		vector<vector<int>> a = cases[test];
		a.erase(a.begin());

		if (n == 1 && m == 1) {
			cout << -1 << endl;
			continue;
		}

		vector<vector<int>> b = a;

		if (n > 1) {
			rotate(b.begin(), b.begin() + 1, b.end());
		}

		for (int i = 0; i < n; ++i) {
			rotate(b[i].begin(), b[i].begin() + 1, b[i].end());
		}

		for (const auto& row : b) {
			for (const auto& elem : row) {
				cout << elem << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	int t;
	cin >> t;
	vector<vector<vector<int>>> cases(t);

	for (int test = 0; test < t; ++test) {
		int n, m;
		cin >> n >> m;
		cases[test].push_back({n, m});

		for (int i = 0; i < n; ++i) {
			vector<int> row(m);
			for (int j = 0; j < m; ++j) {
				cin >> row[j];
			}
			cases[test].push_back(row);
		}
	}

	process(t, cases);

	return 0;
}
