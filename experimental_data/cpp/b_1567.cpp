#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main()
{
	fast
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;//300000
	
		ll k=0;
		int n=a-1;
		if (n % 4 == 0)k=n;

  else if (n % 4 == 1)k=1;
  else if (n % 4 == 2)k=n+1;
   
          if(k==b)
          {
          	cout<<a;
		  }
		  else
		  {
		  	ll r=a^k;
		  	if(r==b)cout<<a+2;
		  	else cout<<a+1;
		  }
		cout<<"\n";
		
	}
}