#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int>graph[N];

int level[N];
int vis[N];

void bfs(int v) {
	queue<int>q;
	q.push(v);
	vis[v] = 1;
	while (!q.empty()) {
		int curr_v = q.front();
		cout << curr_v << " ";
		q.pop();
		for (auto child : graph[curr_v]) {
			if (!vis[child]) {
				q.push(child);
				vis[child] = 1;
				level[child] = level[curr_v] + 1;
			}
		}

	}
}

int main() {
	IOS;

	int v;
	cin >> v;

	for (int i = 0; i < v - 1; ++i) {
		int v1, v2 ;
		cin >> v1 >> v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);

	}

	bfs(1);
	cout << endl;	//For undirected graph of edge weight 1, bfs level gives shortest path between src and vertex
	for (int i = 1; i <= v; ++i) {
		cout << i << ":" << level[i] << endl;
	}
}