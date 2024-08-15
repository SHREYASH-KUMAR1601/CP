#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int x, y, gcde;

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
int main() {
	// IOS;

	int a, b;
	cin >> a >> b;

	bool flag = false;
	if (a < b) {
		swap(a, b);
		flag = true;
	}
	EED(a, b);

	if (!flag) {
		cout << x << " " << y << endl << gcde << endl;
	} else {
		cout << y << " " << x << endl << gcde << endl;
	}
}