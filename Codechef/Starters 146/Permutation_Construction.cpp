/*
*    Author: ShreyashxDON
*    Created: Wednesday, 07.08.2024 08:45 PM (GMT+5:30)
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

vector<int> generatePermutation(int N) {
    vector<int> perm(N);

    int left = 1, right = N;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            perm[i] = left++;
        } else {
            perm[i] = right--;
        }
    }

    return perm;
}

void solve() {
    int N;
    cin >> N;
    vector<int> perm = generatePermutation(N);

    for (int i = 0; i < N; ++i) {
        cout << perm[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
