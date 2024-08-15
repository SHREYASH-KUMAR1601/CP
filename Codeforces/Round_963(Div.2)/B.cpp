#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
int32_t main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), odd, even;
        int oddC = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                even.push_back(a[i]);
            } else {
                odd.push_back(a[i]);
                oddC++;
            }
        }

        if (oddC == 0 || oddC == n) {
            cout << "0" << endl;
            continue;
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        int ans1 = 0, temp = odd.back();
        for (int i = 0; i < even.size(); ++i) {
            if (even[i] < temp) {
                ans1++;
                temp += even[i];
            } else {
                ans1 += 2;
                temp += 2 * even[i];
            }
        }

        int ans2 = 0, temp1 = odd.back();
        reverse(even.begin(), even.end());
        for (int i = 0; i < even.size(); ++i) {
            if (even[i] < temp1) {
                ans2++;
                temp1 += even[i];
            } else {
                ans2 += 2;
                temp1 += 2 * even[i];
            }
        }

        cout << min(ans1, ans2) << endl;
    }
}
