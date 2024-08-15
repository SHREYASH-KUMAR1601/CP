#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int>points(n, 0);
	int max_point = INT_MIN;
	int min_point = INT_MAX;
	int amazing = 0;
	for (int i = 0; i < n; ++i) {
		cin >> points[i];
		if (i != 0 and (points[i] > max_point or points[i] < min_point)) {
			amazing++;
		}
		max_point = max(max_point, points[i]);
		min_point = min(min_point, points[i]);
	}

	cout << amazing << endl;


	return 0;
}