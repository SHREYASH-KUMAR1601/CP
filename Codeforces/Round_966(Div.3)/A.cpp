/*
*    Author: ShreyashxDON
*    Created: Thursday, 22.08.2024 04:04 PM (GMT+5:30)

    ॐ त्र्यम्बकं यजामहे , सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान् ,मृत्योर्मुक्षीय मामृतात् ॥

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

void solve() {
    string s;
    cin >> s;

    if (s.length() >= 2 && s[0] == '1' && s[1] == '0') {
        string st = s.substr(2);

        if (!st.empty() && st[0] == '0') {
            cout << "NO" << endl;
            return;
        }

        int num = (st.empty() ? 0 : stoi(st));

        if (num >= 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
