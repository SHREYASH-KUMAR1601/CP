#include <bits/stdc++.h>
#include "Trees.h"
using namespace std;

const int N = 0;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void Solve(node<int>* root, map<int, multiset<int>>& mp, int column) {
	if (root == NULL) {
		return;
	}

	mp[column].insert(root->data);

	Solve(root->left, mp, column - 1);
	Solve(root->right, mp, column + 1);
}

vector<int> VerticalViewDFS(node<int>* root) {
	vector<int> ans;
	if (root == NULL) {
		return ans;
	}

	//map<column,<value,level>>
	map<int, multiset<int>> mp;

	Solve(root, mp, 0);

	for (auto x : mp) {
		for (auto y : x.second) {
			ans.push_back(y);
		}
	}

	return ans;
}


int main() {
	IOS;

	node<int>* root = Buildtree();

	vector<int> ansDFS = VerticalViewDFS(root);


	cout << "DFS vertical View: ";
	for (auto x : ansDFS) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
