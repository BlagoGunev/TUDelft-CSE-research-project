// Author -- Frame


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

#define Finline __inline__ __attribute__ ((always_inline))

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::queue;
using std::priority_queue;
using std::vector;
using std::sort;
using std::unique;
using std::reverse;

typedef long long ll;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>=b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<=b?1:a=b,0;}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=3005;
int h[N][N];
int _q[N],_l,_r;
int minn[N][N];
void gene(int n,int m)
{
	ll g0,x,y,z;
	read(g0,x,y,z);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			h[i][j]=g0;
			g0=(g0*x+y)%z;
		}
	}
}
void solve()
{
	int n,m,a,b;
	read(n,m,a,b);
	++n,--n;
	gene(n,m);
	int tmp=n;
	n-=tmp;
	n+=tmp;
	for(int i=1;i<=n;++i)
	{
		_l=1,_r=0;
		for(int j=1;j<b;++j)
		{
			while(_l<=_r&&h[i][_q[_r]]>h[i][j]) --_r;
			_q[++_r]=j;
		}
		for(int j=b;j<=m;++j)
		{
			while(_l<=_r&&h[i][_q[_r]]>h[i][j]) --_r;
			_q[++_r]=j;
			while(_l<=_r&&j-_q[_l]>=b) ++_l;
			minn[i][j]=h[i][_q[_l]];
		}
	}
	ll ans=0;
	for(int i=b;i<=m;++i)
	{
		_l=1,_r=0;
		for(register int j=1;j<a;++j)
		{
			while(_l<=_r&&minn[_q[_r]][i]>minn[j][i]) --_r;
			_q[++_r]=j;
		}
		for(register int j=a;j<=n;++j)
		{
			while(_l<=_r&&minn[_q[_r]][i]>minn[j][i]) --_r;
			_q[++_r]=j;
			while(_l<=_r&&j-_q[_l]>=a) ++_l;
			ans+=minn[_q[_l]][i];
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	solve();
	return 0;
}