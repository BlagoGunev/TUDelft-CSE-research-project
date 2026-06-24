#include<bits/stdc++.h>

using namespace std;

int mark[500];

int main()

{

	int n , a, b;

	cin>>n>>a>>b;

	for(int i=0 ; i<a ; i++)

	{

		int x;

		cin>>x;

		mark[x]=1;		

	}

	for(int i=0 ; i<b ; i++)

	{

		int x;

		cin>>x;

		if(mark[x]==0)

		{

			mark[x]=2;

		}		

	}

	for(int i=1 ; i<=n ; i++)

	{

		cout<<mark[i]<<" ";

	}

}