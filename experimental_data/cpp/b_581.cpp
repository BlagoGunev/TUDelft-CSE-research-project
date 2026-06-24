#include <cstdio>
#define MAXN 100050
int n[MAXN],ans[MAXN];
int main()
{
    int a,b,i;
	scanf("%d",&a);
	for(i=1;i<=a;i++)scanf("%d",&n[i]);
	b=n[a];
	for(i=a;i>=1;i--)
	{
		if(b-n[i]<=0)
		{
			b=n[i]+1;
			ans[i]=0;
		}
		else ans[i]=b-n[i];
	}
	for(i=1;i<a;i++)printf("%d ",ans[i]);
	printf("%d",ans[i]);
}