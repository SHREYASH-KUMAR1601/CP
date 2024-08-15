#include <bits/stdc++.h>
using namespace std;
const int N = 10;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
int count1 = 0;
char output[11];
void solve(int i, char maxChar) {

	if (i == n) {
		count1++;
		output[i] = '\0';
		cout << output << endl;
		return;
	}

	for (char ch = 'a'; ch <= maxChar; ch++) {
		output[i] = ch;

		if (ch == maxChar) {
			solve(i + 1, maxChar + 1);
		} else {
			solve(i + 1, maxChar);
		}
	}
}


int main() {
	IOS;


	cin >> n;

	solve(0, 'a');
	// cout << count1 << endl;

}