#include <iostream>
#include <vector>
#include <set>
using namespace std;

int countValidSubsegments(int n, int x, const vector<int>& a) {
    // Prefix sum array
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    // Multisets to track minimum and maximum prefix sums
    multiset<long long> suff_min, suff_max;
    suff_min.insert(0);
    suff_max.insert(0);

    long long count = 0;
    int j = n;

    for (int i = n; i >= 1; --i) {
        // Update suffix multisets
        suff_min.insert(prefix[i]);
        suff_max.insert(prefix[i]);

        // Adjust j to find the maximum valid r for current l = i
        while (j >= i && *suff_max.rbegin() - *suff_min.begin() > x) {
            suff_min.erase(suff_min.find(prefix[j]));
            suff_max.erase(suff_max.find(prefix[j]));
            --j;
        }

        // Count valid subsegments ending at i
        count += (j - i + 1);
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long result = countValidSubsegments(n, x, a);
        cout << result << "\n";
    }

    return 0;
}
