#include<stdio.h>
#define min(x,y) ((x)<(y)?(x):(y))
char a[100005];
main()
{
	register int n,t,ans1,ans2;
	for(scanf("%d",&t);t--;printf("%d\n",min(n-(ans1<<1),n-(ans2<<1))>>1))
	{
		scanf("%d%s",&n,a);ans1=ans2=0;
		for(register int i=0;i<n-1;++i)
			if(!(a[i]^48)&&!(a[i+1]^49))++ans1;
			else if(!(a[i]^49)&&!(a[i+1]^48))++ans2;
	}
}