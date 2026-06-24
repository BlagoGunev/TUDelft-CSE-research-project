#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string(string(s)); }
string to_string(bool b) { return to_string(int(b)); }
string to_string(vector<bool>::reference b) { return to_string(int(b)); }
string to_string(char b) { return "'" + string(1, b) + "'"; }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename T = typename A::value_type>
string to_string(A v) {
	string res = "{";
	for (const auto& x : v) res += (res == "{" ? "" : ", ") + to_string(x);
	return res + "}";
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug(T...);
}
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define db(...) 42
#endif
using ll = long long;
using ld = long double;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, r;
		cin >> n >> r;
		vector<int> A(n);
		for (int& a : A) cin >> a;
		int ans = 0, singles = 0;
		for (int a : A) {
			ans += a / 2 * 2;
			singles += a % 2;
			r -= a / 2;
		}
		assert(2 * r >= singles);
		if (singles > r) {
			ans += 2 * r - singles;
		} else {
			ans += singles;
		}
		cout << ans << '\n';
	}
}