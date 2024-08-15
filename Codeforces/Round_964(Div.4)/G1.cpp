#include <bits/stdc++.h>
using namespace std;

#define int long long

int pw(int a, int b, int mod) {
    int result = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        b = b / 2;
        a = (a * a) % mod;
    }
    return result;
}

void solve() {
    int l = 2, r = 999;
    while (l <= r) {
        int mid = (l + r) / 2;
        cout << "? " << (mid - 1) << " " << mid << endl;
        cout.flush();

        int a;
        cin >> a;

        if (a == (mid - 1) * (mid + 1)) {
            cout << "! " << mid << endl;
            return;
        }
        if (a == mid * (mid - 1)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}