#include<bits/stdc++.h>

using namespace std;

int m,n;

int an[3001];

vector<int>v[3001];

int main()

{	

	int i,j,k; 

	scanf("%d%d",&n,&m);

	for(i=0;i<m;i++)

	{

		int a,b;

		scanf("%d%d",&a,&b);

		v[a].push_back(b);

	}

	long long int ans=0;

	for(i=1;i<=n;i++)

	{

		for(j=0;j<v[i].size();j++)

		{

			int ele=v[i][j];

			for(k=0;k<v[ele].size();k++)

			{

				if(v[ele][k]==i)

				continue;

				an[v[ele][k]]++;

			}

		}

		for(j=1;j<=n;j++)

		{

			ans+=(an[j]*(an[j]-1))/2;

			an[j]=0;

		}	

	}

	printf("%lld\n",ans);

	return 0;

}