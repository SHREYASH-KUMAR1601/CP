#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAXN = 1000005;

vector<int> fact(MAXN), invFact(MAXN);

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[MAXN - 1] = mod_exp(fact[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 0; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

int nCr(int n, int r) {
    if (r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int compute_result(int n, int k, const vector<int>& a) {
    int c1 = 0;
    for (int x : a) {
        if (x == 1) ++c1;
    }
    int c0 = n - c1;
    int mini = (k + 1) / 2;
    if (c1 < mini) return 0;

    int result = 0;
    for (int i = mini; i <= min(c1, k); ++i) {
        result = (result + nCr(c1, i) * nCr(c0, k - i)) % MOD;
    }
    return result;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_factorials();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        cout << compute_result(n, k, arr) << endl;
    }

    return 0;
}
