#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
vector<int> num;

void solve(int ind, string st) {
	if (ind == num.size()) {
		cout << st << endl;
		return;
	}

	for (int j = 0; j < table[num[ind]].length(); ++j) {
		solve(ind + 1, st + table[num[ind]][j]);
	}
}

int main() {
	IOS;
	int n;
	cin >> n;
	while (n != 0) {
		num.push_back(n % 10);
		n = n / 10;
	}
	reverse(num.begin(), num.end());
	solve(0, "");
	return 0;
}
