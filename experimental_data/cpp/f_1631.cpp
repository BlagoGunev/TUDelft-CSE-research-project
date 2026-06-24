#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<climits>
//#define NDEBUG
#include<cassert>
#include<cstring>
#include<complex>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<bitset>
//#define LL __int128
#define LL long long
#define uint unsigned int
#define ULL unsigned LL
//#define int LL
//#define double long double
#define mkp make_pair
#define par pair<int,int>
#define psb push_back
#define epb emplace_back
#define f(x) ((x).first)
#define s(x) ((x).second)
using namespace std;
#define Lbt(x) ((x)&(-(x)))
#define Swap(x,y) (x^=y^=x^=y)
const int Mxxx=1e5;
inline char gc()
{
	static char buf[Mxxx],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxxx,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool fl=false)
{
	static char buf[Mxxx],*p1=buf,*p2=buf+Mxxx;
	return (fl||((*p1++=ch)&&p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
//#define gc getchar
//#define pc(x,y) y?0:(putchar(x),0)
#define output pc('!',true)
inline int read()
{
	char ch=gc();
	int gans=0,gflag=0;
	for(;ch<'0'||'9'<ch;gflag|=ch=='-',ch=gc());
	for(;'0'<=ch&&ch<='9';gans=(gans<<1)+(gans<<3)+(ch^48),ch=gc());
	return gflag?-gans:gans;
}
template<typename T>
inline char read(T&gans)
{
	char ch=gc();
	int gflag=0;gans=0;
	for(;ch<'0'||'9'<ch;gflag|=ch=='-',ch=gc());
	for(;'0'<=ch&&ch<='9';gans=(gans<<1)+(gans<<3)+(ch^48),ch=gc());
	return gans=gflag?-gans:gans,ch;
}
template<typename T>
inline void write(T x)
{
	if(x>9)write(x/10);
	pc(x%10^48);
}
template<typename T>
inline void writenum(T x,char ch)
{
	if(x<0)pc('-'),x=-x;
	write(x);pc(ch);
}
inline void writechar(char x,char ch)
{
	pc(x);pc(ch);
}
template<typename T>
inline T Max(T x,T y)
{
	return x>y?x:y;
}
template<typename T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
template<typename T>
inline T Abs(T x)
{
	return x<0?-x:x;
}
template<typename T>
inline void ckmx(T&x,T y)
{
	x=Max(x,y);
}
template<typename T>
inline void ckmn(T&x,T y)
{
	x=Min(x,y);
}
const int Mx=1e6;
int TT,n,m,a[Mx+5],mnn[Mx+5],mxx[Mx+5],flg[Mx+5],tot[Mx+5];
inline int Gcd(int x,int y)
{
	return !y?x:Gcd(y,x%y);
}
LL ans;
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	#endif
	int i,g,x;LL sm1,sm2;
	for(TT=read();TT;TT--)
	{
		n=read();m=read();
		for(i=1;i<=n;i++)a[i]=read();
		for(g=0,i=1;i<=m;i++)g=g?Gcd(g,read()):read();
		assert(g);
		for(i=0;i<g;i++)mnn[i]=INT_MAX,mxx[i]=INT_MIN,flg[i]=tot[i]=0;
		for(ans=0,i=1;i<=n;i++)
		{
			x=i%g;
			flg[x]|=!a[i];
			tot[x]+=a[i]<0;
			a[i]=Abs(a[i]);
			ckmn(mnn[x],a[i]);
			ckmx(mxx[x],a[i]);
			ans+=a[i];
		}
		for(sm1=sm2=i=0;i<g;i++)
		{
			if(flg[i])continue;
			if(tot[i]&1)sm1+=mnn[i];else sm2+=mnn[i];
		}
		ans-=Min(sm1,sm2)<<1;
		writenum(ans,10);
	}
	return output;
}
/*
3
6 2
0 6 -2 1 -4 5
1 2
7 1
1 -1 1 -1 1 -1 1
2
5 1
-1000000000 -1000000000 -1000000000 -1000000000 -1000000000
1
*/