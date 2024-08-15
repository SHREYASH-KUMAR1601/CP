#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592
double Function(double x , double b , double c) {
	return	((x * x) + (b * x) + c) / sin(x);
}

double Derivative(double x , double b , double c) {
	return ((sin(x) * ((2 * x) + b)) - (((x * x) + (b * x) + c) * cos(x)) ) / (sin(x) * sin(x));
}

// 1. method --> using derivative to find sign of mid
double isThisJee(double b , double c) {
	int count = 0;
	double s = 0 , e = PI / 2;
	double ans;
	while (s <= e) {	//while((e-s) > 1e-6)
		double mid = (s + e) / 2;

		if (Derivative(mid, b, c) < 0) {
			ans = mid;
			s = mid;
		} else {
			e = mid;
			ans = mid;
		}
		count++;
		if (count > 100) {
			break;
		}
	}

	return ans;
}

// 2. Using Ternary search

double isThisJee2(double b , double c) {
	double s = 0 , e = PI / 2;
	double ans;
	while (e - s > 1e-6) {
		double m1 = s + (e - s) / 3.0 ;
		double m2 = e - (e - s) / 3.0 ;

		if (Function(m1, b, c) > Function(m2, b, c)) {
			s = m1;
			ans = m2;
		} else if (Function(m1, b, c) < Function(m2, b, c)) {
			e = m2;
			ans = m1;
		} else {
			s = e = m1;
			ans = m1;
		}
	}
	return ans;
}
int main() {

	int t;
	cin >> t;
	while (t--) {
		double b, c;
		cin >> b >> c;

		double ans = isThisJee2(b, c);
		cout << fixed << setprecision(9) << Function(ans, b, c) << endl;
	}

}