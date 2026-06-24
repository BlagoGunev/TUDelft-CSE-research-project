// LUOGU_RID: 162597467
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,B=500,T=N/B+5;
typedef long long ll;
int test,n,q,a[N],p[N],qi[N],qx[N],nx[N],pn;
int pos[N],tg[T],mx[T],se[T],tgmx[T],sz[T],tp[N],c1[T],c2[T];
int buc[N<<1],*nw=buc;
pair<int,int>Buc[N<<2],*Nw=Buc;
int *b[T];
pair<int,int> *v1[T],*v2[T];
ll ans[N];
inline void pushdown(int o){
	if(!tg[o]&&!tgmx[o])return;
	for(int i=0,v;i<sz[o];++i){
		v=b[o][i];
		if(nx[v]==mx[o])nx[v]+=tgmx[o];
		nx[v]+=tg[o],tp[v]+=tg[o];
	}
	tg[o]=tgmx[o]=0;
}
inline void rebuild(int lx,int px,int o){
	mx[lx]=se[lx]=0;
	c1[lx]=c2[lx]=0;
	for(int i=0,v;i<sz[lx];++i){
		v=b[lx][i];
		if(v<px)nx[v]=min(nx[v],o);
		if(v>px)++nx[v],++tp[v];
		if(nx[v]>mx[lx])se[lx]=mx[lx],mx[lx]=nx[v];
		else if(nx[v]!=mx[lx]&&nx[v]>se[lx])se[lx]=nx[v];
	}
	for(int i=0,v;i<sz[lx];++i){
		v=b[lx][i];
		if(mx[lx]==nx[v])v1[lx][c1[lx]++]=make_pair(-tp[v],0);
		else v2[lx][c2[lx]++]=make_pair(nx[v]-tp[v],0);
	}
	sort(v1[lx],v1[lx]+c1[lx]);
	sort(v2[lx],v2[lx]+c2[lx]);
	for(int i=0;i<c1[lx];++i){
		v1[lx][i].second=v1[lx][i].first;
		if(i)v1[lx][i].second+=v1[lx][i-1].second;
	}
	for(int i=0;i<c2[lx];++i){
		v2[lx][i].second=v2[lx][i].first;
		if(i)v2[lx][i].second+=v2[lx][i-1].second;
	}
}
inline int calcpos(int o){
	int lx=pos[o],res=0;
	for(int i=1;i<lx;++i)res+=sz[i];
	for(int i=0;i<sz[lx];++i)if(b[lx][i]<o)++res;
	return res+1;
}
inline void ins(int x){
	int px=p[x],lx=pos[px];
	int o=calcpos(px);
	pushdown(lx);
	b[lx][sz[lx]++]=px;
	nx[px]=2*n,tp[px]=o;
	rebuild(lx,px,o);
	for(int i=lx+1;i<=pn;++i)if(sz[i])++tg[i];
	for(int i=1;i<lx;++i)if(sz[i]){
		if(se[i]&&o<=se[i]+tg[i]){
			pushdown(i);
			rebuild(i,px,o);
		}else if(o<mx[i]+tg[i]+tgmx[i])
			tgmx[i]=o-mx[i]-tg[i];
	}
}
inline int qry(int lx,int x){
	int res=0,v=mx[lx]+tgmx[lx];
	int o=lower_bound(v1[lx],v1[lx]+c1[lx],make_pair(x-v,0))-v1[lx];
	if(o)res+=v*o+v1[lx][o-1].second;
	res+=x*(c1[lx]-o);
	if(!c2[lx])return res;
	o=lower_bound(v2[lx],v2[lx]+c2[lx],make_pair(x,0))-v2[lx];
	if(o)res+=v2[lx][o-1].second;
	res+=x*(c2[lx]-o);
	return res;
}
inline ll Qry(int x){
	ll res=0;
	for(int i=1;i<=pn;++i)if(sz[i])res+=qry(i,x);
	return res;
}
void work(){
	for(int i=1;i<=pn;++i)tg[i]=tgmx[i]=sz[i]=0;
	for(int i=1,j=1;i<=n;++i){
		ins(i);
		while(j<=q&&qi[j]==i)ans[j]+=Qry(qx[j]),++j;
	}
}
void solve(){
	scanf("%d",&n);
	q=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		p[a[i]]=i,pos[i]=(i-1)/B+1;
	}
	pn=pos[n];
	for(int i=1,k;i<=n;++i){
		scanf("%d",&k);
		for(int j=1,x;j<=k;++j){
			scanf("%d",&x);
			++q,qx[q]=x,qi[q]=i;
			ans[q]=1-i-x;
		}
	}
	work();
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;++i)p[a[i]]=i;
	work();
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
}
int main(){
	for(int i=0;i<T;++i)b[i]=nw,nw+=B;
	for(int i=0;i<T;++i)v1[i]=Nw,Nw+=B,v2[i]=Nw,Nw+=B;
	scanf("%d",&test);
	while(test--)solve();
	return 0;
}