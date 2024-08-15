#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int sum = 0;
        int maxWin = 0;
        int start = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += a[i];

            while (sum > r and start <= i) {
                sum -= a[start];
                start++;
            }

            if (sum >= l and sum <= r) {
                maxWin++;
                sum = 0;
                start = i + 1;
            }
        }

        cout << maxWin << endl;
    }

    return 0;
}