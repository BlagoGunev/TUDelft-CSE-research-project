#include<stdio.h>

#include<string.h>

const int N = 1005;	

int n,m;

double v1,v2,L;

double ll;

int main()

{

	while(~scanf("%d%lf%lf%lf%d",&n,&L,&v1,&v2,&m))

	{

		double k = n/m;

		if(n%m)k+=1;

		ll = 1+(2*v1*(k-1))/(v1+v2);

		ll = L/ll;

		printf("%.10lf\n",(L-ll)/v1+ll/v2);

	}



	return 0;

}