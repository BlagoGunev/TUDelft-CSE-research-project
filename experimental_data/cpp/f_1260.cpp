/*
Author: QAQAutomaton
LANG: C++
PROG: F.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
	}
}__INIT___;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	inline bool read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}

	inline bool read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		x=gc();
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	// print a signed integer
	inline bool write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}

	inline bool write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) {
		putc(x);
		return 0;
	}
	inline bool write(const char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y){
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
int ans;
const int p=1000000007;
vector<int> to[100005];
int l[100005],r[100005];
int dep[100005];
int ls[6000005],rs[6000005],tag[6000005],t;
int sz[6000005],szt[6000005],wx[6000005],wy[6000005];
const int N=100000;
int rt[100005];
int inv[100005];
int insert(int la,int ra,int l,int r,int w,int w2){
	int rt=++t;	
	if(l<=la && ra<=r){
		sz[rt]=(ll)(ra-la+1)*w2%p;szt[rt]=w2;
		tag[rt]=(ll)w*w2%p;
		wx[rt]=(ll)tag[rt]*(ra-la+1)%p;
		wy[rt]=(ll)szt[rt]*(ra-la+1)%p;
		return rt;
	}
	int mid=(la+ra)>>1;
	if(l<=mid)rt[ls]=insert(la,mid,l,r,w,w2);
	if(mid<r)rt[rs]=insert(mid+1,ra,l,r,w,w2);
	szt[rt]=tag[rt]=0;
	sz[rt]=(rt[ls][sz]+rt[rs][sz])%p;
	rt[wx]=(rt[ls][wx]+rt[rs][wx])%p;
	rt[wy]=(rt[ls][wy]+rt[rs][wy])%p;
	return rt;
}
void merge(int &r1,int &r2,int xt,int yt,int dis,int siz){
	if(!r2){ans=(ans+(r1[wx]-(ll)r1[wy]*dis%p+p)*yt)%p;return;}
	if(!r1){ans=(ans+(r2[wx]-(ll)r2[wy]*dis%p+p)*xt)%p;r1=r2;return;}
	ans=(ans+(ll)(r1[tag]-(ll)r1[szt]*dis%p+p)*((ll)yt*(siz+1)%p+sz[r2]))%p;
	ans=(ans+(ll)(r2[tag]-(ll)r2[szt]*dis%p+p)*((ll)xt*(siz+1)%p+sz[r1]))%p;
	merge(r1[ls],r2[ls],(xt+szt[r1])%p,(yt+szt[r2])%p,dis,siz>>1);
	merge(r1[rs],r2[rs],(xt+szt[r1])%p,(yt+szt[r2])%p,dis,siz-(siz>>1)-1);
	(sz[r1]+=sz[r2])%=p;(tag[r1]+=tag[r2])%=p;
	(szt[r1]+=szt[r2])%=p;
	(wx[r1]+=wx[r2])%=p;
	(wy[r1]+=wy[r2])%=p;
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	rt[x]=insert(1,N,l[x],r[x],dep[x],inv[r[x]-l[x]+1]);
	for(auto i:to[x])if(i!=f){
		dfs(i,x);
		merge(rt[x],rt[i],0,0,dep[x],N-1);
	}
}
signed main(){
#ifdef QAQAutoMaton 
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int n,u,v;
	read(n);
	inv[1]=1;
	for(int i=2;i<=N;++i)inv[i]=(ll)(p-p/i)*inv[p%i]%p;
	for(int i=1;i<=n;++i)read(l[i],r[i]);
	for(int i=1;i<n;++i){
		read(u,v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)ans=(ll)ans*(r[i]-l[i]+1)%p;
	write(ans,'\n');
	return 0;

}