#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
const ll inf=2e18;
const int maxn=500005;
typedef pair<ll,int>pii;
#define fi first
#define se second
priority_queue<pii>f;
vector<int>G[maxn]; 
int n,fa[20][maxn],p;
ll val[maxn],res;
inline void solve(int u) {
	for(int i=0;i<(int)G[u].size();++i) {
		int v=G[u][i];
		if(v==fa[0][u])
			continue;
		fa[0][v]=u;
		for(int j=1;j<20;++j)
			fa[j][v]=fa[j-1][fa[j-1][v]];
		ll sum=inf;
		for(int j=19;~j;--j)
			sum=min(sum,val[v]+(j+1)*(fa[j][v]?val[fa[j][v]]:val[p]));
		f.push(pii(-sum,v)); 
	}
}
inline void inite() {
	for(int i=1,u,v;i<n;++i)
		read(u),read(v),G[u].push_back(v),G[v].push_back(u);
}
inline void initp() {
	read(n);
	for(int i=1;i<=n;++i)
		read(val[i]);
}
int main() {
	initp(),p=min_element(val+1,val+n+1)-val,f.push(pii(0,p)),inite();
	while(!f.empty()){pii now=f.top();f.pop();res+=now.fi;solve(now.se);}
	printf("%lld\n",-res);
}