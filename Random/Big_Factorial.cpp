#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void multiply(vector<int>&a, int &no, int mu) {
	int carry = 0;
	for (int i = 0; i < no; ++i) {
		int mul = a[i] * mu + carry;
		a[i] = mul % 10;
		carry = mul / 10;
	}

	while (carry != 0) {
		a[no] = carry % 10;
		carry = carry / 10;
		no++;
	}
}

void fact(int n) {
	vector<int>a(N, 0);

	a[0] = 1;
	int no = 1;	//trak no. of digits in the array
	for (int i = 2; i <= n; ++i) {
		multiply(a, no, i);
	}

	//print the result
	for (int i = no - 1; i >= 0; --i) {
		cout << a[i];
	}
}

int main() {
	IOS;

	int t;
	cin >> t;

	fact(t);

}