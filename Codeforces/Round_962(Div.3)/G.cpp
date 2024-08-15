#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct DSU {
    vector<int> parent;

    DSU(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        DSU dsu(n);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            dsu.unite(a - 1, b - 1); // Adjust for 0-based indexing
        }

        int connectedComponents = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) { // Check if node is its own parent
                connectedComponents++;
            }
        }

        cout << connectedComponents << endl;
    }

    return 0;
}
