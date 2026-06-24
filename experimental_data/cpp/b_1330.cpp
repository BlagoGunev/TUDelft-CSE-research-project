//Head File
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<ctime>
#include<set>
#include<cstdlib>
#include<vector>
#include<cassert>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;

//Stand
#define il inline
#define ll long long

//Debug
#define B cerr<<"Break Point"<<endl;
#define P(x) cerr<<#x<<' '<<"="<<' '<<(x)<<endl;
#define p(x) cerr<<#x<<' '<<"="<<' '<<(x)<<' ';

//File
void fio()
{
    #ifndef ONLINE_JUDGE
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
    #endif
}
void pti()
{
    double timeuse = clock()*1000.0/CLOCKS_PER_SEC;
    cerr<<"Timeuse "<<timeuse<<"ms"<<endl;
}
void end()
{
    #ifndef ONLINE_JUDGE
    pti();
    #endif
    exit(0);
}

//IO
#define pc(s) putchar(s)
#define say(s) cout<<s<<endl
namespace io
{
    const int SIZ=55;int que[SIZ],op,qr;char ch;
    template<class I>
    il void gi(I &w)
    {
        ch=getchar(),op=1,w=0;
	    while(!isdigit(ch)){if(ch=='-') op=-1;ch=getchar();}
        while(isdigit(ch)){w=w*10+ch-'0';ch=getchar();}w*=op;
    }
    template<typename T,typename... Args>
    il void gi(T& t,Args&... args){gi(t);gi(args...);}
    template<class I>
    il void print(I w)
    {
        qr=0;if(!w) putchar('0');if(w<0) putchar('-'),w=-w;
	    while(w) que[++qr]=w%10+'0',w/=10;
        while(qr) putchar(que[qr--]);
    }
}
using io::gi;
using io::print;

const int N=2e5+5;

int T,n;
int a[N];
bool pre[N],suf[N],vis[N];

int main()
{
	fio();
	gi(T);
	while(T--)
	{
		gi(n);
		int maxx=0;
		for(int i=1;i<=n;++i) vis[i]=0,pre[i]=0,suf[i]=0;
		for(int i=1;i<=n;++i) gi(a[i]);
		for(int i=1;i<=n;++i)
		{
			maxx=max(maxx,a[i]);
			if(vis[a[i]]) break;
			vis[a[i]]=true;
			if(maxx==i) pre[i]=true;
		}
		maxx=0;
		for(int i=1;i<=n;++i) vis[i]=0;
		for(int i=n;i>=1;--i)
		{
			maxx=max(maxx,a[i]);
			if(vis[a[i]]) break;
			vis[a[i]]=true;
			if(maxx==n-i+1) suf[i]=true;
		}
		int res=0;
		for(int i=1;i<n;++i) if(pre[i]&&suf[i+1]) ++res;
		print(res),pc(10);
		for(int i=1;i<n;++i) if(pre[i]&&suf[i+1]) print(i),pc(' '),print(n-i),pc(10);
	}
	end();
}