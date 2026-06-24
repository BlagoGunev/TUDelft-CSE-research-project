#include <bits/stdc++.h>
	 
#define ll long long
#define pb push_back
#define pp pop_back
#define si size()
#define fi first
#define se second
#define pii pair <int, int>
#define pll pair <ll,ll>
#define ull unsigned long long
#define pdd pair <double,double>
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define N 110
#define inf 1000000009
#define str string
#define yarik short
#define elif else if
#define modw 1000000007
#define rt return 0;

using namespace std;

void boost()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

pii a[N];
int c[N], ans[N];
pii cc[N];

int main()
{
	boost();
	int n, k, m;
	cin >> n >> m >> k;
	int cnt = 0;
	forn(i, n)
	{
		cin >> a[i].se;
	}
	forn(i, n)
	{
		cin >> a[i].fi;
		cc[i + 1].fi = a[i].fi;
		cc[i + 1].se = a[i].se;
	}
	sort(a, a + N);
	reverse(a, a + N);
	for(int i = 0; i < N; i++)
	{
		ans[a[i].fi] = max(ans[a[i].fi], a[i].se);
	}
	for(int i = 0; i < k; i++)
	{
		cin >> c[i];
		if(ans[cc[c[i]].fi] != cc[c[i]].se)
			cnt++;
	}
	cout << cnt;
	return 0;
}