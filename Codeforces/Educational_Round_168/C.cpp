#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX_N = 2e5 + 5;
const int MOD = 1e9 + 7;

ll powerMod(ll base, ll exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        ll half = powerMod(base, exp / 2);
        return (half * half) % MOD;
    } else {
        return (base * powerMod(base, exp - 1)) % MOD;
    }
}

vector<ll> getDivisors(ll num) {
    vector<ll> divisors;
    for (ll i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            divisors.push_back(i);
            if (i != num / i) {
                divisors.push_back(num / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}


vector<ll> factorize(ll num) {
    vector<ll> factors;
    while (num % 2 == 0) {
        factors.push_back(2);
        num /= 2;
    }
    for (ll i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            factors.push_back(i);
            num /= i;
        }
    }
    if (num > 2) factors.push_back(num);
    return factors;
}

bool isInBounds(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

bool customCompare(pair<ll, ll>& a, pair<ll, ll>& b) {
    ll diffA = a.first - a.second;
    ll diffB = b.first - b.second;
    return diffA == diffB ? a.first > b.first : diffA < diffB;
}

void process() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll length;
    cin >> length;
    string seq;
    cin >> seq;
    vector<int> positions;
    positions.push_back(0);
    ll result = 0;
    for (int i = 1; i < length; ++i) {
        if (seq[i] == '_') {
            if (!positions.empty()) {
                result += i - positions.back();
                positions.pop_back();
            } else {
                positions.push_back(i);
            }
        } else if (seq[i] == '(') {
            positions.push_back(i);
        } else if (seq[i] == ')') {
            if (!positions.empty()) {
                result += i - positions.back();
                positions.pop_back();
            }
        }
    }
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        process();
    }
    return 0;
}
