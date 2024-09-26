#include <bits/stdc++.h>
using namespace std;

class node {
public:
	string key;
	int val;

	node*next;

	node(string s, int v) {
		key = s;
		val = v;
		next = NULL;
	}
};

