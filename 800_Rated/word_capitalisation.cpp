#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;

int main() {

	string s;
	cin >> s;
	if (s[0] - 'a' >= 0) {
		s[0] = s[0] - 32;
	}
	for (int i = 0; i < s.length(); ++i) {
		cout << s[i];
	}


	return 0;
}