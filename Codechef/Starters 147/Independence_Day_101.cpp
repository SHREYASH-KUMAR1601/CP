#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;

        int max_strips = max(A, max(B, C));
        int other_two_sum = A + B + C - max_strips;

        if (max_strips <= other_two_sum + 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
