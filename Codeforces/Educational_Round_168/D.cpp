#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back

const ll INF = LLONG_MAX;

void dfs(ll node, const vector<vll>& graph, const vll& values, vll& dp, ll& result) {
    ll minValue = INF;

    for (const ll& neighbor : graph[node]) {
        dfs(neighbor, graph, values, dp, result);
        minValue = min(minValue, dp[neighbor]);
    }

    if (minValue == INF || minValue == 1000) {
        dp[node] = values[node];
    } else {
        dp[node] = (values[node] >= minValue) ? minValue : (minValue + values[node]) / 2;
    }

    if (node == 0) {
        result = values[0] + minValue;
    }
}

void readInput(vll& values, vector<vll>& graph) {
    ll numNodes;
    cin >> numNodes;
    values.resize(numNodes);
    graph.resize(numNodes);

    for (ll& value : values) {
        cin >> value;
    }

    for (ll i = 1; i < numNodes; ++i) {
        ll parent;
        cin >> parent;
        --parent;
        graph[parent].pb(i);
    }
}

void solve() {
    vll values;
    vector<vll> graph;
    readInput(values, graph);

    ll result = 0;
    vll dp(values.size(), INF);

    dfs(0, graph, values, dp, result);

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
