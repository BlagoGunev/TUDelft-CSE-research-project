#include<bits/stdc++.h>

using namespace std;

int a[1002],visited[1002];

int main()

{

	int N,K;

	scanf("%d%d",&N,&K);

	int i;

	

	for (i=0;i<N;i++)

	{

		scanf("%d",&a[i]);

	}

	int maxi=0,indx,j;

	for (i=0;i<N;i++)

	{int count=0;

	   if(visited[i]==0)

	   {

	   if(a[i]-i*K<=0)

	   continue;

		for (j=i;j<N;j++)

		{

			int p=(j-i);

			if(a[j]==p*K+a[i])

			{

				count++;

				visited[j]=1;

			}

		}

		

		}

		if(count>maxi)

		{

			maxi=count;

			indx=i;

		}

	}

	

	printf("%d\n",N-maxi);

	for (i=0;i<N;i++)

	{

		int exp=a[indx]+(i-indx)*K;

		if(a[i]==exp)

		continue;

		if(a[i]>exp)

		{

			printf("- %d %d\n",i+1,a[i]-exp);

		}

		

		else

		{

			printf("+ %d %d\n",i+1,exp-a[i]);

		}

	}

}