#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
int n;
int Noise(string s) {
	int countS = 0 , ans = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 's') {
			countS++;
		} else {
			ans += countS;
		}
	}

	return ans;
}

bool compare(string &a , string &b) {
	string ab = a + b;
	string ba = b + a;

	if (Noise(ab) > Noise(ba)) {
		return true;
	} else {
		return false;
	}
}
int32_t main() {
	IOS;

	cin >> n;

	vector<string>t(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	sort(t.begin(), t.end(), compare);

	string s = "";
	for (int i = 0; i < n; ++i) {
		s = s + t[i];
	}

	cout << Noise(s) << endl;
}