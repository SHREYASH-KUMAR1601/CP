#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// bitset<size>b it is 8 time efficient than vector
// vector<bool>p(N, 0);

bitset<N>p; // It stores only one bits and is initialised with zero

// If p[i] == 0, it means that it is a prime number
void Seive(int n) {

	for (int i = 3; i * i < n; i += 2) {
		if (p[i] == 0) {
			for (int j = i * i; j <= n; j += i) {
				p[j] = 1;
			}
		}
	}
	p[2] = 0;

	cout << 2 << " ";
	for (int i = 3; i <= n; i += 2) {
		if (p[i] == 0) {
			cout << i << " ";
		}
	}
}


int main() {
	IOS;

	int n;
	cin >> n;
	Seive(n);

}