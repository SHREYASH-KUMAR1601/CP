#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int operations = 0;
        int i = 0;

        while (i < a.size() - 1) { // Ensure at least two elements remain
            if (a[i] == i + 1) {
                operations++;       // Increment operation count
                a.erase(a.begin() + i);  // Remove both a[i] and a[i+1]
                a.erase(a.begin() + i);  // Note: i remains unchanged
            } else {
                i++;  // Move to the next element if the condition isn't met
            }
        }

        cout << operations << '\n';
    }
    return 0;
}
