#include<stdio.h>
int main()
{
	int n,a,b,c;
	while(scanf("%d%d%d%d",&n,&a,&b,&c)!=EOF)
	{
		int sum=0,m=1;
		while(--n)
		{
			if(m==1)
			{
				if(a<b)
				{
					sum+=a;
			 	    m=3;
				}
				else
				{
					sum+=b;
					m=2;
				}
			}
			else if(m==2)
			{
				if(b<c)
				{
					sum+=b;
			 	    m=1;
				}
				else
				{
					sum+=c;
					m=3;
				}
			}
			else if(m==3)
			{
				if(a<c)
				{
					sum+=a;
			 	    m=1;
				}
				else
				{
					sum+=c;
					m=2;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
 }