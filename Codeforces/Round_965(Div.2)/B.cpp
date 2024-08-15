#include <iostream>
#include <vector>

using namespace std;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        vector<int> q(n);
        for (int i = 0; i < n; ++i) {
            if (p[i] == n) {
                q[i] = 1;
            } else {
                q[i] = p[i] + 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << q[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}