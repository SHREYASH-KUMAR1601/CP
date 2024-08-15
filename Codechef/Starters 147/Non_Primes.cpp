/*
*    Author: ShreyashxDON
*    Created: Wednesday, 14.08.2024 08:14 PM (GMT+5:30)
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define int long long int
#define endl '\n'

bitset<N> p;  // It stores only one bit per element and is initialized with zero

// If p[i] == 0, it means that it is a prime number
void Seive(int n) {
    p[0] = p[1] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (p[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                p[j] = 1;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> odd, even;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even.push_back({a[i], i + 1});
        } else {
            odd.push_back({a[i], i + 1});
        }
    }

    // Check even + even pairs
    for (auto x : even) {
        for (auto y : even) {
            if (x.second < y.second && p[x.first + y.first] != 0) {
                cout << x.second << " " << y.second << endl;
                return;
            }
        }
    }

    // Check odd + odd pairs
    for (auto x : odd) {
        for (auto y : odd) {
            if (x.second < y.second && p[x.first + y.first] != 0) {
                cout << x.second << " " << y.second << endl;
                return;
            }
        }
    }

    //Check odd+even pairs
    for (auto x : even) {
        for (auto y : odd) {
            if (p[x.first + y.first] != 0 || x.first + y.first == 2) {  // Sum is not prime
                cout << x.second << " " << y.second << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Seive(210);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


/*
*    Author: ShreyashxDON
*    Created: Wednesday, 14.08.2024 08:14 PM (GMT+5:30)
*/
// #include <bits/stdc++.h>
// using namespace std;

// const int MAX_SUM = 200;
// #define int long long int
// #define endl '\n'

// vector<bool> is_prime(MAX_SUM + 1);

// // Function to precompute prime numbers up to MAX_SUM
// void initializePrimes() {
//     fill(is_prime.begin(), is_prime.end(), true);
//     is_prime[0] = is_prime[1] = false;

//     for (int i = 2; i * i <= MAX_SUM; ++i) {
//         if (is_prime[i]) {
//             for (int j = i * i; j <= MAX_SUM; j += i) {
//                 is_prime[j] = false;
//             }
//         }
//     }
// }

// // Function to find a valid pair
// bool findPair(const unordered_map<int, vector<int>>& index_map) {
//     for (const auto& [num1, indices1] : index_map) {
//         for (const auto& [num2, indices2] : index_map) {
//             if (num1 != num2 && !is_prime[num1 + num2]) {
//                 cout << indices1[0] << " " << indices2[0] << endl;
//                 return true;
//             }
//         }
//     }

//     for (const auto& [num, indices] : index_map) {
//         if (indices.size() > 1 && !is_prime[2 * num]) {
//             cout << indices[0] << " " << indices[1] << endl;
//             return true;
//         }
//     }

//     return false;
// }

// // Function to process each test case
// void processTestCase() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     unordered_map<int, vector<int>> index_map;

//     for (int i = 0; i < n; ++i) {
//         cin >> arr[i];
//         index_map[arr[i]].push_back(i + 1);
//     }

//     if (!findPair(index_map)) {
//         cout << -1 << endl;
//     }
// }

// signed main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     initializePrimes();

//     int t;
//     cin >> t;
//     while (t--) {
//         processTestCase();
//     }

//     return 0;
// }
