#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	unordered_map<char, int> freq;
	for (char c : s) {
		freq[c]++;
	}

	int odd_count = 0;
	for (auto p : freq) {
		if (p.second % 2 != 0) {
			odd_count++;
		}
	}

	if (odd_count == 0 || odd_count % 2 == 1) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
	return 0;
}
