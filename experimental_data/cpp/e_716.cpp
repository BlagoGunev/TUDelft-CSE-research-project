#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cctype>

#include<ctime>

#include<cstdlib>

#include<string>

#include<queue>

#include<cmath>

#include<set>

#include<map>

#include<bitset>

#include<vector>

#define rep(x,a,b) for (int x=a;x<=(int)b;x++)

#define drp(x,a,b) for (int x=a;x>=(int)b;x--)

#define cross(x,a) for (int x=hd[a];~x;x=nx[x])

#define ll long long

#define inf (1<<29)

#define PII pair<int,int>

#define PDD pair<double,double>

#define mk(a,b) make_pair(a,b)

#define fs first

#define sc second

#define pb push_back

using namespace std;

inline ll rd(){

	ll x=0;int ch=getchar(),f=1;

	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();

	if (ch=='-'){f=-1;ch=getchar();}

	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}

	return x*f;

}

inline void rt(ll x){

	if (x<0) putchar('-'),x=-x;

	if (x>=10) rt(x/10),putchar(x%10+'0');

		else putchar(x+'0');

}

const int maxn=100005;

int n,mod,pw[maxn],inv[maxn];

int to[maxn<<1],nx[maxn<<1],hd[maxn],cnt,dig[maxn<<1];

void addedge(int u,int v,int w){

	to[cnt]=v;nx[cnt]=hd[u];dig[cnt]=w;hd[u]=cnt++;

}

void exgcd(int a,int b,int &x,int &y){

	if (!b) return x=1,y=0,void();

	exgcd(b,a%b,x,y);

	int t=x;x=y,y=t-a/b*y;

}

int getinv(ll a){

	int x,y;

	exgcd(a,mod,x,y);

	return (x%mod+mod)%mod;

}

int size[maxn],vis[maxn],tim;

bool del[maxn];

void getsize(int u,int fa){

	size[u]=1;

	cross(i,u){

		int v=to[i];

		if (v==fa||del[v]) continue;

		getsize(v,u);

		size[u]+=size[v];

	}

}

int head,tail,que[maxn];

ll zds=0;

int findcenter(int x){

	getsize(x,-1);

	zds+=size[x];

	head=1,tail=0,que[++tail]=x;

	int mn=size[x]+1,root=x;

	vis[x]=++tim;

	while (head<=tail){

		int u=que[head++],mx=size[x]-size[u];

		cross(i,u){

			int v=to[i];

			if (del[v]||vis[v]==tim) continue;

			mx=max(mx,size[v]);

			que[++tail]=v;vis[v]=tim;

		}

		if (mx<mn) mn=mx,root=u;

	}

	return root;

}

vector<PII>fwd,tfw;

vector<int>rev,trv;

int fw[maxn],rv[maxn],len[maxn];

ll ans;

#define hm 10000007

int hhd[hm],hto[maxn],hnx[maxn],hcnt,htim,hst[hm],hnum[maxn];

void insert(int a,int b){

	if (hst[a]!=htim) hhd[a]=-1,hst[a]=htim;

	for (int i=hhd[a];~i;i=hnx[i]) if (hto[i]==b) return hnum[i]++,void();

	hto[hcnt]=b;hnx[hcnt]=hhd[a];hnum[hcnt]=1;hhd[a]=hcnt++;

}

int find(int a,int b){

	if (hst[a]!=htim) return hhd[a]=-1,0;

	for (int i=hhd[a];~i;i=hnx[i]) if (hto[i]==b) return hnum[i];

	return 0;

}

void conquer(int x){

	int cen=findcenter(x);

	del[cen]=1;

	fwd.clear(),rev.clear();

	cross(i,cen){

		int v=to[i];

		if (del[v]) continue;

		head=1,tail=0,que[++tail]=v;

		fw[v]=rv[v]=dig[i]%mod;len[v]=1;

		vis[v]=++tim;

		trv.clear(),tfw.clear();

		while (head<=tail){

			int u=que[head++];

			tfw.pb(mk(fw[u],len[u])),trv.pb(rv[u]);

			fwd.pb(mk(fw[u],len[u])),rev.pb(rv[u]);

			cross(i,u){

				int v=to[i];

				if (del[v]||vis[v]==tim) continue;

				len[v]=len[u]+1;

				fw[v]=((ll)fw[u]*10+dig[i])%mod;

				rv[v]=(rv[u]+(ll)dig[i]*pw[len[u]]%mod),rv[v]-=rv[v]>=mod?mod:0;

				que[++tail]=v;vis[v]=tim;

			}

		}

		++htim;hcnt=0;

		rep(j,0,trv.size()-1) insert((ll)trv[j]*233%hm,trv[j]);

		rep(j,0,tfw.size()-1){

			int num=(ll)(mod-tfw[j].fs)*inv[tfw[j].sc]%mod;

			ans-=find((ll)num*233%hm,num);

		}

	}

	++htim;hcnt=0;

	rep(j,0,rev.size()-1) insert((ll)rev[j]*233%hm,rev[j]);

	ans+=find(0,0);

	rep(j,0,fwd.size()-1){

		if (!fwd[j].fs) ans++;

		int num=(ll)(mod-fwd[j].fs)*inv[fwd[j].sc]%mod;

		ans+=find((ll)num*233%hm,num);

	}

	cross(i,cen){

		int v=to[i];

		if (!del[v]) conquer(v);

	}

}

int main(){

	n=rd(),mod=rd();

	pw[0]=1;rep(i,1,n) pw[i]=(ll)pw[i-1]*10%mod;

	inv[0]=1;inv[1]=getinv(pw[1]);

	rep(i,2,n) inv[i]=(ll)inv[i-1]*inv[1]%mod;

	memset(hd,-1,sizeof hd);

	rep(i,1,n-1){

		int u=rd(),v=rd(),w=rd();

		addedge(u,v,w),addedge(v,u,w);

	}

	conquer(0);

	rt(ans),putchar('\n');

}