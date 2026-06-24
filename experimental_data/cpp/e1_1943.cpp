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
		int m, k;
		cin >> m >> k;
		vector<int> F(m + 1);
		for (int& f : F) cin >> f;
		int mex;
		for (mex = 1; mex <= m + 1; ++mex) {
			vector<int> A(F.begin(), F.begin() + mex);
			sort(A.begin(), A.end());
			bool bad = false;
			ll total = 0, sum = k;
			for (int i = 1; i < mex; ++i) {
				auto B = A;
				for (int turn = 1; turn <= i; ++turn) {
					// Only turn..i remaining.
					B[turn - 1] = 0;
					int rem = k;
					for (int j = i; j >= 1; --j) {
						int delta = B[i] - B[j - 1];
						ll maxTake = (ll)delta * (i - j + 1);
						if (rem >= maxTake) {
							for (int t = j; t <= i; ++t) B[t] = B[j - 1];
							rem -= maxTake;
						} else {
							for (int t = j; t <= i; ++t) {
								B[t] -= rem / (i - j + 1);
								if (t - j < rem % (i - j + 1)) B[t]--;
							}
							break;
						}
					}
				}
				if (B[i] == 0) bad = true;
			}
			if (bad) break;
		}
		cout << mex - 1 << '\n';
	}
}