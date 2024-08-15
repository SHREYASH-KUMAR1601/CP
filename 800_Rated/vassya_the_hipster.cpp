#include <bits/stdc++.h> // Include all standard C++ headers
using namespace std;


int main() {
	int a , b;
	cin >> a >> b;

	int days = min(a, b);
	int remDays = abs(b - a) / 2;
	cout << days << " " << remDays << endl;
}