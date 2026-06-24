#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50050;
int n,a[maxn],ans[maxn];
int coe[maxn],ord[maxn];
bool cmp(const int &xx,const int &yy) { return coe[xx]>coe[yy]; }
int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in","r",stdin);
#endif
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		ord[i]=i,coe[i]=n-a[i]-a[(i+1)%n];
	//for(i=0;i<n;i++) printf("%d ",coe[i]); printf("\n");
	sort(ord,ord+n,cmp);
	for(i=0;i<n;i++)
		ans[ord[i]]=i;
	for(i=0;i<n;i++)
		printf("%d%c",ans[i],i<n-1?' ':'\n');
	return 0;
}