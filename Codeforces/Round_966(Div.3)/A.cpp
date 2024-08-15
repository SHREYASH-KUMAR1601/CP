#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    set<int> possible_numbers;

    // Generating possible mistaken forms of 10^x
    for (int i = 2; i <= 4; ++i) {
        string num = "10";
        num += string(i - 1, '0');
        possible_numbers.insert(stoi(num));
    }

    while (t--) {
        int a;
        cin >> a;
        if (possible_numbers.count(a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
