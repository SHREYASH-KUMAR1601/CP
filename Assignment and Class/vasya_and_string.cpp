#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int max_length = 1;
	int left = 0;
	int countA = 0, countB = 0;
	int changes = 0;

	for (int right = 0; right < n; ++right) {
		if (s[right] == 'a') {
			countA++;
		} else {
			countB++;
		}

		// Calculate number of changes needed to make all in the window same as s[right]
		changes = (right - left + 1) - max(countA, countB);

		// If changes exceed k, move left pointer
		while (changes > k) {
			if (s[left] == 'a') {
				countA--;
			} else {
				countB--;
			}
			left++;

			// Recalculate changes
			changes = (right - left + 1) - max(countA, countB);
		}

		// Update max_length
		max_length = max(max_length, right - left + 1);
	}

	cout << max_length << endl;

	return 0;
}
