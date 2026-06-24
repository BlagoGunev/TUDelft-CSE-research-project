#include<bits/stdc++.h>

#define y0 pmtx
#define y1 pmtxx
#define x0 pmtxxx
#define x1 pmtxxxx
#define pb push_back
#define mp make_pair
#define fi first 
#define se second
#define DEBUG printf("Passing Line %d in function [%s].\n",__LINE__,__FUNCTION__)

using namespace std;

typedef pair<int ,int > pii;
typedef vector<int > vi;
typedef long long ll;
typedef unsigned long long ull;

namespace FastIO{
    const int SIZE=(1<<20);
    char in[SIZE],*inS=in,*inT=in+SIZE;
    inline char Getchar(){
        if(inS==inT){inT=(inS=in)+fread(in,1,SIZE,stdin);if(inS==inT)return EOF;}
        return *inS++;
    }
    char out[SIZE],*outS=out,*outT=out+SIZE;
    inline void Flush(){fwrite(out,1,outS-out,stdout);outS=out;}
    inline void Putchar(char c){*outS++=c;if(outS==outT)Flush();}
    struct NTR{~NTR(){Flush();}}ztr;
}

#ifndef LOCAL
    #define getchar FastIO::Getchar
    #define putchar FastIO::Putchar 
#endif

template<typename T> inline void read(T &x){
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    x*=f;
}

template<typename T>inline void write(T x){
    if(!x)putchar('0');
    if(x<0)x=-x,putchar('-');
    static int sta[40];int tot=0;
    while(x)sta[tot++]=x%10,x/=10;
    while(tot)putchar(sta[--tot]+48);
}
const int maxn=200007,INF=0x3f3f3f3f;
const ll MOD=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3fll;
const ll P=19260817;

template<typename T>inline void ckmax(T &x,T y){x=(y>x?y:x);}
template<typename T>inline void ckmin(T &x,T y){x=(y<x?y:x);}
template<typename T>inline T my_abs(T x){if(x<0)x=-x;return x;}
inline int mod1(int x){return x<MOD?x:x-MOD;}
inline int mod2(int x){return x<0?x+MOD:x;}
inline void add(int &x,int y){x=mod1(x+y);}
inline void sub(int &x,int y){x=mod2(x-y);}
int n;
int w[maxn];
// string s//;
vector<int > G[maxn];
// int ans;
int ind[maxn];
int d[maxn];
vi v;
void dfs(int u,int f){
	// if(G[u].size()>1)d[u]=max(w[u],w[f]);
	d[u]=w[f];
	for(auto v:G[u]){
		if(v!=f)dfs(v,u);
	}
}
int main(){
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
	int T;
	// scanf("%d",&T);
	read(T);
	while(T--){
		read(n);
		v.clear();
		ll ans=0;
		for(int i=1;i<=n;i++){
			ind[i]=0;
			read(w[i]);
			// G[i].clear();
			ans+=w[i];
		}
		for(int i=1,u,v;i<n;i++){
			read(u),read(v);
			ind[u]++,ind[v]++;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<ind[i];j++){
				v.pb(w[i]);
			}
		}
		sort(v.begin(),v.end(),greater<int >());
		write(ans);
		putchar(' ');
		for(int i=0;i<n-2;i++){
			ans+=v[i];
			write(ans);
			putchar(' ');
		}
		putchar('\n');
	}
    return 0;
}

//things to remember
//1.long long
//2.array length
//3.freopen
//4 boarder case