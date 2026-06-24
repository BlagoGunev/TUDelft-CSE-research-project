#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define FILL(a,x) memset(a,x,sizeof(a))
#define foreach( gg,ii ) for( typeof(gg.begin()) ii=gg.begin();ii!=gg.end();ii++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sz(a) int((a).size())
#define N 100010
#define MAX 30
#define mod 1000000007
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define all(a) a.begin(),a.end()
const ll INF = 1e18+1;

inline ll input(void)
{
	char t;
	ll x=0;
	int neg=0;
	t=getchar();
	while((t<48 || t>57) && t!='-')
		t=getchar();
	if(t=='-')
		{neg=1; t=getchar();}
	while(t>=48 && t<=57)
	{
		x=(x<<3)+(x<<1)+t-48;
		t=getchar();
	}
	if (neg) x=-x;
	return x;
}

inline void output(ll x)
{
	char a[20];
	int i=0,j;
	a[0]='0';
	if (x<0) {putchar('-'); x=-x;}
	if (x==0) putchar('0');
	while(x)
	{
		a[i++]=x%10+48;
		x/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		putchar(a[j]);
	}
	putchar('\n');
}

ll power(ll a, ll b, ll m)
{
	ll ans=1;
	while(b)
	{
		if (b%2) ans*=a;
		b/=2;
		a*=a;
		if (a>=m) a%=m;
		if (ans>=m) ans%=m;
	}
	return ans;
}

ll a[N],q1[N],q2[N],good[N];
char s[N],t[N];

int main()
{
	ll n,lent,x=1,map=0,curr=0;
	scanf("%s%s",s,t);
	n=strlen(s);
	lent=strlen(t);
	REP(i,lent-1) x=(x*27)%mod;
	FILL(good,0);
	REP(i,lent) map=(27*map+t[i]-'a'+1)%mod;
	REP(i,lent) curr=(27*curr+s[i]-'a'+1)%mod;
	REPP(i,lent,n)
	{
		if (curr==map) good[i-1]=1;
		curr=(curr+(mod-x)*(s[i-lent]-'a'+1))%mod;
		curr=(27*curr+s[i]-'a'+1)%mod;
	}
	if (curr==map) good[n-1]=1;
	//REP(i,n) if (good[i]) output(i+1);
	if (good[0]) a[0]=1;
	else a[0]=0;
	q1[0]=a[0];
	q2[0]=a[0];
	REPP(i,1,n)
	{
		if (!good[i]) a[i]=a[i-1];
		else a[i]=(q2[i-lent]+i-lent+2)%mod;
		q1[i]=(q1[i-1]+a[i])%mod;
		q2[i]=(q2[i-1]+q1[i])%mod;
	}
	output(q1[n-1]);
return 0;
}