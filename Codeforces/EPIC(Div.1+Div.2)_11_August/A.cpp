#include <iostream>

using namespace std;

typedef long long ll;
ll calculate_answer(int n, int m, int k) {
    return min(n, k) * min(m, k);
}
void input_output() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        ll ans = calculate_answer(n, m, k);
        cout << ans << endl;
    }
}




int main() {
    input_output();
    return 0;
}
