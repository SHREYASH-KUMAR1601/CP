#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N] = {0};

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        int mx = 0 , ans = 0;
        long long sum = 0;

        for (int i = 1; i <= n; ++i)
        {
            sum += a[i];
            mx = max(a[i], mx);

            if (mx == sum - mx) {
                ans++;
            }
        }

        cout << ans << endl;

    }
}
