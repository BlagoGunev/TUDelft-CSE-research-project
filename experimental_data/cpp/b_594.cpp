#include <cstdio>

#include <cmath>



const double pi=acos(-1);

double k2,t,ll,rr,mid;

int i,j,n,r,v,x,y,z;



int main()

{

	scanf("%d%d%d",&n,&r,&v);

	for (i=1;i<=n;i++)

	{

		scanf("%d%d",&x,&y);

		z=y-x;

		k2=trunc(z/pi/r/2);

		ll=0,rr=pi;

		for (j=1;j<=60;j++)

		{

			mid=(ll+rr)/2;

			if (2*mid*r+2*k2*r*pi+sin(mid)*2*r<z)

				ll=mid;

			else

				rr=mid;

		}

		printf("%.10lf\n",(2*ll*r+2*k2*r*pi)/v);

	}

	return 0;

}