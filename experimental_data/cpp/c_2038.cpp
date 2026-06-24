// MagicDark
#include <bits/stdc++.h>
#define debug cerr << "\33[32m[" << __LINE__ << "]\33[m "
#define SZ(x) ((int) x.size() - 1)
#define all(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof x)
#define F(i, x, y) for (int i = (x); i <= (y); i++)
#define DF(i, x, y) for (int i = (x); i >= (y); i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> T& chkmax(T &x, T y) {return x = max(x, y);}
template <typename T> T& chkmin(T &x, T y) {return x = min(x, y);}
template <typename T> T& read(T &x) {
	x = 0; int f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = - f;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x *= f;
}
const int N = 2e5 + 10;
int n, a[N];
void zhk() {
	cin >> n;
	map <int, int> mp;
	F(i, 1, n) cin >> a[i], mp[a[i]]++;
	vector <int> g;
	for (auto [i, j]: mp)
		F(l, 1, j / 2) g.push_back(i);
	if (g.size() < 4) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << g[0] << " " << g[1] << " ";
		cout << g[0] << " " << g[SZ(g)] << " ";
		cout << g[SZ(g) - 1] << " " << g[1] << " ";
		cout << g[SZ(g) - 1] << " " << g[SZ(g)] << " ";
		cout << '\n';
	}
}
signed main() {
	ios::sync_with_stdio(0); // don't use puts
	cin.tie(0), cout.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) zhk();
	return 0;
}
/* why?
*/