#include <iostream>
#include <vector>

using namespace std;

// Function to count pairs (i, j) such that pi * pj is divisible by i * j
int countDivisiblePairs(int n, vector<int>& p) {
	int count = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if ((p[i - 1] * p[j - 1]) % (i * j) == 0) {
				count++;
			}
		}
	}

	return count;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
		}

		int result = countDivisiblePairs(n, p);
		cout << result << endl;
	}

	return 0;
}
