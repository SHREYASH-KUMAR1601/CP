#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// int solve(string a, string b) {
// 	int n = a.length();
// 	int m = b.length();

// 	int ans = n + m;

// 	//For each i in b , find the length of continuous substring of a .
// 	for (int i = 0; i < m; ++i)		//i iterates over b
// 	{
// 		int j = i;
// 		for (auto c : a) {
// 			if (j < m and c == b[j]) {
// 				j++;
// 			}
// 		}

// 		ans = min(ans, m + n - (j - i));
// 	}
// 	return ans;
// }

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {

		string a, b;
		cin >> a >> b;
		int ans = 0;
		for (int i = 0; i < b.size(); i++) {	//Finding maximum length of subsequence b inside a
			int curr = 0;
			for (int j = 0; j < a.size(); j++) {
				if (a[j] == b[i + curr]) {
					curr++;
				}
			}
			ans = max(ans, curr);
		}
		cout << a.size() + b.size() - ans << endl;
	}

	return 0;
}
