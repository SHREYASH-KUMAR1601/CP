#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int len;
		cin >> len;
		string str;
		cin >> str;

		int flips = 0;
		if (str[0] == '0') flips++;
		if (str[len - 1] == '0') flips++;

		cout << min(len, flips) << '\n';
	}
	return 0;
}
