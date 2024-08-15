#include <iostream>
#include <algorithm>
#include <string>


bool is_palindrome(const std::string& s) {
	int len = s.length();
	for (int i = 0; i < len / 2; ++i) {
		if (s[i] != s[len - 1 - i]) {
			return false;
		}
	}
	return true;
}

bool contains_palindromic_substring(const std::string& s, int K) {
	int n = s.length();

	for (int i = 0; i <= n - K; ++i) {
		std::string substring = s.substr(i, K);
		if (is_palindrome(substring)) {
			return true;
		}
	}

	return false;
}


int main() {
	int N, K;
	std::cin >> N >> K;
	std::string s;
	std::cin >> s;

	std::sort(s.begin(), s.end());
	int count = 0;
	do {
		if (!contains_palindromic_substring(s, K)) {
			count++;
		}

	} while (std::next_permutation(s.begin(), s.end()));
	std::cout << count << std::endl;
	return 0;
}
