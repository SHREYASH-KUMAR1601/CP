#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int k;
	cin >> k;

	string s;
	cin >> s;

	unordered_map<char, int>mp;
	for (int i = 0; i < s.length() ; i++) {
		mp[s[i]]++;
	}

	for (auto x : mp) {
		if (x.second > k) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

}