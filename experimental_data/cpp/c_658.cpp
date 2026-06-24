#include <bits/stdc++.h>
#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<queue>

#include<stack>

#include<math.h>

#include<vector>

#include<map>

#include<set>

#include<stdlib.h>

#include<cmath>

#include<string>

#include<algorithm>

#include<iostream>

using namespace std;

#define X first

#define Y second

typedef int64_t ll;



int main()

{

	int n,d,h,i;

	scanf("%d%d%d",&n,&d,&h);

	if(d>2*h)

	{

		puts("-1");

		return 0;

	}

	if(n!=2 && d==1)

	{

		puts("-1");

		return 0;

	}

	for(i=1;i<=h;i++)

	{

		printf("%d %d\n",i,i+1);

	}

	if(d>h)

	{

		printf("%d %d\n",1,h+2);

		for(i=h+2;i<=d;i++)

			printf("%d %d\n",i,i+1);

		for(i=d+2;i<=n;i++)

			printf("1 %d\n",i);

		return 0;

	}

	for(i=d+2;i<=n;i++)

		printf("2 %d\n",i);

	return 0;

}