#include <iostream>
#include <algorithm>
using namespace std;

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // Convert both strings to lowercase
    for (char& c : s1) {
        c = toLower(c);
    }
    for (char& c : s2) {
        c = toLower(c);
    }

    // Perform lexicographical comparison
    if (s1 < s2) {
        cout << -1 << endl;
    } else if (s1 > s2) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
