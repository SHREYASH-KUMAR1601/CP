#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int max_length_subsequence(const string &s, const string &t, int i, int j) {

	if (i == s.length() or j == t.length()) {
		return 0;
	}

	if (s[i] == t[j]) {
		return 1 + max_length_subsequence(s, t, i + 1, j + 1);
	}

	return max(max_length_subsequence(s, t, i + 1, j) , max_length_subsequence(s, t, i, j + 1));
}

int main() {
	IOS;

	string s, t;
	cin >> s >> t;

	cout << max_length_subsequence(s, t, 0, 0) << endl;

}