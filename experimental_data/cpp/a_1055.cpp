#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,s,i;
	cin>>n>>s;
	
	  int a[n],b[n];
      for(i=1;i<=n;i++)
      {
      	cin>>a[i];
      }
      for(i=1;i<=n;i++)
      {
      	cin>>b[i];
      }
      if(a[1]==0)
      {
      	cout<<"NO"<<endl;
      	return 0;
	  }
      if(a[s]==1)
      {
      	 cout<<"YES"<<endl;
      	 return 0;
      }
	  if(b[s]==1)
	  {
		for(i=s+1;i<=n;i++)
		{
			if(a[i]==1 && b[i]==1)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
    return 0;
  
}