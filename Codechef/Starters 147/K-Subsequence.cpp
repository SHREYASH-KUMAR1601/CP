

#include <bits/stdc++.h>
using namespace std;



const int MXN = 5e5 + 5;
const int LOG = 20;

int n, q;
int p[LOG][MXN];
int val[MXN];
pair<int, int> st[MXN << 2];

void build(int l, int r, int x)
{
    if (l == r)
    {
        st[x] = {val[l], l};
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, 2 * x);
    build(mid + 1, r, 2 * x + 1);
    st[x] = max(st[2 * x], st[2 * x + 1]);
}
pair<int, int> get(int l, int r, int x, int lx, int rx)
{
    if (l > rx || r < lx) return { -inf, -1};
    if (l >= lx && r <= rx) return st[x];
    int mid = (l + r) >> 1;
    return max(get(l, mid, 2 * x, lx, rx), get(mid + 1, r, 2 * x + 1, lx, rx));
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        val[i] = val[i] + i;
    }
    build(1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        p[0][i] = get(1, n, 1, i, val[i]).second;
    }
    for (int i = 1; i < LOG; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (val[x] >= y)
        {
            cout << 1 << '\n';
            continue;
        }
        int res = 0;
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (val[p[i][x]] >= y) continue;
            x = p[i][x];
            res += (1LL << i);
        }
        if (val[p[0][x]] < y)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << res + 2 << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

}