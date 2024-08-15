#include <iostream>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<char> s(n), t(n);

        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> t[i];
        }

        bool transformPossible = true;
        bool hasOne = false;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') hasOne = true;
            if (t[i] == '1' && !hasOne) {
                transformPossible = false;
                break;
            }
        }

        if (transformPossible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
