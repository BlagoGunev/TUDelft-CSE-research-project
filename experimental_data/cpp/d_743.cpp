#include<bits/stdc++.h>
#define NA (-(1ll<<62))
using namespace std;

struct edge
{
	int n;
	edge* next;
}mem[500005],*head[200005];
int cnt;
void add_edge(int s,int t)
{
	mem[++cnt].n=t;mem[cnt].next=head[s];head[s]=mem+cnt;
	mem[++cnt].n=s;mem[cnt].next=head[t];head[t]=mem+cnt;
}
int n,val[200005];
long long tot[200005];
long long ans=NA;
long long find(int now,int fa)
{
	long long mx1=NA,mx2=NA;
	tot[now]=val[now];
	for (edge *it=head[now];it;it=it->next)
	{
		if (it->n==fa) continue;
		long long ths=find(it->n,now);
		if (ths>mx1) {mx2=mx1;mx1=ths;}
		else if (ths>mx2) {mx2=ths;}
		tot[now]+=tot[it->n];
	}
	if ((mx1!=NA)&&(mx2!=NA)) ans=max(ans,mx1+mx2);
	return max(tot[now],mx1);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&val[i]);
	for (int i=1;i<=n-1;i++)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		add_edge(s,t);
	}
	find(1,-1);
	if (ans==NA) printf("Impossible\n");
	else printf("%I64d\n",ans);
	return 0;
}