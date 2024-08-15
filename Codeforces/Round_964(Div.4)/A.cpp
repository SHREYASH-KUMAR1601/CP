#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        int sum = (n / 10) + (n % 10);

        std::cout << sum << std::endl;
    }

    return 0;
}
