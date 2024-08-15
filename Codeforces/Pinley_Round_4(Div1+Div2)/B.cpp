#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

void do_test() {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];

    vector<int> a(n);
    a[0] = b[0];
    for (int i = 1; i < n - 1; i++) {
        a[i] = b[i - 1] | b[i];
    }
    a[n - 1] = b[n - 2];

    for (int i = 0; i < n - 1; i++) {
        if (b[i] != (a[i] & a[i + 1])) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        do_test();
    }

    return 0;
}
