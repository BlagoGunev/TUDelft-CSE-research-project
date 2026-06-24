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

#define fr first

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

struct Node{

	int x,y;

}a[maxn];

struct Limit{

	int p,t,l;

}b[maxn];

int n,m,R,B,ls[maxn],h,w;

int cntx[maxn],cnty[maxn],lx[maxn],ly[maxn],rx[maxn],ry[maxn];

int d[maxn<<1];

int cnt,to[650000],nx[650000],cap[650000],hd[maxn<<1];

void addedge(int u,int v,int l,int r){

	d[u]-=l,d[v]+=l;

	to[cnt]=v;nx[cnt]=hd[u];cap[cnt]=r-l;hd[u]=cnt++;

	to[cnt]=u;nx[cnt]=hd[v];cap[cnt]=0;  hd[v]=cnt++;

}

int S,T,head,tail,que[maxn<<1];

int dep[maxn<<1];

bool bfs(){

	head=1,tail=0;

	que[++tail]=S;

	memset(dep,-1,sizeof dep);

	dep[S]=1;

	while (head<=tail){

		int u=que[head++];

		cross(i,u){

			int v=to[i];

			if (cap[i]&&dep[v]==-1){

				dep[v]=dep[u]+1;

				if (v==T) return 1;

				que[++tail]=v;

			}

		}

	}

	return 0;

}

int dfs(int u,int f){

	if (u==T||!f) return f;

	int ret=0,flow;

	cross(i,u){

		int v=to[i];

		if (dep[v]==dep[u]+1&&(flow=dfs(v,min(f,cap[i])))!=0){

			ret+=flow,f-=flow;

			cap[i]-=flow,cap[i^1]+=flow;

			if (!f) break;

		}

	}

	if (!ret) dep[u]=-1;

	return ret; 

}

int maxflow(){

	int ret=0,f;

	while (bfs()) while ((f=dfs(S,inf))!=0) ret+=f;

	return ret;

}

int id[maxn];

int main(){

//	freopen("color.in","r",stdin);

//	freopen("color.out","w",stdout);

	n=rd(),m=rd();

	R=rd(),B=rd();//if (R>B) swap(R,B);

	rep(i,1,n) a[i].x=rd(),a[i].y=rd();

	rep(i,1,m) b[i].p=rd(),b[i].t=rd(),b[i].l=rd();

	rep(i,1,n) ls[i]=a[i].x;

	sort(ls+1,ls+n+1);

	h=unique(ls+1,ls+n+1)-ls-1;

	rep(i,1,n) a[i].x=lower_bound(ls+1,ls+h+1,a[i].x)-ls;

	rep(i,1,m) if (b[i].p==1){

		int ps=lower_bound(ls+1,ls+h+1,b[i].t)-ls;

		if (ls[ps]!=b[i].t) b[i].t=-1;

			else b[i].t=ps;

	}

	rep(i,1,n) ls[i]=a[i].y;

	sort(ls+1,ls+n+1);

	w=unique(ls+1,ls+n+1)-ls-1;

	rep(i,1,n) a[i].y=lower_bound(ls+1,ls+w+1,a[i].y)-ls;

	rep(i,1,m) if (b[i].p==2){

		int ps=lower_bound(ls+1,ls+w+1,b[i].t)-ls;

		if (ls[ps]!=b[i].t) b[i].t=-1;

			else b[i].t=ps;

	}

	rep(i,1,n) cntx[a[i].x]++,cnty[a[i].y]++;

	rep(i,1,h) lx[i]=0,rx[i]=cntx[i];

	rep(i,1,w) ly[i]=0,ry[i]=cnty[i];

	rep(i,1,m){

		if (b[i].t==-1) continue;

		if (b[i].p==1){

			int hs=b[i].t,l=b[i].l,nn=cntx[hs];

			lx[hs]=max(lx[hs],(nn-l)&1?(nn-l+1)/2:(nn-l)/2);

			rx[hs]=min(rx[hs],(nn+l)/2);

		}

		else{

			int hs=b[i].t,l=b[i].l,nn=cnty[hs];

			ly[hs]=max(ly[hs],(nn-l)&1?(nn-l+1)/2:(nn-l)/2);

			ry[hs]=min(ry[hs],(nn+l)/2);

		}

	}

	rep(i,1,h) if (lx[i]>rx[i]) return puts("-1"),0;

	rep(i,1,w) if (ly[i]>ry[i]) return puts("-1"),0;

	S=h+w+1,T=h+w+2;

	memset(hd,-1,sizeof hd);

	rep(i,1,h) addedge(S,i,lx[i],rx[i]);

	rep(i,1,w) addedge(h+i,T,ly[i],ry[i]);

	rep(i,1,n) id[i]=cnt,addedge(a[i].x,h+a[i].y,0,1);

	addedge(T,S,0,inf);

	S=h+w+3,T=h+w+4;

	int sumd=0;

	rep(i,1,h+w+2){

		if (d[i]>0) addedge(S,i,0,d[i]),sumd+=d[i];

		if (d[i]<0) addedge(i,T,0,-d[i]);

	}

	int ans=maxflow();

	if (ans!=sumd) return puts("-1"),0;

	S=h+w+1,T=h+w+2;

	ans=maxflow();

	if (R<B){

		rt((ll)R*ans+(ll)B*(n-ans)),putchar('\n');

		rep(i,1,n) if (cap[id[i]]) putchar('b');else putchar('r');

	}

	else{

		rt((ll)B*ans+(ll)R*(n-ans)),putchar('\n');

		rep(i,1,n) if (cap[id[i]]) putchar('r');else putchar('b');

	}

}