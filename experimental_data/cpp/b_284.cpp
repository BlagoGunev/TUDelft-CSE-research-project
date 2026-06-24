#include<stdio.h>
int main()
{
	int n,i,a[3]={0},ans;
	scanf("%d",&n);
	char c=getchar();
	for(i=0;i<n;i++)
	{
		c=getchar();
		if(c=='A')	a[0]++;
		else if(c=='I')	a[1]++;
		else if(c=='F')	a[2]++;
	}
	if(a[1]>1)	ans=0;
	else if(a[1]==1)	ans=1;
	else if(a[1]==0)	ans=a[0];
	printf("%d",ans);
	return 0;
}