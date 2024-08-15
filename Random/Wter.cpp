#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int a, int b, vector<int> c) {
    vector<int> river(a, 0);
    int m = c.size();
    int totalLen = 0;
    for (int size : c) {
        totalLen += size;
    }
    int remainingSpace = a - totalLen;
    int pos = 0;
    int idx = 0;

    while (idx < m) {
        int placeAt = pos + min(remainingSpace, b - 1);
        remainingSpace -= (placeAt - pos);

        if (placeAt + c[idx] > a) {
            return { -1};
        }

        fill(river.begin() + placeAt, river.begin() + placeAt + c[idx], idx + 1);

        pos = placeAt + c[idx];
        ++idx;
    }

    int lastPos = 0;
    int i = 0;

    while (i < a) {
        if (river[i] != 0) {
            if (i - lastPos > b) {
                return { -1};
            }
            lastPos = i + c[river[i] - 1] - 1;
        }
        ++i;
    }

    if (a - lastPos > b) {
        return { -1};
    }

    return river;
}

int main() {
    vector<int> C1 = {1, 2, 1};
    int A1 = 7, B1 = 2;
    vector<int> output1 = solution(A1, B1, C1);
    for (int val : output1) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> C2 = {2};
    int A2 = 10, B2 = 5;
    vector<int> output2 = solution(A2, B2, C2);
    for (int val : output2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
