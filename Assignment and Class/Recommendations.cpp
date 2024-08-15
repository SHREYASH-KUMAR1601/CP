#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> t(n);

	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) cin >> t[i];

	map<ll, vector<ll>> mp;
	for (ll i = 0; i < n; i++) {
		mp[a[i]].push_back(i);
	}

	vector<ll> v;
	for (auto x : mp) v.push_back(x.first);
	sort(v.begin(), v.end());

	multiset<pair<ll, ll>, greater<pair<ll, ll>>> s;
	ll ans = 0;
	ll pos = v[0];

	while (true) {
		if (s.empty()) {
			auto it = lower_bound(v.begin(), v.end(), pos);
			if (it == v.end()) break;
			pos = *it;
		}

		for (auto x : mp[pos]) {
			s.insert({t[x], pos});
		}
		auto p = *(s.begin());
		s.erase(s.begin());
		ans += (pos - p.second) * p.first;
		pos++;
	}

	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
