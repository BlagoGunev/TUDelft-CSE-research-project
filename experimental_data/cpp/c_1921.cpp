# include <iostream>
# include <algorithm>
#define endl '\n'
using namespace std;
const int N = 200010;
typedef long long LL;
LL p[N];
LL n, f, a, b;

void solve()
{
	cin >> n >> f >> a >> b;
	for (int i = 1; i <= n; i ++) cin >> p[i];
	
	LL res = 0;
	for (int i = 1; i <= n; i ++)
		res += min((p[i] - p[i - 1]) * a, b);
	//cout << res << ' ';
	cout << ((res < f) ? "YES" : "NO") << endl;
	return;
}

int main()
{
	int t;
	cin >> t;
	while(t --)
		solve();

	return 0;
}