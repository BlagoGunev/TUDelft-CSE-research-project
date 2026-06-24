// Fresh Peach Heart Shower

#include <bits/stdc++.h>

#define reg

#define int long long 

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

int f[45][2][2],w[45];

inline int solve(int n,int x,int y)

{

	int g=std::__gcd(x,y);

	if(g>1)return solve(n/g+1,x/g,y/g)*(n%g)+solve(n/g,x/g,y/g)*(g-n%g);

	int m=x+y;

	rep(i,0,m-1)w[i]=(n-i+m-1)/m;

	std::mem(f,0);

	f[0][1][1]=w[0];

	rep(i,1,m-1)

	{

		int v=w[i*x%m];

		if(i<m-1)f[i][1][1]=f[i-1][0][1]+v;

		f[i][0][1]=std::max(f[i-1][0][1],f[i-1][1][1]);

		f[i][0][0]=std::max(f[i-1][0][0],f[i-1][1][0]);

		f[i][1][0]=f[i-1][0][0]+v;

	}

	return std::max({f[m-1][0][0],f[m-1][0][1],f[m-1][1][0],w[0]});

}

signed main(void)

{

	int n,x,y;read(n,x,y),write(solve(n,x,y)),ln;

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