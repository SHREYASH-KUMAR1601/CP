#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bitset<N>p;
vector<int>primes;
void Seive() {

	for (int i = 3; i * i <= N; i += 2) {
		if (p[i] == 0) {
			for (int j = i * i; j <= N; j += i) {
				p[j] = 1;
			}
		}
	}
	p[2] = 0;
	primes.push_back(2);
	// cout << 2 << " ";
	for (int i = 3; i <= N; i += 2) {
		if (p[i] == 0) {
			// cout << i << " ";
			primes.push_back(i);
		}
	}
}

//bitset p1[i] == 0 means i is a prime number



void Segmented_Seive(int l, int r) {
	//I have to iterate over prime numbers from 0 ---> sqrt(r)
	bitset<10005>p1;
	for (int i = 0; primes[i]*primes[i] <= r; i++) {

		int start = (l / primes[i]) * primes[i];
		if (start < l) {
			start += primes[i];
		}

		for (int j = start; j <= r; j += primes[i]) {
			p1[j - l] = 1;
		}

		if (start == primes[i]) {
			p1[start - l] = 0;
		}
	}

	for (int i = l; i <= r; i++) {
		if (p1[i - l] == 0) {
			cout << i << " ";
		}
	}

	cout << endl << endl;
}

int main() {
	IOS;
	Seive();
	int t;
	cin >> t;

	while (t--) {
		int l, r;
		cin >> l >> r;
		// cout << l << r << endl;
		if (l == 1) l++;
		Segmented_Seive(l, r);

	}


}