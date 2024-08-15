#include <bits/stdc++.h>
using namespace std;
// std::string removeConsecutiveDuplicates(const std::string& s) {
// 	std::string result = s;
// 	bool removed = true;

// 	while (removed) {
// 		removed = false;
// 		std::string tempResult;

// 		for (size_t i = 0; i < result.size(); ++i) {
// 			if (i + 1 < result.size() && result[i] == result[i + 1]) {
// 				// Skip the next character
// 				++i;
// 				removed = true;
// 			} else {
// 				tempResult += result[i];
// 			}
// 		}

// 		result = tempResult;
// 	}

// 	return result;
// }

int main() {
	string s;
	cin >> s;

	// std::string cleanedString = removeConsecutiveDuplicates(s);
	// std::cout << cleanedString << std::endl;

	stack<char>st;
	for (int i = 0; i < s.length(); ++i) {
		if (!st.empty())
		{
			if (s[i] == st.top())
				st.pop();
			else
				st.push(s[i]);

		}
		else
			st.push(s[i]);
	}

	string x;
	while (!st.empty()) {
		x += st.top();
		st.pop();
	}

	for (int i = x.length() - 1; i >= 0; --i)
	{
		cout << x[i];
	}

	return 0;
}
