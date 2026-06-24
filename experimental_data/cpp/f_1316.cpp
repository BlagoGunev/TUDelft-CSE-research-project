#include<bits/stdc++.h>

using namespace std;

const int maxn=600005;

const int mod=(1e9+7);

int n,m,i,j,t,k,s,ls[maxn],tls,a[maxn],b[maxn];

int pla[maxn],chg[maxn],two[maxn];

int sum[maxn<<2],cnt[maxn<<2],lef[maxn<<2],rig[maxn<<2];



inline int Pow(int x,int y)

{

	int ret=1;

	while (y)

	{

		if (y&1) ret=1ll*ret*x%mod;

		x=1ll*x*x%mod;y>>=1;

	}return ret;

}

inline void re_new(int rt,int v,int c)

{

	if (c==0)

	{

		sum[rt]=lef[rt]=rig[rt]=0;cnt[rt]=1;

	}

	else

	{

		sum[rt]=v*1ll*v%mod*(c*1ll*two[c-1]%mod-two[c]+mod+1)%mod;

		lef[rt]=rig[rt]=v*1ll*(two[c]-1)%mod;

		cnt[rt]=two[c];

	}

}

inline void pushup(int rt)

{

	sum[rt]=(sum[rt<<1]*1ll*cnt[rt<<1|1]+sum[rt<<1|1]*1ll*cnt[rt<<1]+lef[rt<<1]*1ll*rig[rt<<1|1])%mod;

	cnt[rt]=cnt[rt<<1]*1ll*cnt[rt<<1|1]%mod;

	lef[rt]=(lef[rt<<1]+lef[rt<<1|1]*1ll*cnt[rt<<1])%mod;

	rig[rt]=(rig[rt<<1|1]+rig[rt<<1]*1ll*cnt[rt<<1|1])%mod;

}



void build(int rt,int l,int r)

{

	if (l==r)

	{

		re_new(rt,ls[r],b[r]);

		return;

	}

	int mid=(l+r)>>1;

	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);

	pushup(rt);

}

void upd(int rt,int l,int r,int pl)

{

	if (l==r){re_new(rt,ls[r],b[r]);return;}

	int mid=(l+r)>>1;

	if (pl>mid) upd(rt<<1|1,mid+1,r,pl);

	else upd(rt<<1,l,mid,pl);

	pushup(rt);

}



int main()

{

	two[0]=1;

	for (i=1;i<maxn;++i) two[i]=2*two[i-1]%mod;

	scanf("%d",&n);

	for (i=1;i<=n;++i) scanf("%d",&a[i]),ls[i]=a[i];

	scanf("%d",&m);

	for (i=1;i<=m;++i)

	{

		scanf("%d%d",&pla[i],&chg[i]);

		ls[n+i]=chg[i];

	}

	sort(ls+1,ls+n+m+1);tls=1;

	for (i=2;i<=n+m;++i) if (ls[i]^ls[tls]) ls[++tls]=ls[i];

	for (i=1;i<=n;++i)

	{

		b[a[i]=lower_bound(ls+1,ls+tls+1,a[i])-ls]++;

	}

	build(1,1,tls);

	int mul=Pow(2,mod-1-n);

	printf("%lld\n",sum[1]*1ll*mul%mod);

	for (i=1;i<=m;++i)

	{

		chg[i]=lower_bound(ls+1,ls+tls+1,chg[i])-ls;

		--b[a[pla[i]]];upd(1,1,tls,a[pla[i]]);

		++b[chg[i]];upd(1,1,tls,chg[i]);

		a[pla[i]]=chg[i];

		printf("%lld\n",sum[1]*1ll*mul%mod);

	}

	return 0;

}