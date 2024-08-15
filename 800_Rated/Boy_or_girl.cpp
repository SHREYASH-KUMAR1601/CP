#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;

int main() {

	string s;
	cin >> s;

	unordered_map<char, int>mp;
	for (int i = 0; i < s.length(); ++i)
	{
		mp[s[i]]++;
	}
	int count = 0;
	for (auto x : mp)
	{
		count++;
	}
	if (count % 2 == 0) {
		cout << "CHAT WITH HER!" << endl;
	} else {
		cout << "IGNORE HIM!" << endl;
	}


	return 0;
}