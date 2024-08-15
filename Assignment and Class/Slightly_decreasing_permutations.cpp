#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int k;
	cin >> k;

	for (int i = n ; i >= n - k + 1 ; i--) {
		cout << i << " ";
	}
	for (int i = 1 ; i <= n - k ; i++) {
		cout << i << " ";
	}
}