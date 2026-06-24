// LUOGU_RID: 157093665
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define L x<<1
#define R L|1
#define mid (l+r>>1)
#define lc L,l,mid
#define rc R,mid+1,r
#define OK Ll<=l&&r<=Rr
#define Root 1,1,n
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define repn(x) rep(x,1,n)
#define repm(x) rep(x,1,m)
#define pb push_back
#define e(x) for(int i=h[x],y=to[i];i;i=nxt[i],y=to[i])
#define E(x) for(auto y:p[x])
#define Pi pair<int,int>
#define ui unsigned ll
inline int read(){int s=0,w=1;char c=getchar();while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}while(c>=48&&c<=57)s=(s<<1)+(s<<3)+c-48,c=getchar();return s*w;}
inline void pf(ll x){if(x<0) putchar('-'),x=-x;if(x>9)pf(x/10);putchar(x%10+48);}
using namespace std;
const int N =3e5+5,M=1e6+5,inf=(1LL<<31)-1,mod=998244353;
const ll llf=1e18;
inline void add(int &a,int b){((a+=b)>=mod) and (a-=mod);}
inline int Add(int a,int b){return add(a,b),a;}
inline int mul(int a,int b){return 1LL*a*b%mod;}
inline void Mul(int &a,int b){a=mul(a,b);}
inline void red(int &a,int b){add(a,mod-b);}
inline int Red(int a,int b){return red(a,b),a;}
inline int qp(int a,int b){if(!b)return 1;int c=qp(a,b>>1);Mul(c,c);if(b&1)Mul(c,a);return c;}
inline int INV(int x){return qp(x,mod-2);}
int a[55][55],A[55],B[55];
int m,n,cst,s,t,h[N],nxt[M],to[M],d[N],cnt=1,pre[N],c[M],w[M],dis[N],ans;
bool vis[N];
void add_(int a,int b,int C,int cost){
	to[++cnt]=b;
	nxt[cnt]=h[a];
	h[a]=cnt;
	w[cnt]=C;
	c[cnt]=cost;//????? 
	
	to[++cnt]=a;
	nxt[cnt]=h[b];
	h[b]=cnt;
	w[cnt]=0;
	c[cnt]=-cost;//?????
}
bool spfa(){//spfa??????· 
	queue<int>q;
	q.push(s);
	rep(i,0,t) vis[i]=0,d[i]=100000000;
	vis[s]=1;d[s]=0;
	dis[s]=210000000;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=h[x];i;i=nxt[i]){
			int v=to[i];
			if(d[v]>d[x]+c[i]&&!w[i]==0){ 
				dis[v]=min(dis[x],w[i]);
				d[v]=d[x]+c[i];
				pre[v]=i;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return !(d[t]==100000000);
}
void exchange(){
	int x=t;
	while(x!=s){
		int y=pre[x]; 
		w[y]-=dis[t];
		w[y^1]+=dis[t];  
		x=to[y^1];
	}
	ans+=dis[t];
	cst+=d[t]*dis[t];
}
inline int id(int x,int y){
	return (x-1)*m+y;
}
inline int ida(int x){
	return x+n*m;
}
inline int idb(int x){
	return x+n*m+n;
}
int sum=0;
inline void Main(){
	n=read(),m=read();
	s=0,t=n*m+n+m+1;
	repn(i)repm(j)a[i][j]=read(),sum+=a[i][j];
	int sa=0,sb=0;
	repn(i)A[i]=read(),sa+=A[i];
	repm(i)B[i]=read(),sb+=B[i];
	if(sa!=sb)return cout <<"-1",void();
	repn(i){
		add_(s,ida(i),A[i],0);
		repm(j){
			if(a[i][j])add_(ida(i),id(i,j),1,-1);
			else add_(ida(i),id(i,j),1,1);
		}
	}
	repm(i){
		add_(idb(i),t,B[i],0);
		repn(j){
			add_(id(j,i),idb(i),1,0);
		}
	}
	while(spfa())exchange();
	if(ans==sa)cout <<sum+cst;
	else cout <<-1;
}
signed main(){
	int T=1;
	while(T--)Main(); 
	return 0;
}