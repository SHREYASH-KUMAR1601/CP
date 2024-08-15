#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


long long mul(int a, int b, int c) {
    return a * b + a * c + b * c;
}

int main() {
    IOS;

    int t;
    cin >> t;
    while (t--) {
        long long co = 0;
        int n, x;
        cin >> n >> x;

        for (int a = 1; a <= x; ++a) {
            int b_max = min(x - a, n / a);
            for (int b = 1; b <= b_max; ++b) {
                int c_max = min(x - a - b, (n - a * b) / (a + b));
                co += max(0, c_max);
            }
        }

        cout << co  << endl;
    }

    return 0;
}
