#include <bits/stdc++.h>

using namespace std;

#define res(x,y) (((x)%(y))+(y))%(y)
#define rep(x, y) for(int x=0;x<y;x++)
#define sqr(x) ((x)*(x))
#define scan(x) scanf("%d", &x)
#define print(x) printf("%d\n", x)

#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE

#define pb(x) push_back(x)
#define mp(x, y) make_pair(x,y)
#define F first
#define S second
#define mod 1000000007

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

int n, m;

void out(int k)
{
	if (k <= m) printf("%d ", k);
}

int main()
{
	scanf("%d %d", &n, &m);
	int j = 2;
	for(int i=1;i<=2*n;i+=2)
	{
		out(2*n+i); out(i); out(2*n+j); out(j);
		j+=2;
	}
	printf("\n");
	return 0;
}