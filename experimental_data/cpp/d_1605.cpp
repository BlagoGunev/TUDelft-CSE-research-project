#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+10,mod=998244353,INF=0x3f3f3f3f;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
vector<int>e[N],t[2];
int T;
int n,f[N],g[N],val[N],tag[N],co[N];
V dfs(int u,int fa=0,int c=0){
	t[c].push_back(u);
	for(int v:e[u])if(v!=fa)
		dfs(v,u,!c);
}
V input(){
	n=getint(),t[0].clear(),t[1].clear();
	FOR(i,1,n)e[i].clear();
	FOR(i,2,n){
		int x=getint(),y=getint();
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1);
	if(t[0].size()>t[1].size())swap(t[0],t[1]);
	int p=0,q=0;
	FOR(i,0,19)
		if(t[0].size()>>i&1)
			FOR(j,0,(1<<i)-1)co[t[0][p++]]=1<<i|j;
		else{
			FOR(j,0,(1<<i)-1){
				if(q==t[1].size())break;
				co[t[1][q++]]=1<<i|j;
			}
		}
	FOR(i,1,n)cout<<co[i]<<" \n"[i==n];
}
V init(){
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}