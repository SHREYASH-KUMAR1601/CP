#include <bits/stdc++.h>
using namespace std;
const int N = 0;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Person {
public:
	int t;
	int l;
	int h;

	Person(int x, int y, int z) {
		t = x;
		l = y;
		h = z;
	}
};

int main() {
	IOS;

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<Person> customer;
		for (int i = 0; i < n; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			customer.push_back(Person(a, b, c));
		}

		int curr_t = 0;
		int curr_temp_low = m;
		int curr_temp_high = m;
		bool possible = true;

		for (int i = 0; i < n; ++i) {
			int time_diff = customer[i].t - curr_t;

			int new_temp_low = curr_temp_low - time_diff;
			int new_temp_high = curr_temp_high + time_diff;

			int preferred_low = customer[i].l;
			int preferred_high = customer[i].h;

			new_temp_low = max(new_temp_low, preferred_low);
			new_temp_high = min(new_temp_high, preferred_high);

			if (new_temp_low > new_temp_high) {
				possible = false;
				break;
			}

			curr_t = customer[i].t;
			curr_temp_low = new_temp_low;
			curr_temp_high = new_temp_high;
		}

		if (possible) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
