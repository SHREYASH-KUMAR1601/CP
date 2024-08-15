#include <iostream>
using namespace std;
// #define int long long;

int main() {

	int k , n, w;
	cin >> k >> n >> w;

	int total_cost = 0;

	for (int i = 1; i <= w; ++i) {
		total_cost += k * i;
	}

	if (n < total_cost) {
		cout << (total_cost - n) << endl;
	} else {
		cout << 0 << endl;
	}
}
