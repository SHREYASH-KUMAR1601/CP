#include <bits/stdc++.h>
using namespace std;

// Extended Euclidean Algorithm to find x and y for a*x + b*y = gcd(a, b)
tuple<long long, long long, long long> extendedGCD(long long a, long long b) {
    if (b == 0) {
        return {a, 1, 0};
    } else {
        auto [g, x1, y1] = extendedGCD(b, a % b);
        return {g, y1, x1 - (a / b) * y1};
    }
}

long long maximizeScore(int n, int m, int l, int f) {
    // Compute gcd and coefficients using extended GCD
    tuple<long long, long long, long long> result = extendedGCD(l, f);
    long long g = get<0>(result);
    long long x = get<1>(result);
    long long y = get<2>(result);

    if (g > 1) {
        // If gcd(l, f) > 1, we need to normalize the problem
        return 0;
    }

    // Compute possible ranges of WL and WF
    long long maxScore = 0;

    // Generate valid scores by iterating with adjustments
    long long k = 0; // This can be any integer

    // We need to ensure WL and WF are within their respective bounds
    long long offset1 = (n - x) / f;
    long long offset2 = (m - y) / l;

    // Adjust and compute max possible score
    for (long long t = -100000; t <= 100000; ++t) {
        long long WL = x + t * f;
        long long WF = y - t * l;

        if (WL >= 0 && WL <= n && WF >= 0 && WF <= m) {
            maxScore = max(maxScore, l * WL + f * WF);
        }
    }

    return maxScore;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, l, f;
        cin >> n >> m >> l >> f;
        cout << maximizeScore(n, m, l, f) << endl;
    }

    return 0;
}
