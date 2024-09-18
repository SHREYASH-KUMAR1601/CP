/*
*    Author: ShreyashxDON
*    Created: Sunday, 08.09.2024 10:45 AM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

// Use sqrtl() instead of sqrt() for long long

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pre(n, 0);
    pre[0] = a[0];

    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        int offset = i ? pre[i - 1] : 0;
        int r = upper_bound(pre.begin() + i, pre.end(), offset + x) - pre.begin();

        if (r < n) {
            dp[i] = 1 + ((r + 1 < n) ? dp[r + 1] : 0); // Ensure to correctly reference dp[r + 1]
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (n - i) - dp[i];
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
