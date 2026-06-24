#include <set>
#include <map>
#include <queue>
#include <ctime>
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define re(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define run(v) for(int k=head[v];k;k=e[k].ne)
#define ergo(p,x) for(int (p)=head[(x)];(p);(p)=ne[(p)])
#define Rep2(p,x) for(int (p)=cur[(x)];(p);(p)=ne[(p)])
//#define v e[k].t
#define clr(a) memset(a,0,sizeof(a));
#define il inline
#define sz(a) ((int)a.size())
#define pb push_back 
#define w1 first
#define w2 second
#define adm(a,b,c) {a=a+b;if(a>=c)a-=c;else if(a<0)a+=c;}
typedef pair<int,int> pa;
typedef long long ll;typedef long double ld;typedef unsigned long long ull;
const int N=5e5+5,M=2e6+5,INF=1e9,mod=1e9+7;
const ll linf=1e18;const double eps=1e-8,pi=acos(-1);
il int gmin(int &a,int b){if(a>b)a=b;}il ll gmin(ll &a,ll b){if(a>b)a=b;}il int gmax(int &a,int b){if(a<b)a=b;}il ll gmax(ll &a,ll b){if(a<b)a=b;}
il void read(ll&x){ll f=1,t=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){t=t*10+ch-'0';ch=getchar();}x=t*f;}il ll read(ll&x,ll&y){read(x);read(y);}
il void read(int&x){int f=1,t=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){t=t*10+ch-'0';ch=getchar();}x=t*f;}il int read(int&x,int&y){read(x);read(y);}
il void read(int&a,int&b,int&c){read(a);read(b);read(c);}il void read(ll&a,ll&b,ll&c){read(a);read(b);read(c);}
il int read(){int x;read(x);return x;}
il ll qpow(ll a,ll b,ll p){ll ret=1;for(;b;b>>=1,a=a*a%p)if(b&1)ret=ret*a%p;return ret;}il ll qpow(ll a,ll b){ll ret=1;for(;b;b>>=1,a=a*a%mod)if(b&1)ret=ret*a%mod;return ret;}
il ll qmul(ll a,ll b,ll p){ll ret=0;for(;b;b>>=1,a=(a<<1)%p)if(b&1)adm(ret,a,p);return ret;}il ll qmul(ll a,ll b){ll ret=0;for(;b;b>>=1,a=(a<<1)%mod)if(b&1)adm(ret,a,mod);return ret;}
int n,tot,flag,root;
int len[N];
int head[N],toit[N],ne[N];
int len2;
void adde(int x,int y){
	toit[++tot]=y;ne[tot]=head[x];head[x]=tot;
}il void judge(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);}
il void gen(){freopen("data.in","w",stdout);}
void dfs(int x,int fa){
	int ttt=1;len[x]=-1;
	ergo(p,x)if(toit[p]!=fa){
		ttt=0;
		dfs(toit[p],x);
		if(flag)return;
		if(len[x]==-1)len[x]=len[toit[p]]+1;
		else if(len[toit[p]]+1!=len[x]){flag=1;root=x;return;}
	}if(ttt)len[x]=0;
}
void dfs2(int x,int fa){
	int ttt=1;len[x]=-1;
	ergo(p,x)if(toit[p]!=fa){
		ttt=0;dfs2(toit[p],x);if(flag)return;
		if(len[x]==-1)len[x]=len[toit[p]]+1;
		else if(len[toit[p]]+1!=len[x]){
			if(x!=root){flag=1;return;}else{
				if(!len2)len2=len[toit[p]]+1;
				else if(len[toit[p]]+1!=len2){flag=1;return;}
			}
		}
	}if(ttt)len[x]=0;
}
int main(){
	read(n);
	rep(i,1,n-1){
		int x,y;read(x);read(y);
		adde(x,y);adde(y,x);
	}
	flag=0;dfs(1,0);
	if(!flag){int ans=len[1];while(ans%2==0)ans/=2;printf("%d\n",ans);return 0;}
	flag=0;dfs2(root,0);
	if(flag)return puts("-1"),0;
	int ans=len2+len[root];
	while((ans&1)==0)ans/=2;
	printf("%d\n",ans);
	return 0;
}