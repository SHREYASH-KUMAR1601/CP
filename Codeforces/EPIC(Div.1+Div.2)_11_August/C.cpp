#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

ll squaredDist(ll x1, ll y1, ll x2, ll y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool canReachGoal(ll xs, ll ys, ll xt, ll yt, const vector<pair<ll, ll>>& circles) {
    ll goalDistSquared = squaredDist(xs, ys, xt, yt);

    for (const auto& c : circles) {
        ll cx = c.first, cy = c.second;
        ll distStart = squaredDist(xs, ys, cx, cy);
        ll distEnd = squaredDist(xt, yt, cx, cy);

        if (distEnd <= goalDistSquared) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;

    while (numTests--) {
        int numCircles;
        cin >> numCircles;

        vector<pair<ll, ll>> circles(numCircles);
        for (int i = 0; i < numCircles; ++i) {
            cin >> circles[i].first >> circles[i].second;
        }

        ll startX, startY, goalX, goalY;
        cin >> startX >> startY >> goalX >> goalY;

        if (canReachGoal(startX, startY, goalX, goalY, circles)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
