#include<stdio.h>
#define min(x,y) ((x)<(y)?(x):(y))
char s[100001];
main()
{
	register int t,n,a,b,ans,lst;
	for(scanf("%d",&t);t--;printf("%d\n",ans))
	{
		scanf("%d%d%s",&a,&b,s);ans=0;lst=-999999;
		for(register int i=0;s[i];++i)if(s[i]^'0')
			ans+=min(a,b*(i-lst-1)),lst=i;
	}
}