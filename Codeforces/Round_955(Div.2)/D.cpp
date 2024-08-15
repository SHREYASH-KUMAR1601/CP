#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;

// Custom Defines (consider organizing alphabetically for clarity)
#define ALL(t) t.begin(), t.end()
#define DBG(var) cerr << #var << " = " << var << endl;
#define FIRST(a) (a).begin()
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORI(i, n) for (int i = 1; i <= n; ++i)
#define FOREACH(i, t) for (auto i = t.begin(); i != t.end(); ++i)
#define INF 1000000000
#define IOS ios_base::sync_with_stdio(0)
#define LAST(a) (--a.end())
#define LL long long
#define MP make_pair
#define PB push_back
#define PRINT_ALL(a) for (auto it = a.begin(); it != a.end(); ++it) cout << *it << " ";
#define REMOVE_FIRST(a) a.erase(a.begin())
#define REMOVE_LAST(a) a.erase(--a.end())
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, a, b) for (int i = a; i >= b; --i)
#define TEST(name) freopen(name, "r", stdin);
#define f first
#define mod 1000000009
#define p_int pair<int, int>
#define print(n) cout << n << endl;
#define s second
#define v_int vector<int>

// Main function
int main() {
    IOS;

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>>heights(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> heights[i][j];
            }
        }

        vector<vector<int>>types(n, vector<int>(m));

        for (int i = 0; i < n; ++i)
        {
            string row;
            cin >> row;
            for (int j = 0; j < m; ++j)
            {
                types[i][j] = row[j] - '0';
            }
        }

        long long snow = 0 , nonSnow = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (types[i][j] == 0) {
                    snow += heights[i][j];
                } else {
                    nonSnow += heights[i][j];
                }
            }
        }

        if (snow == nonSnow) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}