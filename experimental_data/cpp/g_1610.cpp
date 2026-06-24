// Fresh Peach Heart Shower
#include <bits/stdc++.h>
#define reg
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
const int MaxN=3e5+50;
char s[MaxN];
int nxt[MaxN],n;
inline int cmp(int x,int y) // don't know what complex , used hash is ok
{
	while(x<=n&&y<=n&&s[x]==s[y])x=nxt[x+1],y=nxt[y+1];
	if(x<=n&&y<=n)return s[x]<=s[y];
	return x>n&&y<=n;
}
signed main(void) // copied from froggy
{
	std::scanf("%s",s+1),n=std::strlen(s+1);
	std::stack<int> st;
	st.push(n+1);
	rep(i,1,n+1)nxt[i]=i;
	per(i,n,1)if(s[i]==')')st.push(i);
		else
		{
			st.pop();
			if(st.empty())st.push(i);
			else if(cmp(i,st.top()))st.top()=i;
			else nxt[i]=st.top();
		}
	for(int i=1;i<=n;i=nxt[i+1])std::putchar(s[i]);
	ln;
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