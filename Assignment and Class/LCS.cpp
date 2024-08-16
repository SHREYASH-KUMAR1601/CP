#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<vector<int>> dp;
string s, t;

string getLCS(int i, int j, int LCS) {
	string ans = "";

	while (LCS > 0) {
		if (s[i] == t[j]) {
			ans.push_back(s[i]);
			i++;
			j++;
			LCS--;
		} else {
			if (dp[i + 1][j] > dp[i][j + 1]) {
				i++;
			} else {
				j++;
			}
		}
	}

	return ans;
}

int lengthLCS(const string &s, const string &t, int i, int j) {
	if (i == s.length() || j == t.length()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s[i] == t[j]) {
		return dp[i][j] = 1 + lengthLCS(s, t, i + 1, j + 1);
	}

	return dp[i][j] = max(lengthLCS(s, t, i + 1, j), lengthLCS(s, t, i, j + 1));
}

void Solve() {
	int n = s.length(), m = t.length();
	dp.assign(n + 1, vector<int>(m + 1, -1));

	cout << getLCS(0, 0, lengthLCS(s, t, 0, 0)) << endl;
}

int main() {
	IOS;

	cin >> s >> t;

	Solve();

	return 0;
}
