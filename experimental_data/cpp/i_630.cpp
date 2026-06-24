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

	ll n;

	cin>>n;

	cout<<2*4*3*exx(4,n-3)+(n-3)*4*3*3*exx(4,n-4);

	

	

}