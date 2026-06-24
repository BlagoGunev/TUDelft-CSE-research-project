//#include<bits\stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<algorithm>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#define ll long long
#define db double
#define INF 1000000000
#define ldb long double
#define pb push_back
#define put_(x) printf("%d ",x);
#define get(x) x=read()
#define gt(x) scanf("%d",&x)
#define gi(x) scanf("%lf",&x)
#define put(x) printf("%d\n",x)
#define putl(x) printf("%lld\n",x)
#define gc(a) scanf("%s",a+1)
#define rep(p,n,i) for(RE int i=p;i<=n;++i)
#define go(x) for(int i=lin[x],tn=ver[i];i;tn=ver[i=nex[i]])
#define fep(n,p,i) for(RE int i=n;i>=p;--i)
#define pii pair<int,int>
#define mk make_pair
#define RE register
#define P 1000000007
#define S second
#define F first
#define gf(x) scanf("%lf",&x)
#define pf(x) ((x)*(x))
#define ull unsigned long long
#define ui unsigned
#define EPS 1e-8
#define mod 998244353
#define sq sqrt
using namespace std;
char buf[1<<15],*fs,*ft;
inline char getc()
{
    return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;
}
inline int read()
{
    RE int x=0,f=1;RE char ch=getc();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getc();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getc();}
    return x*f;
}
const int MAXN=200010;
int T;
int n;
int a[MAXN];
int main()
{
	//freopen("1.in","r",stdin);
	get(T);
	while(T--)
	{
		int cnt=0;
		get(n);
		rep(1,n,i)get(a[i]);
		sort(a+1,a+1+n);
		int now=0;
		rep(1,n,i)
		{
			++now;
			if(a[i]<=now)now=0,++cnt;
		}
		put(cnt);
	}
	return 0;
}