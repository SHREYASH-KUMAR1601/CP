#include <bits/stdc++.h>
using namespace std;
const int N = 10;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
int grid[N][N] = {0};
int total_box = 0;
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

void input_grid() {

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> grid[i][j];

			if (grid[i][j] == 1) {
				total_box++;
			}
		}
	}
}

int ans = -1;
void solve(int x, int y, int count) {

	ans = max(ans, count);

	for (int i = 0; i < 8; ++i)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (new_x >= 0 and new_x < N and y >= 0 and new_y < N and grid[new_x][new_y] == 1) {
			grid[new_x][new_y] = 0;
			solve(new_x, new_y, count + 1);//always use count+1 instead of count++

			grid[new_x][new_y] = 1; //bactracking
		}
	}
}

int main() {
	IOS;
	cin >> n;
	input_grid();
	grid[0][0] = 0;
	solve(0, 0, 1);

	cout << total_box - ans << endl;
}