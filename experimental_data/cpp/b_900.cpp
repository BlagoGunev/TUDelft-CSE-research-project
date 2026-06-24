#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	//printf("%lf",k);
	int kk;
	int x;
	int tot=0;
	int ans=0;
	while (1)
	{
		tot++;
		a=a*10;
		x=a/b;
		if (x==c) 
		{
			ans=tot;
			break;
		}
		a=a-x*b;
		if (tot>100000) break;
	}
	if (ans!=0) printf("%d",ans);
		else printf("-1");
	return 0;
}