#include<stdio.h> 
#include<string.h>
int main()
{
	int a[105];
	int i=0;
	a[1]=1;
	a[2]=2;
	a[3]=4;
	for(i=4;i<=100;i++)
	{
		a[i]=i+a[i-2];
	}
	int n;
	scanf("%d",&n);
	printf("%d",a[n]);
	return 0;
}