#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

int s,x,t;



int main()

{

	scanf("%d %d %d",&t,&s,&x);

	if(x == t)	puts("YES");

	else if(x == t + 1)	puts("NO");

	else

	{

		if(x < t)	puts("NO");

		else

		{

			x -= t;

			x %= s;

			if(x == 0 || x == 1)	puts("YES");

			else	puts("NO");

		}

	}

	return 0;

}