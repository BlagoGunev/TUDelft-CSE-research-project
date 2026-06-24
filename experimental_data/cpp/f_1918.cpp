#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define il inline
#define pii pair<int,int>
#define x first
#define y second
#define gc getchar()
#define rd read()
#define debug() puts("------------")

namespace yzqwq{
	il int read(){
		int x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=gc;}
		while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc;
		return x*f;
	}
	il int qmi(int a,int b,int p){
		int ans=1;
		while(b){
			if(b&1) ans=ans*a%p;
			a=a*a%p,b>>=1;
		}
		return ans;
	}
	il auto max(auto a,auto b){return (a>b?a:b);}
	il auto min(auto a,auto b){return (a<b?a:b);}
	il int gcd(int a,int b){
		if(!b) return a;
		return gcd(b,a%b);
	}
	il int lcm(int a,int b){
		return a/gcd(a,b)*b;
	}
	il void exgcd(int a,int b,int &x,int &y){
		if(!b) return x=1,y=0,void(0);
		exgcd(b,a%b,x,y);
		int t=x;
		x=y,y=t-a/b*x;
		return ;
	}
	mt19937 rnd(time(0));
}
using namespace yzqwq;

const int N=1e6+10;
int ne[N<<1],e[N<<1],h[N],idx;
int n,k,dep[N],mdep[N],cnt,tim;
priority_queue<int> Q;

il void add(int a,int b){
	ne[++idx]=h[a],e[idx]=b,h[a]=idx;
}
il void dfs1(int now,int fa){
	dep[now]=dep[fa]+1,mdep[now]=dep[now];
	for(re int i=h[now];i;i=ne[i]){
		int j=e[i];
		dfs1(j,now),mdep[now]=max(mdep[now],mdep[j]);
	}
	return ;
}
il void dfs2(int now,int x){
	priority_queue<pii,vector<pii>,greater<pii>> qu;
	for(re int i=h[now];i;i=ne[i]){
		int j=e[i];
		qu.push({mdep[j],j});
	}
	while(!qu.empty()){
		pii noww=qu.top();qu.pop();
		int j=noww.y;
		dfs2(j,x);
		tim+=2;
		if(now==1&&qu.empty()) tim-=mdep[now]-dep[1];
		if(!qu.empty()){
			if(mdep[j]-dep[now]-dep[now]+dep[1]>0) Q.push(mdep[j]-dep[now]-dep[now]+dep[1]);
		}
	}
	return ;
}

il void solve(){
	n=rd,k=rd;
	for(re int i=2;i<=n;++i) add(rd,i);
	dfs1(1,0),dfs2(1,0);
	while(cnt<k&&!Q.empty()){
		tim-=Q.top();Q.pop();
		++cnt;
	}
	cout<<tim;
	return ;
}

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int t=1;while(t--)
	solve();
	return 0;
}