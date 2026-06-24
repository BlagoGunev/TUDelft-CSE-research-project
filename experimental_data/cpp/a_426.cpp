#include<bits/stdc++.h>

using namespace std;

int n , k ;

int main()

{

	cin>>n>>k;

	int x , sum=0 , maxx=0;

	for(int i=0 ; i<n ; i++)

	{

		cin>>x;

		sum+=x;

		maxx=max(maxx , x);

	}

	sum-=maxx;

	if( k >= sum)

		cout<<"YES";

	else

		cout<<"NO";

}