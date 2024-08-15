#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int x, y, gcde;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}
void EED(int a, int b) {

	if (b == 0) {
		x = 1;
		y = 0;
		gcde = a;
		return;
	}


	EED(b, a % b);

	int current_x = y;
	int current_y = x - ((a / b) * y);

	x = current_x;
	y = current_y;
}

int MMI(int a , int m) {

	if (gcd(a, m) != 1) {
		return -1;
	}

	EED(a, m);

	return (x + m) % m;
}
int main() {
	// IOS;

	int a, b;
	cin >> a >> b;


	cout << MMI(a, b) << endl;


}