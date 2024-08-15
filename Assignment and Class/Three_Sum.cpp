#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		int cnt[10] = {0};		//Frequency array
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			int digit = a[i] % 10;
			cnt[digit]++;
		}
		vector<int>v;		//Expand frequency array
		for (int i = 0 ; i < 10; i++) {
			for (int j = 0 ; j < min(3, cnt[i]) ; j++) {
				v.push_back(i);
			}
		}
		int flag = 0;
		for (int i = 0 ; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				for (int k = j + 1; k < v.size(); k++) {
					if ((v[i] + v[j] + v[k]) % 10 == 3) {
						flag = 1;
						cout << "Yes" << endl;
						break;
					}
				}
				if (flag == 1) {
					break;
				}
			}
			if (flag == 1) {
				break;
			}
		}

		if (flag == 0) {
			cout << "No" << endl;
		}

	}
}