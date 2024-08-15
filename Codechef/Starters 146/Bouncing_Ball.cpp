/*
*    Author: ShreyashxDON
*    Created: Wednesday, 07.08.2024 08:33 PM (GMT+5:30)
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> heights(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
    }

    vector<int> pre(n + 1, 0);
    vector<int> suff(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + heights[i];
    }
    for (int i = n; i >= 1; --i) {
        suff[i] = suff[i + 1] + heights[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (heights[i] == 0) {
            if (abs(pre[i - 1] - suff[i + 1]) == 0) {
                ans += 2;
            } else if (abs(pre[i - 1] - suff[i + 1]) == 1) {
                ans += 1;
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
