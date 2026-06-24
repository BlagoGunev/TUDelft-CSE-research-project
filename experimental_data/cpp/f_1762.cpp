// LUOGU_RID: 100080306
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=500021;

int f[maxn],a[maxn];int n,K;

int T;int mx=100002;ll ans;

namespace SEG

{

	#define lson(p) ((p)<<1)

	#define rson(p) ((p)<<1|1)

	int sz[maxn*4],mn[maxn*4];

	void build(int l,int r,int p)

	{

		sz[p]=0,mn[p]=0x3f3f3f3f;

		if(l==r) return sz[p]=0,mn[p]=0x3f3f3f3f,void();

		int mid=(l+r)>>1;

		build(l,mid,lson(p)); build(mid+1,r,rson(p));

	}

	void update(int l,int r,int x,int s,int v,int p)

	{

		if(l==r) return sz[p]+=s,mn[p]=v,void();

		int mid=(l+r)>>1;

		if(x<=mid) update(l,mid,x,s,v,lson(p));

		else update(mid+1,r,x,s,v,rson(p));

		sz[p]=sz[lson(p)]+sz[rson(p)];

		mn[p]=min(mn[lson(p)],mn[rson(p)]); 

	}

	int query1(int l,int r,int x,int y,int p)

	{

		if(x<=l&&y>=r) return mn[p];

		int mid=(l+r)>>1;

		int ret=0x3f3f3f3f;

		if(x<=mid) ret=min(ret,query1(l,mid,x,y,lson(p)));

		if(y>mid) ret=min(ret,query1(mid+1,r,x,y,rson(p)));

		return ret;

	}

	int query2(int l,int r,int x,int y,int p)

	{

		if(x<=l&&y>=r) return sz[p];

		int mid=(l+r)>>1;int ret=0;

		if(x<=mid) ret+=query2(l,mid,x,y,lson(p));

		if(y>mid) ret+=query2(mid+1,r,x,y,rson(p));

		return ret; 

	}

}

int cnt[maxn];

void solve()

{

	for(int i=n;i>=1;i--)

	{

		SEG::update(1,mx,a[i],1,i,1);

		int j=SEG::query1(1,mx,a[i]+1,min(a[i]+K,mx),1);

		if(j>n) {f[i]=0;continue;}

		f[i]=f[j]+SEG::query2(1,mx,a[i]+1,a[j],1);

		ans+=f[i];

	}

	for(int i=1;i<=n;i++) 

		SEG::update(1,mx,a[i],-1,0x3f3f3f3f,1);

	reverse(a+1,a+1+n);

	for(int i=n;i>=1;i--)

	{

		SEG::update(1,mx,a[i],1,i,1);

		int j=SEG::query1(1,mx,a[i]+1,min(a[i]+K,mx),1);

		if(j>n) {f[i]=0;continue;}

		f[i]=f[j]+SEG::query2(1,mx,a[i]+1,a[j],1);

		ans+=f[i];

	}

	for(int i=1;i<=n;i++) 

		SEG::update(1,mx,a[i],-1,0x3f3f3f3f,1);

	for(int i=1;i<=n;i++) cnt[a[i]]++,ans+=cnt[a[i]];

	for(int i=1;i<=n;i++) cnt[a[i]]=0;

}

void cytakioi()

{

	scanf("%d%d",&n,&K);

	for(int i=1;i<=n;i++)

		scanf("%d",&a[i]);

	solve();

	printf("%lld\n",ans);

	ans=0;

}

int main()

{

	//freopen("p.in","r",stdin);

	scanf("%d",&T); SEG::build(1,mx,1);

	while(T--) cytakioi();

}