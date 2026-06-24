// Shalin

#include <bits/stdc++.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

#include <limits.h>

using namespace std;

#define si(x) scanf("%d",&x)

#define slli(x) scanf("%lld",&x);

#define sc(x) scanf("%c",&x);

#define ss(x) scanf("%s",x);

#define sd(x) scanf("%lf",&x);

#define bitcount __builtin_popcount

#define gcd __gcd

#define llu long long unsigned int

#define lli long long int

#define fi first

#define se second

#define pb push_back

#define mod 1000000007

#define mp make_pair

#define vi vector<int>

#define vlli vector<long long int>

#define pii pair<int,int>

void solve1(int x1,int y1,int x2,int y2,int x3,int y3,int aa,int bb,int cc)

{

	int i,j,k;

	char mat[y1][y1];

	for(i=0;i<x1;i++)

	{

		for(j=0;j<y1;j++)

			mat[i][j]='A'+aa;

	}

	for(i=x1;i<x1+x2;i++)

	{

		for(j=0;j<y1;j++)

			mat[i][j]='A'+bb;

	}

	for(i=x1+x2;i<x1+x2+x3;i++)

	{

		for(j=0;j<y1;j++)

			mat[i][j]='A'+cc;

	}

	for(i=0;i<y1;i++)

	{

		for(j=0;j<y1;j++)

			printf("%c",mat[i][j]);

		printf("\n");

	}

}

void solve2(int x1,int y1,int x2,int y2,int x3,int y3,int aa,int bb,int cc)

{

	int i,j,k;

	char mat[y1][y1];

	

	for(i=0;i<x1;i++)

	{

		for(j=0;j<y1;j++)

			mat[i][j]='A'+aa;

	}

	for(i=x1;i<x1+x2;i++)

	{

		for(j=0;j<y2;j++)

			mat[i][j]='A'+bb;

	}

	for(i=x1;i<x1+x2;i++)

	{

		for(j=y2;j<y1;j++)

			mat[i][j]='A'+cc;

	}

	for(i=0;i<y1;i++)

	{

		for(j=0;j<y1;j++)

			printf("%c",mat[i][j]);

		printf("\n");

	}

}

int main()

{

	//freopen("input.txt","r",stdin);

    //freopen("output.txt","w",stdout);

	int x[4],y[4];

	cin>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];

	int perm[3]={1,2,3};

	do

	{

		



		for(int i=0;i<(1<<3);i++)

		{

			int x1=x[perm[0]],y1=y[perm[0]];

			int x2=x[perm[1]],y2=y[perm[1]];

			int x3=x[perm[2]],y3=y[perm[2]];

			if((i>>0)&1)

			{

				swap(x1,y1);

			}

			if((i>>1)&1)

			{

				swap(x2,y2);

			}

			if((i>>2)&1)

			{

				swap(x3,y3);

			}

			//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;

			if(y1==y2 and y2==y3 and x1+x2+x3==y1)

			{

				printf("%d\n",y1);

				solve1(x1,y1,x2,y2,x3,y3,perm[0]-1,perm[1]-1,perm[2]-1);

				return 0;

			}

			if(y2+y3==y1 and x2==x3 and x1+x2==y1)

			{

				printf("%d\n",y1);

				solve2(x1,y1,x2,y2,x3,y3,perm[0]-1,perm[1]-1,perm[2]-1);

				return 0;

			}

		}



	}

	while(next_permutation(perm,perm+3));

	printf("-1\n");

	return 0;

}