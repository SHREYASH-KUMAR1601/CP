#include <bits/stdc++.h>
using namespace std;

namespace std {

template <int D, typename T>
struct Vec : public vector < Vec < D - 1, T >> {
	static_assert(D >= 1, "Dimension must be positive");
	template <typename... Args>
	Vec(int n = 0, Args... args) : vector < Vec < D - 1, T >> (n, Vec < D - 1, T > (args...)) {}
};

template <typename T>
struct Vec<1, T> : public vector<T> {
	Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};

template <class Fun>
class y_combinator_result {
	Fun fun_;

public:
	template <class T>
	explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

	template <class... Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template <class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

}  // namespace std

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int xc, yc, k;
		cin >> xc >> yc >> k;

		int half = k / 2;
		for (int i = 0; i < half; ++i) {
			cout << xc - i - 1 << ' ' << yc << '\n';
			cout << xc + i + 1 << ' ' << yc << '\n';
		}
		if (k % 2 == 1) {
			cout << xc << ' ' << yc << '\n';
		}
	}

	return 0;
}
