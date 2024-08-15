#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;

		string s;
		cin >> s;

		int cnt = 0;
		for (char c : s) {
			if (c == 'U') cnt++;
		}

		if (cnt % 2 == 0) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}

}