// Fresh Peach Heart Shower
#include <bits/stdc++.h>
#define reg
#define ALL(x) (x).begin(),(x).end()
#define mem(x,y) memset(x,y,sizeof x)
#define sz(x) (int)(x).size()
#define ln putchar('\n')
#define lsp putchar(32)
#define pb push_back
#define MP std::make_pair
#define MT std::make_tuple
#ifdef _LOCAL_
#define dbg(x) std::cerr<<__func__<<"\tLine:"<<__LINE__<<' '<<#x<<": "<<x<<"\n"
#define dprintf(x...) std::fprintf(stderr,x)
#else
#define dbg(x) 42
#define dprintf(x...) 42
#endif
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
typedef std::pair<int,int> pii;
typedef std::vector<int> poly;
template <class t> inline void read(t &s){s=0;
signed f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();;s*=f;}
template<class t,class ...A> inline void read(t &x,A &...a){read(x);read(a...);}
template <class t> inline void write(t x){if(x<0)putchar('-'),x=-x;
static int buf[50],top=0;while(x)buf[++top]=x%10,x/=10;if(!top)buf[++top]=0;
while(top)putchar(buf[top--]^'0');}
inline void setIn(std::string s){freopen(s.c_str(),"r",stdin);return;}
inline void setOut(std::string s){freopen(s.c_str(),"w",stdout);return;}
inline void setIO(std::string s=""){setIn(s+".in");setOut(s+".out");return;}
template <class t>inline bool ckmin(t&x,t y){if(x>y){x=y;return 1;}return 0;}
template <class t>inline bool ckmax(t&x,t y){if(x<y){x=y;return 1;}return 0;}
inline int lowbit(int x){return x&(-x);}
#define fi first
#define se second
const int MaxN=(1<<16)|5;
const int p=998244353;
inline int fpow(int a,int b)
{
	int ret=1;
	for(;b;b>>=1,a=1LL*a*a%p)if(b&1)ret=1LL*ret*a%p;
	return ret;
}
struct CC
{
	int f[MaxN],inv[MaxN],Inv[MaxN];
	CC()
	{
		f[0]=1;
		rep(i,1,MaxN-1)f[i]=1LL*f[i-1]*i%p;
		inv[MaxN-1]=fpow(f[MaxN-1],p-2);
		per(i,MaxN-2,0)inv[i]=1LL*inv[i+1]*(i+1)%p;
		Inv[0]=1;
		rep(i,1,MaxN-1)Inv[i]=1LL*f[i-1]*inv[i]%p;
	}
}C;
inline void fwt(poly &a,int op)
{
	int n=a.size();
	for(int mid=1;mid<n;mid<<=1)for(int j=0;j<n;j+=(mid<<1))rep(k,0,mid-1)
	{
		int x=a[j+k],y=a[j+k+mid];
		(a[j+k]=x+y)>=p&&(a[j+k]-=p),(a[j+k+mid]=x+p-y)>=p&&(a[j+k+mid]-=p);
	}
	if(op<0)
	{
		int inv=fpow(n,p-2);
		for(auto &i:a)i=1LL*i*inv%p;
	}
}
inline poly Ln(poly &a)
{
	if(a.size()<=1u)return poly();
	int n=a.size();
	poly ret(n);
	rep(i,1,n-1)
	{
		int s=0;
		rep(j,1,i-1)s=(s+1LL*a[j]*ret[i-j]%p*(i-j))%p;
		ret[i]=(a[i]+p-1LL*s*C.Inv[i]%p)%p;
	}
	return ret;
}
inline poly Exp(poly &a)
{
	if(a.size()<=1u)return poly({1});
	int n=a.size();
	poly ret(n);
	ret[0]=1;
	rep(i,1,n-1)
	{
		int s=0;
		rep(j,0,i-1)s=(s+1LL*ret[j]*a[i-j]%p*(i-j))%p;
		ret[i]=1LL*s*C.Inv[i]%p;
	}
	return ret;
}
int A[MaxN],n,K,c;
poly lg[MaxN];
inline poly Mul(poly a,poly b)
{
	poly ret(K+1);
	rep(i,0,K)rep(j,0,K-i)ret[i+j]=(ret[i+j]+1LL*a[i]*b[j])%p;
	return ret;
}
signed main(void)
{
	int Sxor=0;read(n,K,c);
	std::map<poly ,int> S;
	rep(i,1,n)
	{
		read(A[i]),Sxor^=A[i];
		poly msk;
		rep(j,1,K)msk.pb(A[i]^(A[i]-j));
		++S[msk];
	}
	rep(i,0,(1<<K)-1)
	{
		poly f(K+1);
		f[0]=1;
		rep(j,0,K-1)if(i>>j&1)f[j+1]=(p-C.inv[j+1])%p;
			else f[j+1]=C.inv[j+1];
		lg[i]=Ln(f);
	}
	std::vector<std::pair<poly,int> > Dr;
	for(auto i:S)Dr.pb(i);
	poly ret(1<<c),cnt(1<<K);
	rep(t,0,(1<<c)-1)
	{
		poly st;
		for(auto i:Dr)
		{
			int mask=0;
			rep(j,0,K-1)if(__builtin_parity(i.fi[j]&t))mask|=1<<j;
			if(!cnt[mask])st.pb(mask);
			cnt[mask]+=i.se;
		}
		poly dp(K+1);dp[0]=1;
		for(auto i:st)
		{
			poly cur=lg[i];
			rep(j,0,K)cur[j]=1LL*cur[j]*cnt[i]%p;
			dp=Mul(dp,Exp(cur));
		}
		ret[t]=1LL*dp[K]*C.f[K]%p;
		for(auto i:st)cnt[i]=0;
	}
	fwt(ret,-1);
	int inv=fpow(n,p-1-K);
	rep(i,0,(1<<c)-1)write(1LL*ret[i^Sxor]*inv%p),lsp;ln;
	return 0;
}

/*
 * Check List:
 * 1. Input / Output File (OI)
 * 2. long long 
 * 3. Special Test such as n=1
 * 4. Array Size
 * 5. Memory Limit (OI) int is 4 and longlong is 8
 * 6. Mod (a*b%p*c%p not a*b*c%p  ,  (a-b+p)%p not a-b )
 * 7. Name ( int k; for(int k...))
 * 8. more tests , (T=2 .. more)
 * 9. blank \n after a case
*/