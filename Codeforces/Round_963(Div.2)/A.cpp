#include <bits/stdc++.h>

using namespace std;

int t, n;

string s;
int main() {
    cin >> t;

    while (t--) {
        cin >> n >> s;

        unordered_map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        int result = 0;
        result += min(count['A'], n);
        result += min(count['B'], n);
        result += min(count['C'], n);
        result += min(count['D'], n);

        cout << result << endl;
    }

    return 0;
}
