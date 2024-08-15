#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// 1- Naive Approach

// bool is_prime(int n) {

// 	for (int i = 2; i < n; ++i) {
// 		if (n % i == 0) {
// 			return false;
// 		}
// 	}

// 	return true;
// }

// 2- Optimized naive approach

// bool is_prime(int n) {

// 	for (int i = 2; i * i < n; ++i) {
// 		if (n % i == 0) {
// 			return false;
// 		}
// 	}

// 	return true;
// }


// 3-Prime seive  - O(nloglogn)

void prime_seive(vector<int>&p) {

	// Mark all odd no.s as prime
	for (int i = 3; i <= N; i += 2) {
		p[i] = 1;
	}

	for (int i = 3; i <= N; i = i + 2) {
		//If the current no. is not marked
		if (p[i] == 1) {
			//Mark all multiples of i
			for (int j = i * i; j <= N; j = j + i) {
				p[j] = 0;
			}
		}
	}

	p[2] = 1;
	p[0] = p[1] = 0;

}

int32_t main() {
	IOS;

	int n;
	cin >> n;

	vector<int>p(N, 0);
	prime_seive(p);
	for (int i = 0; i < n; ++i) {
		if (p[i] == 1) {
			cout << i << " ";
		}
	}

}

