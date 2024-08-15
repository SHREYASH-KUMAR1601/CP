#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int strength(const string& password) {
    if (password.empty()) return 0;
    int time = 2;
    for (size_t i = 1; i < password.size(); ++i) {
        if (password[i] == password[i - 1]) {
            time += 1;
        } else {
            time += 2;
        }
    }
    return time;
}

int main() {
    int t;
    cin >> t;
    vector<string> results;

    while (t--) {
        string s;
        cin >> s;
        int maxTime = 0;
        string bestPassword;

        for (char ch = 'a'; ch <= 'z'; ++ch) {
            for (size_t i = 0; i <= s.size(); ++i) {
                string newPassword = s.substr(0, i) + ch + s.substr(i);
                int newTime = strength(newPassword);
                if (newTime > maxTime) {
                    maxTime = newTime;
                    bestPassword = newPassword;
                }
            }
        }
        results.push_back(bestPassword);
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
