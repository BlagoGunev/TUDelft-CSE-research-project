#include<bits/stdc++.h>

#define ll long long 

using namespace std;



int main()

{

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);

  int t=1;

  //cin>>t;

  while(t--)

  {

 	ll n;

 	cin>>n;

 	vector<ll>store(n+1);

 	store[0]=1;

 	for(int i=1;i<=n;++i)

 	{

 		store[i]=store[i-1]*i;

 	}   

 	ll ans=store[n]/store[n/2]/store[n/2];

	ans=ans*store[n/2-1]*store[n/2-1]; 	

	ans/=2;

	cout<<ans<<"\n";

  }

  return 0;

}