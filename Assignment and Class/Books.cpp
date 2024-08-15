#include<bits/stdc++.h>
using namespace std;

int main() {

	int n , t;
	cin >> n >> t;

	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Bruteforce Approach - O(n2)

	// int ans = INT_MIN;

	// for (int i = 0; i < n; ++i)
	// {
	// 	int count = 0;
	// 	int temp = t;
	// 	for (int j = i; j < n; ++j)
	// 	{
	// 		if (a[j] > temp) {
	// 			break;
	// 		}
	// 		temp = temp - a[j];
	// 		count++;
	// 	}

	// 	ans = max(ans, count);
	// }

	// cout << ans << endl;


	//Sliding Window - O(n)

	int ans = 0, count = 0, currentTime = 0, left = 0;
	for (int right = 0; right < n; right++) {
		currentTime += a[right];
		count++;
		while (currentTime > t) {
			currentTime -= a[left];
			left++;
			count--;
		}
		ans = max(ans, count);
	}

	cout << ans << endl;
}