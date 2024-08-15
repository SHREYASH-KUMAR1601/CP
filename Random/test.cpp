#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isValidMapping(const vector<string>& crypt, const unordered_map<char, int>& mapping) {
    long long nums[3] = {0, 0, 0};

    int i = 0;
    while (i < 3) {
        const string& word = crypt[i];
        if (mapping.at(word[0]) == 0 && word.length() > 1) {
            return false;
        }
        int j = 0;
        while (j < word.length()) {
            nums[i] = nums[i] * 10 + mapping.at(word[j]);
            ++j;
        }
        ++i;
    }

    return nums[0] + nums[1] == nums[2];
}

int countValidSolutions(const vector<string>& crypt, vector<char>& uniqueLetters, int idx, unordered_set<int>& usedDigits, unordered_map<char, int>& mapping) {
    if (idx == uniqueLetters.size()) {
        return isValidMapping(crypt, mapping) ? 1 : 0;
    }

    int count = 0;
    int digit = 0;
    while (digit <= 9) {
        if (usedDigits.find(digit) == usedDigits.end()) {
            mapping[uniqueLetters[idx]] = digit;
            usedDigits.insert(digit);
            count += countValidSolutions(crypt, uniqueLetters, idx + 1, usedDigits, mapping);
            usedDigits.erase(digit);
        }
        ++digit;
    }

    return count;
}

int solution(vector<string> crypt) {
    unordered_set<char> seen;
    for (const string& word : crypt) {
        for (char c : word) {
            seen.insert(c);
        }
    }

    vector<char> uniqueLetters(seen.begin(), seen.end());
    unordered_map<char, int> mapping;
    unordered_set<int> usedDigits;

    return countValidSolutions(crypt, uniqueLetters, 0, usedDigits, mapping);
}

int main() {
    vector<string> crypt = {"SEND", "MORE", "MONEY"};
    cout << "Number of valid solutions: " << solution(crypt) << endl;
    return 0;
}
