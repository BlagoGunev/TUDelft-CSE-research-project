#include<bits/stdc++.h>

using namespace std;

const int MAXN=500+100;

int a[MAXN];

long long int ans;

int main()

{

	int n,k;

	cin>>n>>k;

	for(int i=1 ; i<=n ; i++)

	{

		cin>>a[i];

	}

	a[0]=9999999;

	a[n+1]=999999;

	for(int i=1 ; i<=n ; i++)

	{

		int help=k-(a[i]+a[i-1]);

		if(  help>0 )

		{

			ans+=help;

			a[i]+=help;

		}

	}

	cout<<ans<<endl;

	for(int i=1 ; i<=n ; i++)

	{

		cout<<a[i]<<" ";

	}

}