#include <iostream>
using namespace std;

int findMinimumQuestions(int truthTellers, int uncertainPeople) {
    if (truthTellers <= uncertainPeople) {
        return -1;
    }
    return 2 * uncertainPeople + 1;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int truthTellers, uncertainPeople;
        cin >> truthTellers >> uncertainPeople;

        int result = findMinimumQuestions(truthTellers, uncertainPeople);
        cout << result << endl;
    }

    return 0;
}
