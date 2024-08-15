#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
int n;
vector<int>first;
vector<int>second;
bool isSequenceSame() {
	if (first.size() != second.size()) {
		return false;
	}

	for (size_t i = 0; i < first.size(); ++i) {
		if (first[i] != -second[i]) {
			return false;
		}
	}

	return true;
}

void winner() {
	for (int i = 0; i < min(first.size(), second.size()); ++i) {
		if (first[i] > -second[i]) {
			cout << "first" << endl;
			return;
		} else if (first[i] < -second[i]) {
			cout << "second" << endl;
			return;
		} else {
			continue;
		}
	}
}
int32_t main() {
	IOS;


	cin >> n;

	int f = 0, s = 0;
	int a;
	while (n--) {
		cin >> a;

		if (a < 0) {
			second.push_back(a);
			s += a;
		} else {
			first.push_back(a);
			f += a;
		}
	}
	if (f > -s) {
		cout << "first" << endl;
	} else if (-s > f) {
		cout << "second" << endl;
	} else {
		if (isSequenceSame()) {
			if (a < 0) {
				cout << "second" << endl;
			} else {
				cout << "first" << endl;
			}
		} else {
			winner();
		}
	}

}