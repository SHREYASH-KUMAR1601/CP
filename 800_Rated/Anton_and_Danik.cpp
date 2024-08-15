#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;

// Main function
int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;
	int countA = 0, countD = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') countA++;
		else countD++;
	}

	if (countA > countD) {
		cout << "Anton" << endl;
	}
	else if (countA < countD) {
		cout << "Danik" << endl;
	} else {
		cout << "Friendship" << endl;
	}

}