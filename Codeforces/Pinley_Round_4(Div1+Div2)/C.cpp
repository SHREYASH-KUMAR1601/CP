#include <bits/stdc++.h>

using namespace std;

vector<int> findOperations(int n, vector<int>& values) {
    int initialParity = values[0] & 1;
    if (!all_of(values.begin(), values.end(), [initialParity](int x) { return (x & 1) == initialParity; })) {
        return { -1};
    }

    vector<int> ops;
    while (ops.size() < 40) {
        int minValue = *min_element(values.begin(), values.end());
        int maxValue = *max_element(values.begin(), values.end());

        if (minValue == maxValue && maxValue == 0) {
            break;
        }

        int median = minValue + (maxValue - minValue) / 2;
        ops.push_back(median);

        for (int& v : values) {
            v = abs(v - median);
        }
    }

    if (accumulate(values.begin(), values.end(), 0) != 0) {
        return { -1};
    }

    ops.insert(ops.begin(), ops.size());
    return ops;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;

    while (numTests--) {
        int numValues;
        cin >> numValues;
        vector<int> values(numValues);
        for (int &v : values) {
            cin >> v;
        }

        vector<int> result = findOperations(numValues, values);

        if (result[0] == -1) {
            cout << -1 << '\n';
        } else {
            cout << result[0] << '\n';
            for (int i = 1; i < result.size(); ++i) {
                cout << result[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
