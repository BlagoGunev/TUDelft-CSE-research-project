// Fresh Peach Heart Shower

#include <bits/stdc++.h>

#define reg

#define int long long 

#define ALL(x) (x).begin(),(x).end()

#define mem(x,y) memset(x,y,sizeof x)

#define ln putchar('\n')

#define lsp putchar(32)

#define pb push_back

#define MP std::make_pair

#ifdef _LOCAL_

#define dprintf(x...) std::fprintf(stderr,x)

#else

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

const int MaxN=2e5+50;

int a[MaxN],s[MaxN],up[19][MaxN];

signed main(void)

{

	int n,m;read(n,m);

	rep(i,1,n)read(a[i]),++s[a[i]];

	rep(i,1,m)s[i]+=s[i-1];

	rep(k,1,18)for(int i=1;i+(1<<k)-1<=m;++i)

		up[k][i]=up[k-1][i]^up[k-1][i+(1<<~-k)]^(((s[i+(1<<k)-1]^s[i+(1<<~-k)-1])&1)<<~-k);

	int q,l,r;read(q);

	while(q--)

	{

		read(l,r);

		int ans=0;

		per(k,18,0)if(l+(1<<k)<=r)ans^=up[k][l]^(((s[r]^s[l+(1<<k)-1])&1)<<k),l+=(1<<k);

		std::putchar(ans?'A':'B');

	}ln;

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