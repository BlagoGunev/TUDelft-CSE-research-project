#include <stdio.h>

#include <algorithm>

#include <iostream>

#include <vector>

#include <map>

#include <set>

#include <stdlib.h>

#include <math.h>

#include <string>

#include <time.h>

#include <string.h>

#include <queue>

#include <stack>

using namespace std;

typedef long long int ll;



ll ncr(ll n, ll k)

{

	if(n<k)

	{

		return 0;

	}

	if(n==k || k==0)

	{

		return 1;

	}

	else

	{

		return n*(ncr(n-1,k-1))/k;

	}

}



ll exx(ll n, ll k)

{

	ll ret=1;

	if(k<0)

	{

		return 0;

	}

	while(k)

	{

		if(k&1)

		{

			ret=(ret*n);

		}

		k=k>>1;

		n=(n*n);

	}

	return ret;

}



int main(void)

{

	int i, j;

	int n;

	double px, py, vx, vy, a, b, c, d;

	cin>>px>>py>>vx>>vy>>a>>b>>c>>d;

	double l=sqrt(vx*vx+vy*vy);

	double nvx=vx/l;

	double nvy=vy/l;

	printf("%.10lf %.10lf\n",px+nvx*b,py+nvy*b);

	printf("%.10lf %.10lf\n",px-nvy*(a/2),py+(nvx)*(a/2));

	printf("%.10lf %.10lf\n",px-nvy*(c/2),py+(nvx)*(c/2));

	printf("%.10lf %.10lf\n",px-nvy*(c/2)-nvx*d,py+(nvx)*(c/2)-nvy*d);

	printf("%.10lf %.10lf\n",px+nvy*(c/2)-nvx*d,py-(nvx)*(c/2)-nvy*d);

	printf("%.10lf %.10lf\n",px+nvy*(c/2),py-(nvx)*(c/2));		

	printf("%.10lf %.10lf\n",px+nvy*(a/2),py-(nvx)*(a/2));

}