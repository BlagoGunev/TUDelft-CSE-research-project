#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;					 		
int main()
{	
	ll n,a,b,c;
	cin>>n>>a>>b;
	int f=0;
	ll cost =0;
	vector<ll> A(100);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(int i=0;2*i<n;i++)
	{
		c=n-i-1;
		if(A[i]==2)
		{
			if(A[c]==2)	
			{
				cost+=min(a,b);
				if(c!=i)
				{
					cost+=min(a,b);
				}	
			}
			else if(A[c]==0)
			{
				cost+=a;
			}
			else
			{
				cost+=b;
			}			
		}
		else if(A[c]==2)
		{
			if(A[i]==0)
			{
				cost+=a;
			}
			else
			{
				cost+=b;
			}
		}
		else if(A[i]!=A[c])
		{
			f=1;
			break;
		}
	}
	if(f==1)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		cout<<cost<<endl;
	}					
return 0;
}