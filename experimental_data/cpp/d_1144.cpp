#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxd = 2e5+10;
int arr[maxd],vis[maxd],pos,x,dd,n;
int main()
{
	// freopen("a.in","r",stdin);
	// freopen("k.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		arr[i] = x;
		vis[x]++;
		if(vis[x] > vis[pos]) pos = x,dd=i;
	}
	printf("%d\n",n-vis[pos]);
	for(int i=dd-1;i>=1;i--)
	{
		if(arr[i] > pos) printf("%d %d %d\n",2,i,i+1);
		if(arr[i] < pos) printf("%d %d %d\n",1,i,i+1);
	}
	for(int i=dd+1;i<=n;i++)
	{
		if(arr[i] > pos) printf("%d %d %d\n",2,i,i-1);
		if(arr[i] < pos) printf("%d %d %d\n",1,i,i-1);
	}
	return 0;
}