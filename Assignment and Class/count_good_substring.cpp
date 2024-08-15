#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0)
#define int long long

void solve(string s) {
	int even = 0;
	int odd = s.length();

	int count[2][2] = {{0, 0}, {0, 0}}; //[a/b][even/odd]  [0][0] = count_even_a ; [0][1] = count_odd_a
	//[1][0] = count_even_b; [1][1] = count_odd_b;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a') {
			if (i % 2 == 0) {
				count[0][0]++;
			} else {
				count[0][1]++;
			}
		} else {
			if (i % 2 == 0) {
				count[1][0]++;
			} else {
				count[1][1]++;
			}
		}
	}

	for (int i = s.length() - 1; i >= 0; --i) {
		if (s[i] == 'a') {
			if (i % 2 == 0) {
				count[0][0]--;
				even = even + count[0][1];
				odd = odd + count[0][0];
			} else {
				count[0][1]--;
				odd = odd + count[0][1];
				even += count[0][0];
			}
		} else {
			if (i % 2 == 0) {
				count[1][0]--;
				even = even + count[1][1];
				odd = odd + count[1][0];

			} else {
				count[1][1]--;
				odd = odd + count[1][1];
				even = even + count[1][0];
			}
		}
	}

	cout << even << " " << odd << endl;

}

// int Count[2][2]; //0->odd , 1->even , 97 -> a , 98-> b
// void solve(string s) {
// 	int even = 0;
// 	int odd = 0;

// 	for (int i = 0; i < s.length(); i++) {
// 		odd++;

// 		if (i % 2 == 0) {	//even index
// 			odd += Count[s[i] - 'a'][1];
// 			Count[s[i] - 'a'][1]++;
// 			even += Count[s[i] - 'a'][0];
// 		} else {	//odd index
// 			odd += Count[s[i] - 'a'][0];
// 			Count[s[i] - 'a'][0]++;
// 			even += Count[s[i] - 'a'][1];
// 		}
// 	}


// 	cout << even << " " << odd << endl;

// }
int32_t main() {
	IOS;

	string s;
	cin >> s;

	solve(s);

}