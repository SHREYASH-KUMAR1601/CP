#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	int n;
	cin >> n;
	vector<string>grid(n);
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];

	}

	char ch = grid[0][0];
	char chi = grid[0][1];

	//If diagonal and other character is same , return no;
	if (ch == chi) {
		cout << "NO" << endl;
		return 0;
	}

	//Check if diagonals are same
	for (int i = 0; i < n; ++i) {
		if (grid[i][i] != ch || grid[i][n - i - 1] != ch) {
			cout << "NO" << endl;
			return 0;
		}
	}

	//Check if elements other than diagonal are same;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j and j != n - i - 1) {
				if (grid[i][j] != chi) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}

	cout << "YES" << endl;


}