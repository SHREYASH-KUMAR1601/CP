#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<char> vowel = {'A', 'E', 'I', 'O', 'U', 'Y'};

bool isVowel(char c) {
	c = toupper(c);
	return find(vowel.begin(), vowel.end(), c) != vowel.end();
}

int main() {
	IOS;

	string s;
	cin >> s;

	string result;
	for (char c : s) {
		if (!isVowel(c)) {
			result += '.';
			result += tolower(c);
		}
	}

	cout << result << endl;

	return 0;
}
