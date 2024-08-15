#include <bits/stdc++.h>
using namespace std;

const int N = 8;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int getX(string s) {
	return (s[0] - 'a');
}

int getY(string s) {
	return (s[1] - '1');
}

vector<pair<int, int>> movements = {
	{2, -1}, {2, 1},
	{ -2, 1}, { -2, -1},
	{ -1, 2}, {1, 2},
	{ -1, -2}, {1, -2}
};

bool isValid(int x, int y) {
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int level[N][N];
bool vis[N][N];

int bfs(string src, string dest) {
	int srcX = getX(src);
	int srcY = getY(src);
	int destX = getX(dest);
	int destY = getY(dest);

	queue<pair<int, int>> q;
	q.push({srcX, srcY});
	vis[srcX][srcY] = true;
	level[srcX][srcY] = 0;

	while (!q.empty()) {
		pair<int, int> curr_v = q.front();
		q.pop();

		for (auto m : movements) {
			int x_new = curr_v.first + m.first;
			int y_new = curr_v.second + m.second;

			if (!isValid(x_new, y_new)) continue;
			if (vis[x_new][y_new]) continue;

			q.push({x_new, y_new});
			level[x_new][y_new] = level[curr_v.first][curr_v.second] + 1;
			vis[x_new][y_new] = true;

			if (x_new == destX && y_new == destY) {
				return level[x_new][y_new];
			}
		}
	}

	return -1;
}

void reset() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			level[i][j] = 0;
			vis[i][j] = false;
		}
	}
}

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		string s, d;
		cin >> s >> d;

		cout << bfs(s, d) << endl;
		reset();
	}
}
