#include <bits/stdc++.h>
using namespace std;

#define ios				ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define all(x)			x.begin(), x.end()
#define pb				push_back
#define mp				make_pair
#define fi				first
#define se				second
#define bug(str, x)			cerr << str << " : " << x << '\n'

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
const int inf = 1e9 + 10;
const int mod = 1e9 + 7;

int main(){
	ios;
	int n;
	cin >> n;
	ll s = 0;
	for(int i = 0; i < n; i ++){
		ll h; cin >> h;
		s += h;
	}
	s -= 1ll * n * (n - 1) / 2;
	ll x = (s + n - 1) / n;
	int p = n * x - s;
	for(int i = 0; i < n; i ++)
		cout << x + i - (i >= n - p) << ' ';
	cout << '\n';
}