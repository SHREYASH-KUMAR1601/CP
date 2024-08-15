#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	vector<int> giver(n + 1);
	for (int i = 1; i <= n; ++i) {
		giver[p[i]] = i;
	}

	for (int i = 1; i <= n; ++i) {
		cout << giver[i] << " ";
	}
	cout << endl;

	return 0;
}
