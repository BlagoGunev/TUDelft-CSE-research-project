//by yjz

#include<bits/stdc++.h>

using namespace std;

#define FF first

#define SS second

#define PB push_back 

#define MP make_pair

typedef long long ll;

const ll INF=1<<28;

const ll LINF=1ll<<61;

//My own input/output stream

#define geti(x) x=getnum()

#define getii(x,y) geti(x),geti(y)

#define getiii(x,y,z) getii(x,y),geti(z)

#define puti(x) putnum(x),putsp()

#define putii(x,y) puti(x),putnum(y),putsp()

#define putiii(x,y,z) putii(x,y),putnum(z),putsp()

#define putsi(x) putnum(x),putendl()

#define putsii(x,y) puti(x),putnum(y),putendl()

#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()

inline ll getnum()

{

	register ll r=0;register bool ng=0;register char c;c=getchar();

	while(c!='-'&&(c<'0'||c>'9'))c=getchar();

	if(c=='-')ng=1,c=getchar();

	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();

	if(ng)r=-r;return r;

}

template <class T> inline void putnum(T x)

{

	if(x<0)putchar('-'),x=-x;

	register short a[20]={},sz=0;

	while(x>0)a[sz++]=x%10,x/=10;

	if(sz==0)putchar('0');

	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);

}

inline void putsp(){putchar(' ');}

inline void putendl(){putchar('\n');}

inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}

int n;

pair<ll,ll> a[100111];

ll pmx[100111],pmn[100111];

ll smx[100111],smn[100111];

ll querylen(int x,int y)

{

	if(x>y)return 0;

	else return max(pmx[x-1],smx[y+1])-min(pmn[x-1],smn[y+1]);

}

ll querymx(int x,int y)

{

	if(x>y)return 0;

	else

	{

		ll t=max(max(pmx[x-1],smx[y+1]),-min(pmn[x-1],smn[y+1]));

		return t*t;

	}

}

bool check(ll len)

{

//	cout<<"check:"<<len<<endl;

	ll L=sqrt(len);

	while(L*L<=len)L++;

	while(L*L>len)L--;

	int l=n,r=1;

	for(int i=1;i<=n;i++)

	{

		if(a[i].FF>=-L&&a[i].FF<=L)

		{

			l=min(l,i);

			r=max(r,i);

		}

	}

	int it=l;

	for(int i=l;i<=r;i++)

	{

		if(a[i].FF>0)break;

		while(it<=r&&a[it].FF<=a[i].FF+L&&a[it].FF<=-a[i].FF)it++;

		while(a[it-1].FF>-a[i].FF)it--;

		if(querylen(i,it-1)<=L&&(querymx(i,it-1)+a[i].FF*a[i].FF)<=len)return true;

	}

	it=r;

	for(int i=r;i>=l;i--)

	{

		if(a[i].FF<0)break;

		while(it>=l&&a[it].FF>=a[i].FF-L&&a[it].FF>=-a[i].FF)it--;

		while(a[it+1].FF<-a[i].FF)it++;

		if(querylen(it+1,i)<=L&&(querymx(it+1,i)+a[i].FF*a[i].FF)<=len)return true;

	}

	return false;

}

int main()

{

	geti(n);

	ll tmx1=-(1ll<<60),tmn1=-tmx1;

	ll tmx2=tmx1,tmn2=tmn1;

	for(int i=1;i<=n;i++)

	{

		getii(a[i].FF,a[i].SS);

		tmx1=max(tmx1,a[i].FF);

		tmn1=min(tmn1,a[i].FF);

		tmx2=max(tmx2,a[i].SS);

		tmn2=min(tmn2,a[i].SS);

	}

	sort(a+1,a+n+1);

	pmx[0]=smx[n+1]=-(1ll<<60);

	pmn[0]=smn[n+1]=1ll<<60;

	for(int i=1;i<=n;i++)pmx[i]=max(pmx[i-1],a[i].SS),pmn[i]=min(pmn[i-1],a[i].SS);

	for(int i=n;i>=1;i--)smx[i]=max(smx[i+1],a[i].SS),smn[i]=min(smn[i+1],a[i].SS);

	ll l=0,r=1ll<<60;

	while(l<=r)

	{

		ll m=l+r>>1;

		if(check(m))r=m-1;

		else l=m+1;

	}

	cout<<min(min((tmx1-tmn1)*(tmx1-tmn1),(tmx2-tmn2)*(tmx2-tmn2)),l)<<endl;

	return 0;

}