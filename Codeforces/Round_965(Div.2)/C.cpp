#include <bits/stdc++.h>
using namespace std;

namespace std {

template <int D, typename T>
struct Vec : public vector < Vec < D - 1, T >> {
    static_assert(D >= 1, "Dimension must be positive");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector < Vec < D - 1, T >> (n, Vec < D - 1, T > (args...)) {}
};

template <typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};

/* Example
    Vec<4, int64_t> f(n, k, 2, 2); // = f[n][k][2][2];
    Vec<2, int> adj(n); // graph
*/

template <class Fun>
class y_combinator_result {
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

    template <class... Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

/* Example
    auto fun = y_combinator([&](auto self, int x) -> void {
        self(x + 1);
    });
*/

}  // namespace std

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {
            return a[i] > a[j];
        });
        int need = ((n - 1) >> 1) + 1;
        int64_t low = 0, high = 1e10;
        while (low < high) {
            int64_t mid = low + high + 1 >> 1;
            bool ok = 0;
            for (int i : ord) {
                if (b[i] == 1) {
                    if (a[i] + k >= mid) ok = 1;
                    int64_t x = mid - a[i] - k;
                    int rem = need;
                    for (int j : ord) {
                        if (j == i) continue;
                        if (rem == 0) break;
                        if (a[j] >= x) rem--;
                    }
                    if (rem == 0) ok = 1;
                    break;
                }
            }
            for (int i : ord) {
                if (b[i] == 0) {
                    int64_t rem = need;
                    int64_t sum = 0;
                    int64_t x = mid - a[i];
                    for (int j : ord) {
                        if (j == i) continue;
                        if (rem == 0) break;
                        if (a[j] >= x) {
                            rem--;
                        } else if (b[j]) {
                            sum += x - a[j];
                            rem--;
                        }
                    }
                    if (rem == 0 && sum <= k) {
                        ok = 1;
                    }
                    break;
                }
            }
            if (ok) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        cout << low << '\n';
    }
}