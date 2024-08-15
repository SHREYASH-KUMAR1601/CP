#include <bits/stdc++.h>
using namespace std;

int power_of_three(int exponent) {
    return pow(3, exponent);
}

int max_power_of_three_leq(int number) {
    int exponent = log2(number) / log2(3);
    return power_of_three(exponent);
}

int compute_answer(int l, int r) {
    int power = log2(l) / log2(3);
    power++;
    int result = 2 * power;

    while (r > l) {
        int current_power = log2(r) / log2(3);
        int max_power = power_of_three(current_power);
        int count = r - max(max_power, l + 1);
        result += ((current_power + 1) * (count + 1));
        r = max_power - 1;
    }

    return result;
}

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int left, right;
        cin >> left >> right;

        int result = compute_answer(left, right);
        cout << result << endl;
    }

    return 0;
}
