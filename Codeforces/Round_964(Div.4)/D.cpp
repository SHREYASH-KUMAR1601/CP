#include <bits/stdc++.h>
using namespace std;

bool canTransform(const string& s, const string& t) {
    int tj = 0;
    for (int si = 0; si < s.size() && tj < t.size(); ++si) {
        if (s[si] == t[tj] || s[si] == '?') {
            ++tj;
        }
    }
    return tj == t.size();
}

string transformString(string s, const string& t) {
    int tj = 0;
    for (char& ch : s) {
        if (ch == '?') {
            if (tj < t.size()) {
                ch = t[tj++];
            } else {
                ch = 'a';
            }
        } else if (ch == t[tj]) {
            tj++;
        }
    }
    return s;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        string s, t;
        cin >> s >> t;

        if (canTransform(s, t)) {
            cout << "YES" << endl;
            cout << transformString(s, t) << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
