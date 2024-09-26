#include <bits/stdc++.h>
#include "Hashmap.h"
using namespace std;

int main() {

	int n;
	cin >> n;

	Hashmap mp(3);
	while (n--) {
		string key;
		int val;

		cin >> key >> val;

		mp.Insert(key, val);
	}

	mp.Print();
}