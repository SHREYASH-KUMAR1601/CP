#include <iostream>
#include <vector>

using namespace std;

void readPermutation(vector<long long>& perm, long long n) {
	for (long long i = 1; i <= n; ++i) {
		cin >> perm[i];
	}
}

bool canBobWin(const vector<long long>& a, const vector<long long>& b, const vector<long long>& c, long long n) {
	bool isBobWin = true;

	for (long long i = 1; i <= n; ++i) {
		if (b[i] != a[i]) {
			isBobWin = false;
			break;
		}
	}

	if (!isBobWin) {
		isBobWin = true;
		for (long long i = 1; i <= n; ++i) {
			if (b[i] != c[i]) {
				isBobWin = false;
				break;
			}
		}
	}

	return isBobWin;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		vector<long long> a(n + 1), b(n + 1), c(n + 1);

		readPermutation(a, n);
		for (long long i = 1; i <= n; ++i) {
			c[n - i + 1] = a[i];
		}

		readPermutation(b, n);

		if (canBobWin(a, b, c, n)) {
			cout << "Bob\n";
		} else {
			cout << "Alice\n";
		}
	}

	return 0;
}
