#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ALPHABET_SIZE 26
#define MOD 1000000007

int main() {
    IOS;

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        vector<vector<int>> prefixA(ALPHABET_SIZE, vector<int>(n + 1, 0));
        vector<vector<int>> prefixB(ALPHABET_SIZE, vector<int>(n + 1, 0));

        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < ALPHABET_SIZE; ++c) {
                prefixA[c][i + 1] = prefixA[c][i];
                prefixB[c][i + 1] = prefixB[c][i];
            }
            prefixA[a[i] - 'a'][i + 1]++;
            prefixB[b[i] - 'a'][i + 1]++;
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;

            vector<int> freqA(ALPHABET_SIZE, 0);
            vector<int> freqB(ALPHABET_SIZE, 0);

            for (int c = 0; c < ALPHABET_SIZE; ++c) {
                freqA[c] = prefixA[c][r + 1] - prefixA[c][l];
                freqB[c] = prefixB[c][r + 1] - prefixB[c][l];
            }

            int changes = 0;
            for (int c = 0; c < ALPHABET_SIZE; ++c) {
                changes += abs(freqA[c] - freqB[c]);
            }

            cout << changes / 2 << endl;
        }
    }

    return 0;
}
