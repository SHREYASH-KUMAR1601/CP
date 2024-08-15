#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// vector<vector<int>>edge(v + 1, vector<int>(v + 1));
// vector<vector<int>>cost(v + 1, vector<int>(v + 1));
// vector<pair<int, int>>graph[N];
vector<int>graph[N];	//vector<vector<int>>
// bool vis[N];
// void dfs(int v) {

// 	cout << v << endl;
// 	vis[v] = true;

// 	for (auto x : graph[v]) {
// 		if (vis[x]) continue;

// 		dfs(x);
// 	}

// }

//DFS for trees to find height and depth
// int height[N];
// int depth[N];
// int evenSub[N];
// int SubSum[N];
// void dfs(int v, int par = 0) {

// 	// cout << v << endl;
// 	SubSum[v] += v;
// 	if (v % 2 == 0) {
// 		evenSub[v] = 1;
// 	}
// 	for (auto child : graph[v]) {
// 		if (child == par) continue;

// 		depth[child] = depth[v] + 1;
// 		dfs(child, v);
// 		height[v] = max(height[v], height[child] + 1);
// 		SubSum[v] += SubSum[child];
// 		evenSub[v] += evenSub[child] ;

// 	}

// }
// int parent[N];

// void dfs(int v, int p = -1) {

// 	parent[v] = p;

// 	for (auto child : graph[v]) {
// 		if (child == p) continue;
// 		dfs(child, v);
// 	}

// }

// vector<int>Path(int v) {
// 	vector<int>ans;

// 	while (v != -1) {
// 		ans.push_back(v);
// 		v = parent[v];
// 	}
// 	reverse(ans.begin(), ans.end());

// 	return ans;
// }

// class Solution {
//     void dfs(int i, int j, vector<vector<int>>& image, int iniColor, int finalColor, int n, int m) {
//         if (i < 0 || i >= n || j < 0 || j >= m) return;
//         if (image[i][j] != iniColor) return;

//         image[i][j] = finalColor;

//         dfs(i, j + 1, image, iniColor, finalColor, n, m);
//         dfs(i, j - 1, image, iniColor, finalColor, n, m);
//         dfs(i + 1, j, image, iniColor, finalColor, n, m);
//         dfs(i - 1, j, image, iniColor, finalColor, n, m);
//     }

// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int iniColor = image[sr][sc];
//         if (iniColor == color) return image;
//         int n = image.size();
//         int m = image[0].size();
//         dfs(sr, sc, image, iniColor, color, n, m);
//         return image;
//     }
// };


// class Solution {
// 	void dfs(int i, int j, vector<vector<char>>& grid, int n, int m, vector<vector<bool>>& vis) {
// 		if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1' || vis[i][j]) {
// 			return;
// 		}

// 		vis[i][j] = true;

// 		dfs(i + 1, j, grid, n, m, vis); // down
// 		dfs(i - 1, j, grid, n, m, vis); // up
// 		dfs(i, j + 1, grid, n, m, vis); // right
// 		dfs(i, j - 1, grid, n, m, vis); // left
// 	}

// public:
// 	int numIslands(vector<vector<char>>& grid) {
// 		int n = grid.size();
// 		int m = grid[0].size();
// 		int co = 0;

// 		vector<vector<bool>> vis(n, vector<bool>(m, false));

// 		for (int i = 0; i < n; ++i) {
// 			for (int j = 0; j < m; ++j) {
// 				if (!vis[i][j] && grid[i][j] == '1') {
// 					dfs(i, j, grid, n, m, vis);
// 					co++;
// 				}
// 			}
// 		}
// 		return co;
// 	}
// };


int main() {
	IOS;

	int v;
	cin >> v;

	for (int i = 0; i < v - 1; ++i) {
		int v1, v2 ;
		cin >> v1 >> v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);

		// graph[v1].push_back({v2, w});
		// graph[v2].push_back({v1, w});
		// edge[v1][v2] = 1;
		// edge[v2][v1] = 1;
		// cost[v1][v2] = w;
		// cost[v2][v1] = w;
	}


	dfs(1);

	// for (int i = 1; i <= v; ++i)
	// {
	// 	cout << SubSum[i] << " " << evenSub[i] << endl;
	// }

// 	int max_depth = -1;
// 	int max_depth_node ;


// //CALCULATION OF DIAMETER OF A TREE
// 	for (int i = 1; i <= v; ++i) {
// 		if (max_depth < depth[i]) {
// 			max_depth = depth[i];
// 			max_depth_node = i;
// 		}

// 		depth[i] = 0;
// 	}

// 	dfs(max_depth_node);

// 	max_depth = -1;
// 	for (int i = 1; i <= v; ++i) {
// 		if (max_depth < depth[i]) {
// 			max_depth = depth[i];
// 		}

// 	}

// 	cout << max_depth << endl;


	//LOWEST COMMMON ANCESTOR

	// int x, y;
	// cin >> x >> y;

	// vector<int>Path1 = Path(x);
	// vector<int>Path2 = Path(y);

	// int LCA = -1;

	// for (int i = 0; i < min(Path1.size(), Path2.size()); ++i) {
	// 	if (Path1[i] == Path2[i]) {
	// 		LCA = Path1[i];
	// 	} else {
	// 		break;
	// 	}
	// }

	// cout << LCA << endl;



}