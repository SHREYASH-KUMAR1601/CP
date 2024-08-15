/*
*    Author: ShreyashxDON
*    Created: Wednesday, 07.08.2024 09:13 PM (GMT+5:30)
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

// Common Mistakes:
// 1. Use sqrtl() instead of sqrt() for long long
// 2. if a[i] goes to 10^9, you only need to check for primes till sqrt(10^9) i.e. 31623
// 3. GCD of |x-y|?
// 4. should pairity of x and y be equal?
// 5. Huffman Coding? Merging 2 smallest elements?
// 6. Coordinate Compression?
// 7. Min/Max Spanning Tree.
// 8. Topo sort ? if there is something related to relative ordering.
// 9. Try calculating it in reverse order?

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Count characters in reverse for "back"
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    for (char c : s2) {
        if (c == 'k') cnt4++;
        else if (c == 'c' && cnt4) { cnt4--; cnt3++; }
        else if (c == 'a' && cnt3) { cnt3--; cnt2++; }
        else if (c == 'b' && cnt2) { cnt2--; cnt1++; }
    }

    int ans = cnt1 * 3; // Initial characters to be removed
    int new_char = cnt1; // Characters to be added to after removing "back"
    while (new_char) {
        if (cnt2) {
            ans += cnt2 * 3;
            cnt2 = 0;
        } else if (cnt3 && new_char >= 2) {
            int temp = min(cnt3 * 2, new_char);
            new_char -= (temp / 2);
            ans += (temp / 2) * 3;
            cnt3 -= temp / 2;
        } else if (cnt4 && new_char >= 3) {
            int temp = min(3 * cnt4, new_char);
            new_char -= (temp / 3) * 2;
            ans += (temp / 3) * 3;
            cnt4 -= temp / 3;
        } else {
            ans += (new_char / 4) * 3;
            new_char -= (new_char / 4) * 3;
            if (new_char < 4) break;
        }
    }

    // Count characters for "front"
    int fc1 = 0, fc2 = 0, fc3 = 0, fc4 = 0, fc5 = 0;
    for (char c : s) {
        if (c == 'f') fc1++;
        else if (c == 'r' && fc1) { fc1--; fc2++; }
        else if (c == 'o' && fc2) { fc2--; fc3++; }
        else if (c == 'n' && fc3) { fc3--; fc4++; }
        else if (c == 't' && fc4) { fc4--; fc5++; }
    }

    ans += fc5 * 4; // Add characters needed to form "front"
    new_char = fc5; // Characters to be added to make "front"
    while (new_char) {
        if (fc4) {
            ans += fc4 * 4;
            fc4 = 0;
        } else if (fc3 && new_char >= 2) {
            int temp = min(fc3 * 2, new_char);
            new_char -= (temp / 2);
            ans += (temp / 2) * 4;
            fc3 -= temp / 2;
        } else if (fc2 && new_char >= 3) {
            int temp = min(fc2 * 3, new_char);
            new_char -= (temp / 3) * 2;
            ans += (temp / 3) * 4;
            fc2 -= temp / 3;
        } else if (fc1 && new_char >= 4) {
            int temp = min(fc1 * 4, new_char);
            new_char -= (temp / 4) * 3;
            ans += (temp / 4) * 4;
            fc1 -= temp / 4;
        } else {
            ans += (new_char / 5) * 4;
            new_char -= (new_char / 5) * 4;
            if (new_char < 5) break;
        }
    }

    cout << s.size() - ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
