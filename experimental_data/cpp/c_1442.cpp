#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2,fma")



#include<bits/stdc++.h>

#define itn int

#define ll long long

#define fi first

#define se second

#define pb push_back

using namespace std;



ll read(){

	ll a=0;bool b=0;char c=getchar();

	while(c>'9'||c<'0')b^=(c=='-'),c=getchar();

	while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();

	return b?-a:a;

}

const int N=200005;

const ll mod=998244353;

struct edge{

	int v,nx;

}e[2*N];

int hd[N],hr[N],cnt,n,m;

ll b[N];

int vi[N][2];



struct pir{

	int u;

	ll d,le;

}a[N][2];

bool operator<(pir a,pir b){

	return a.d==b.d?a.le>b.le:a.d>b.d;

}

bool operator>(pir a,pir b){

	return b<a;

}



void dij(){

	priority_queue<pir>q;q.push(pir{n,0,0});

	for(int i=1;i<n;i++)a[i][0]=a[i][1]=pir{i,100000000,10000000};

	a[n][0]=a[n][1]=pir{n,0,0};

	memset(vi,0,sizeof vi);

	while(q.size()){

		pir o=q.top();q.pop();

		int u=o.u;

		if(vi[u][o.d&1])continue;

		vi[u][o.d&1]=1;

		int nd=(o.d&1)?o.d+1:o.d;

		for(int j=hd[u];j;j=e[j].nx){

			pir w=pir{e[j].v,nd,o.le+1};

			if(a[e[j].v][!(nd&1)]<w){

				a[e[j].v][!(nd&1)]=w;q.push(w);

			}

		}

		nd=(o.d&1)?o.d:o.d+1;

		for(int j=hr[u];j;j=e[j].nx){

			pir w=pir{e[j].v,nd,o.le+1};

			if(a[e[j].v][!(nd&1)]<w){

				a[e[j].v][!(nd&1)]=w;q.push(w);

			}

		}

	}

	

	q.push(pir{n,0,0});

	memset(vi,0,sizeof vi);

	while(q.size()){

		pir o=q.top();q.pop();

		int u=o.u;

		if(vi[u][!(o.d&1)])continue;

		vi[u][!(o.d&1)]=1;

		int nd=(o.d&1)?o.d:o.d+1;

		for(int j=hd[u];j;j=e[j].nx){

			pir w=pir{e[j].v,nd,o.le+1};

			if(a[e[j].v][nd&1]<w){

				a[e[j].v][nd&1]=w;q.push(w);

			}

		}

		nd=(o.d&1)?o.d+1:o.d;

		for(int j=hr[u];j;j=e[j].nx){

			pir w=pir{e[j].v,nd,o.le+1};

			if(a[e[j].v][nd&1]<w){

				a[e[j].v][nd&1]=w;q.push(w);

			}

		}

	}

//	for(int i=1;i<=n;i++)cout<<i<<" : "<<a[i][0].d<<' '<<a[i][0].le<<' '<<a[i][1].d<<' '<<a[i][1].le<<'\n';

}

struct node{

	ll u,l;

};

bool operator<(node a,node b){

	return a.l>b.l;

}

int v[N];



int main(){

	n=read(),m=read();

	for(int i=1;i<=m;i++){

		int u=read(),v=read();

		e[++cnt]=edge{v,hd[u]},hd[u]=cnt;

		e[++cnt]=edge{u,hr[v]},hr[v]=cnt;

	}

	dij();

	for(int i=1;i<=n;i++)b[i]=1e18;

	ll ans=1e18,g=0;

	ll as1=1e18,as2=1e18;

	b[1]=0;

	for(int k=0;k<20;k++){

		priority_queue<node>q;

		for(int i=1;i<=n;i++)q.push(node{i,b[i]}),v[i]=0;

		while(q.size()){

			node o=q.top();q.pop();

			int u=o.u;

			if(v[u])continue;

			v[u]=1;

			if(k&1){

				for(int j=hr[u];j;j=e[j].nx){

					if(b[e[j].v]>b[u]+1){

						b[e[j].v]=b[u]+1;q.push(node{e[j].v,b[e[j].v]});

					}

				}

			}else{

				for(int j=hd[u];j;j=e[j].nx){

					if(b[e[j].v]>b[u]+1){

						b[e[j].v]=b[u]+1;q.push(node{e[j].v,b[e[j].v]});

					}

				}

			}

		}

	//	for(int i=1;i<=n;i++)cout<<b[i]<<' ';puts("");

		for(int i=1;i<=n;i++)if(b[i]<1e9){

			if(as1>a[i][k&1].d+k||(as1==a[i][k&1].d+k&&as2>b[i]+a[i][k&1].le)){

				as1=a[i][k&1].d+k,as2=b[i]+a[i][k&1].le;

			}

		}

		if(b[n]<1e9){

			ans=min(ans,(1<<k)-1+b[n]);

			g=1;

		}

	}

	if(g)cout<<ans%mod<<'\n';

	else{

		ans=1;

		for(int i=1;i<=as1;i++)ans=ans*2%mod;

		ans=(ans-1+as2+mod)%mod;

		cout<<ans<<'\n';

	}

	return 0;

}