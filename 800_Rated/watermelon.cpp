#include <bits/stdc++.h>
using namespace std;

int main() {

	int w;
	cin >> w;

	int s = 1 , e = w - 1;

	if (w % 2 != 0) {
		cout << "NO" << endl;
		return 0;
	}
	while (s <= e) {
		if (s % 2 == 0 and e % 2 == 0) {
			cout << "YES" << endl;
			return 0;
		}

		s++; e--;

	}

	cout << "NO" << endl;

}