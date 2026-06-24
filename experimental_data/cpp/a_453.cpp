#include<stdio.h>
#include<string.h>
#define eps 0.000001
int n,m,i,flag,j;
double temp,ans,tt;
main()
{
	scanf("%d%d",&m,&n);
	ans=m;
	for(i=m-1;i>=1;i--)
	{
		temp=i*1.0/m;
		tt=1.0;
		flag=0;
		for(j=1;j<=n;j++)
		{
			tt*=temp;
			if(tt<eps)
			{
				flag=1;
				break;
			}
		}
		ans-=tt;
		if(flag==1) break;
	}
	printf("%f\n",ans);
}