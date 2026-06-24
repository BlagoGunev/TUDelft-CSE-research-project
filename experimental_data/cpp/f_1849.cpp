// LUOGU_RID: 159240027
#include<bits/stdc++.h>
#define N 500005
//#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
#define gc() getchar()
#define fi first
#define se second
//#define CHECK_MEMORY ___JQH___
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=1e9;
const ll INF=2e18;
bool Memory_Begin;
namespace IO{const int SIZE=(1<<21)+1;char ibuf[SIZE],*iS,*iT,obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1,c,qu[55];int f,qr;inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf,fflush(stdout);}inline void putc(char x){*oS++=x;if(oS==oT)flush();}template <class I>inline void read(I &x){for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;}template <class I>inline void print(I x){if(!x)putc('0');if(x<0)putc('-'),x=-x;while(x)qu[++qr]=x%10+'0',x/=10;while(qr)putc(qu[qr --]);}inline void reads(string &s){s.clear();for(c=gc();c<33||c>126;)c=gc();for(;c>=33&&c<=126;c=gc())s.push_back(c);}inline void prints(string s){for(char c:s)putc(c);}struct Flusher_ {~Flusher_(){flush();}}io_flusher_;}
using IO::read;using IO::putc;using IO::print;using IO::reads;using IO::prints;
template<class I>I updiv(I x,I y){return (x%y==0?x/y:x/y+1);}
template<class I>bool cmin(I &x,I y){if(x>y)return x=y,1;return 0;}
template<class I>bool cmax(I &x,I y){if(x<y)return x=y,1;return 0;}

int n,col[N],ans[N];
pii a[N];
vector<int>s[N];
void add(int x,int y)
{
	s[x].push_back(y);
	s[y].push_back(x);
}
int flag;
void dfs(int x,int Col)
{
	col[x]=Col;
	for(int y:s[x])
	{
		if(!col[y]) dfs(y,-Col);
		else if(col[x]==col[y]) flag=0;
	}
}
bool check(int mid)
{
	for(int i=1;i<=n;i++) s[i].clear(),col[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=min(n,i+3);j++)
			if((a[i].fi^a[j].fi)<mid) add(i,j);
	flag=1;
	for(int i=1;i<=n;i++) if(!col[i]) dfs(i,1);
	return flag;
}
bool Memory_End;
signed main()
{
#ifdef CHECK_MEMORY
	cerr<<"Memory: "<<(&Memory_End-&Memory_Begin)/1048576.0<<" MiB\n";
#endif
	read(n);
	for(int i=1;i<=n;i++) read(a[i].fi),a[i].se=i;
	if(n==2) return print(10),0;
	sort(a+1,a+n+1);
	int l=0,r=(1<<30)-1,res=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) res=mid,l=mid+1;
		else r=mid-1;
	}
	check(res);
	for(int i=1;i<=n;i++) ans[a[i].se]=(col[i]==1);
	for(int i=1;i<=n;i++) print(ans[i]);
	return 0;
}