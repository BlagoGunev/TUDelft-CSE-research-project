#include<stdio.h>
int main()
{
	long long n,i,j,a,b,c,d,e;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		e=b;
		b=b*d;
		a=a*d;
		d=d*e;
		c=c*e;
		if(a==c)
		printf("0\n");
		else if(a==0||c==0||a%c==0||c%a==0)
		printf("1\n");
		else
		printf("2\n");
	}
	return 0;
 }