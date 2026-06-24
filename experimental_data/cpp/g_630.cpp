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

	while(k)

	{

		if(k&1)

		{

			ret=(ret*n)%100000;

		}

		k=k>>1;

		n=(n*n)%100000;

	}

	return ret;

}



int main(void)

{

	int i, j;

	ll n;

	cin>>n;

	cout<<ncr(n+4,5)*ncr(n+2,3);

	

}