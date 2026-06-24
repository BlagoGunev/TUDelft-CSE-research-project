#include <bits/stdc++.h>
#define fo(a,b,c) for (int a=b; a<=c; a++)
#define fd(a,b,c) for (int a=b; a>=c; a--)
#define ll long long
#define file
using namespace std;

int n,Q;
ll tr[2000001][2];
int a[500001],b[500001];
ll c[500001];
ll sumb;

void change(int t,int l,int r,int x,ll s)
{
	int mid=(l+r)/2;
	if (l==r)
	{
		tr[t][0]=s;
		tr[t][1]=min(s,0ll);
		return;
	}
	if (x<=mid) change(t*2,l,mid,x,s);
	else change(t*2+1,mid+1,r,x,s);
	
	tr[t][0]=tr[t*2][0]+tr[t*2+1][0];
	tr[t][1]=min(tr[t*2][1],tr[t*2+1][1]+tr[t*2][0]);
}

int main()
{
//	freopen("F.in","r",stdin);
	
	scanf("%d%d",&n,&Q);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n) scanf("%d",&b[i]),change(1,1,n,i,a[i]-b[i]),sumb+=b[i];
	fo(i,1,n-1) scanf("%lld",&c[i]);
	for (;Q;--Q)
	{
		int p,x,y;
		ll z;
		scanf("%d%d%d%lld",&p,&x,&y,&z);
		sumb-=b[p];
		a[p]=x,b[p]=y;
		sumb+=b[p];
		
		change(1,1,n,p,x-y);
		printf("%lld\n",sumb+tr[1][1]);
	}
}