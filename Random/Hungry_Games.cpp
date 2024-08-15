#include <iostream>
#include <vector>
using namespace std;

long long countValidSubsegments(int l, int r, long long current_sum, long long x, const vector<long long>& a) {
	if (r == a.size()) return 0;

	current_sum += a[r];
	if (current_sum > x) current_sum = 0;

	long long count = (current_sum != 0) ? 1 : 0;

	count += countValidSubsegments(l, r + 1, current_sum, x, a);

	return count;
}

long long countAllSubsegments(int n, long long x, const vector<long long>& a) {
	long long totalCount = 0;

	for (int l = 0; l < n; l++) {
		totalCount += countValidSubsegments(l, l, 0, x, a);
	}

	return totalCount;
}

void solve() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		long long x;
		cin >> n >> x;

		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		cout << countAllSubsegments(n, x, a) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
