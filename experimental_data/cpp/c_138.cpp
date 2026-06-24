#include<bits/stdc++.h>

using namespace std;

int n,m;

int a[100010]={};

int b[100010]={};

int lf[100010]={};

int rf[100010]={};

struct pp{

	int b,z;

} mo[10010]={};

bool cmp(pp x,pp y)

{

	return x.b<y.b;

}

double la[400010]={};

void build(int o,int l,int r)

{

	if(l==r)

	{

		la[o]=1.0;

		return;

	}

	int mid=(l+r)/2;

	build(o*2,l,mid);

	build(o*2+1,mid+1,r);

	la[o]=1.0;

}

void pushdown(int o)

{

	la[o*2]*=la[o];

	la[o*2+1]*=la[o];

	la[o]=1.0;

}

void update(int o,int l,int r,int ll,int rr,int x)

{

	if(ll<=l&&r<=rr)

	{

		la[o]*=(x*1.0)/100;

		return;

	}

	pushdown(o);

	int mid=(l+r)/2;

	if(ll<=mid) update(o*2,l,mid,ll,rr,x);

	if(rr>=mid+1) update(o*2+1,mid+1,r,ll,rr,x);

}

double ff(int o,int l,int r,int x)

{

	if(l==r&&x==l)

	{

		return la[o];

	}

	pushdown(o);

	int mid=(l+r)/2;

	if(x<=mid)  return ff(o*2,l,mid,x);

	if(x>=mid+1) return ff(o*2+1,mid+1,r,x);

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++) scanf("%d%d%d%d",&a[i],&b[i],&lf[i],&rf[i]);

	for(int i=1;i<=m;i++)

	{

		scanf("%d%d",&mo[i].b,&mo[i].z);

	}

	sort(mo+1,mo+m+1,cmp);

	build(1,1,m);

	int l,r;

	for(int i=1;i<=n;i++)

	{

		int p=a[i]-b[i];

		l=1;

		r=m;

		while(l<r)

		{

			int mid=(l+r)/2;

			if(mo[mid].b>=p) r=mid;

			else l=mid+1;

		}

		if(mo[l].b<p) continue;

		int zz=l;

		p=a[i]-1;

		l=1;

		r=m;

		while(l<r)

		{

			int mid=(l+r)/2+1;

			if(mo[mid].b<=p) l=mid;

			else r=mid-1;

		}

		if(mo[l].b>p) continue;

		int yy=l;

		update(1,1,m,zz,yy,100-lf[i]);

	}

	for(int i=1;i<=n;i++)

	{

		int p=a[i]+1;

		l=1;

		r=m;

		while(l<r)

		{

			int mid=(l+r)/2;

			if(mo[mid].b>=p) r=mid;

			else l=mid+1;

		}

		if(mo[l].b<p) continue;

		int zz=l;

		p=a[i]+b[i];

		l=1;

		r=m;

		while(l<r)

		{

			int mid=(l+r)/2+1;

			if(mo[mid].b<=p) l=mid;

			else r=mid-1;

		}

		if(mo[l].b>p) continue;

		int yy=l;

		update(1,1,m,zz,yy,100-rf[i]);

	}

	double ans=0;

	for(int i=1;i<=m;i++)

	{

		ans+=mo[i].z*1.0*ff(1,1,m,i);

	}

	printf("%.10lf",ans);

	return 0;

}