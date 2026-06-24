#include <stdio.h>
#include <stdlib.h>
int main()
{	
 	int t;
	long long s,a,b,c,ans;
	scanf("%d",&t);
	for(int i=0;i<t;i++){	
	scanf("%llu %llu %llu %llu",&s,&a,&b,&c);
	ans	=s/c;	
	printf("%llu\n",ans+(ans/a)*b);
	}
	return 0;
}