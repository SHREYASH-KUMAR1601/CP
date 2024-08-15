#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {

	int n;
	cin >> n;

	vector<int>arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int count = 0;
	sort(arr.begin() , arr.end());

	for (int i = 0 ; i < n  ; i++) {
		count = count + abs((i + 1) - arr[i]);
	}

	cout << count << endl;

}