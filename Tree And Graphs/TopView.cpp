#include <bits/stdc++.h>
#include "Trees.h"
using namespace std;

const int N = 0;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void Solve(node<int>* root, map<int, pair<int, int>>& mp, int column, int level) {
	if (root == NULL) {
		return;
	}

	if (mp.count(column) == 0 || mp[column].second > level) {
		mp[column] = make_pair(root->data, level);
	}

	Solve(root->left, mp, column - 1, level + 1);
	Solve(root->right, mp, column + 1, level + 1);
}

vector<int> TopViewDFS(node<int>* root) {
	vector<int> ans;
	if (root == NULL) {
		return ans;
	}

	//map<column,<value,level>>
	map<int, pair<int, int>> mp;

	Solve(root, mp, 0, 0);

	for (auto x : mp) {
		ans.push_back(x.second.first);
	}

	return ans;
}

vector<int> TopViewBFS(node<int>* root) {
	vector<int> result;
	if (root == NULL) return result;

	map<int, int> topNode;

	queue<pair<node<int>*, int>> q;
	q.push({root, 0});

	while (!q.empty()) {
		pair<node<int>*, int> current = q.front();
		q.pop();

		node<int>* currentNode = current.first;
		int col = current.second;

		if (topNode.find(col) == topNode.end()) {
			topNode[col] = currentNode->data;
		}

		if (currentNode->left) {
			q.push({currentNode->left, col - 1});
		}

		if (currentNode->right) {
			q.push({currentNode->right, col + 1});
		}
	}

	for (auto it : topNode) {
		result.push_back(it.second);
	}

	return result;
}

int main() {
	IOS;

	node<int>* root = Buildtree();

	vector<int> ansDFS = TopViewDFS(root);

	vector<int> ansBFS = TopViewBFS(root);

	cout << "BFS Top View: ";
	for (auto x : ansBFS) {
		cout << x << " ";
	}
	cout << endl;

	cout << "DFS Top View: ";
	for (auto x : ansDFS) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
