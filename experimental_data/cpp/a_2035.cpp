#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,del##i##verme=int(n);i<del##i##verme;++i)
#define rep1(i,n) for(int i=1,parano##i##a=int(n);i<=parano##i##a;++i)
#define per(i,n) for(int i=int(n)-1;i>=0;--i)
#define per1(i,n) for(int i=int(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define y0 LingLuo
#define y1 VividCycle
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
unsigned time_related_rand()
{
	return unsigned(std::chrono::steady_clock::now().time_since_epoch().count());
}
int t;ll n,m,c,r;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>r>>c;
		cout<<(m-c)+(n-r)*(2*m-1)<<'\n';
	}
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not ?????? or few affect?
*/