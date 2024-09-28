/*
*    Author: ShreyashxDON
*    Created: Saturday, 28.09.2024 10:21 AM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int N = 0;
const int MOD = 1e9 + 7;


void solve() {
    int n, q;
    cin >> n >> q;

    vector<int>a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> mp;

    for (int i = 0; i < n; i++) {

        int temp = (i + 1) * (n - i) - 1;
        mp[temp]++;

        if (i > 0) {    //For points in between
            int temp1 = i * (n - i);
            mp[temp1] += (a[i] - a[i - 1]) - 1;
        }
    }

    while (q--) {
        int k;
        cin >> k;

        if (mp.find(k) == mp.end()) {
            cout << "0" << " ";
        } else {
            cout << mp[k] << " ";
        }
    }

    cout << endl;
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