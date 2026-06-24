#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#define INF 0x3f3f3f3f
#define mod 1000000007

int main()
{
   	long long a,b,n,s;
   	int t;
   	scanf("%d",&t);
   	while(t--)
   	{
   		int f=0;
   		long long tt,kk;
   		scanf("%lld %lld %lld %lld",&a,&b,&n,&s);
   		kk=b+n*a;
   		if(kk>=s)
   		{
   			kk=s%n;
   			tt=s/n;
   			if(tt<=a&&kk<=b)
   			f=1;
   			else if(s-n*a<=b&&s-n*a>=0)
   			f=1;
   			else if(s<=b)
   			f=1;
   			
		}
		
		   
		   if(f==0)
		   printf("NO\n");
		   else
		   printf("YES\n");
   		
	}
}