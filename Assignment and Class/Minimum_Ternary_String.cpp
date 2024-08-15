#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	IOS;

	string s;
	cin >> s;

	string ans;
	int co = 0;

	for (char c : s) {
		if (c == '1') co++;
		else ans += c;
	}


	size_t pos = ans.find('2');
	if (pos != string::npos) {
		ans.insert(pos, string(co, '1'));
	} else {
		// If there is no '2', append '1's at the end
		ans += string(co, '1');
	}

	cout << ans << endl;

	return 0;
}
