//author:raunakrocks2k15
#include<cstdio>
int main()
{
	int a,b,flag=0,l,rem=0;
	int res=0;
	scanf("%d%d",&a,&b);
	l=a;
	while(1)
	{
		if(l==0)
			break;
		res+=l;
		l+=rem;
		rem=l%b;
		l=l/b;
		
		
	}
	printf("%d\n",res);
	return 0;
	
}