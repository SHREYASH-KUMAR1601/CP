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
		int n;
		cin >> n;
		vector<int> v(n, 0);
		unordered_map<int, int>mp;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			mp[v[i]]++;
		}

		int ans = 0;
		int last_max = INT_MIN;
		int turn = 0;
		sort(v.begin() , v.end());
		for (int i = 0; i < n; ++i) {
			if (turn == 0 and v[i] > last_max) {
				ans++;
				last_max = v[i];
				turn = 1;
			} else if (turn == 0 and v[i] <= last_max) {
				while (v[i] <= last_max and i < n) {
					i++;
				}
				ans++;
				last_max = v[i];
				turn = 1;
			} else if (turn == 1) {
				while (v[i] <= last_max and i < n) {
					i++;
				}
				turn = 0;
			}
		}

		cout << ans << endl;
	}

}