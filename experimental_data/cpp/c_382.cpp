#include <iostream>

#include <cmath>

#include <vector>

#include <cstdlib>

#include <cstdio>

#include <climits>

#include <ctime>

#include <cstring>

#include <queue>

#include <stack>

#include <list>

#include <algorithm>

#include <map>

#include <set>

#define LL long long

#define Pr pair<int,int>

#define fread(ch) freopen(ch,"r",stdin)

#define fwrite(ch) freopen(ch,"w",stdout)



using namespace std;

const int INF = 0x3f3f3f3f;

const int msz = 10000;

const int mod = 1e9+7;

const double eps = 1e-8;



int num[112345];



int main()

{

	//fread("");

	//fwrite("");



	int n;



	scanf("%d",&n);



	if(n == 1)

	{

		puts("-1");

		return 0;

	}



	for(int i = 0; i < n; ++i)

		scanf("%d",&num[i]);



	sort(num,num+n);



	int a,b,c1,c2;

	int p1,p2;



	a = num[1]-num[0];

	c1 = 1;

	c2 = 0;

	p1 = 1;



	for(int i = 2; i < n; ++i)

	{

		if(num[i]-num[i-1] == a) 

		{

			c1++;

			continue;

		}



		if(c2)

		{

			if(num[i]-num[i-1] == b && c1 == 1)

			{

				swap(a,b);

				swap(c1,c2);

				swap(p2,p1);

				c1++;

				continue;

			}

			puts("0");

			return 0;

		}

		b = num[i]-num[i-1];

		c2++;

		p2 = i;

	}



	if(!c2)

	{

		if(a == 0)

		{

			printf("1\n%d",num[0]);

		}

		else if(n == 2 && a%2 == 0)

		{

			printf("3\n%d %d %d",num[0]-a,num[1]-a/2,num[1]+a);

		}

		else printf("2\n%d %d",num[0]-a,num[n-1]+a);

	}

	else

	{

		if(b%2 == 0 && a == b/2)

		{

			printf("1\n%d",num[p2]-a);

		}

		else if(a%2 == 0 && b == a/2)

		{

			if(c1 == 1 && c2 == 1)

			{

				printf("1\n%d",num[p1]-b);

			}

			else puts("0");

		}

		else puts("0");

	}



	return 0;

}