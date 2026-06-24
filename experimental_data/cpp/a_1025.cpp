#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define pb push_back
#define deb(x) cout<<#x<<" : "<<x<<"\n";
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
#define mset(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define mod 1000000007
#define N 100010

ll pow_mod(ll x,ll y)
{
	ll r=1;
	for(;y;y>>=1,x=(ll)x*x%mod)
		if(y&1)r=(ll)r*x%mod;
	return r;
}

int main()
{
	int n;
	cin>>n;
	
	int f[30];
	mset(f,0);
	
	if(n==1)
	{
		cout<<"YES";
		return 0;
	}
	
	for(int i=0;i<n;i++)
	{
		char c;
		cin>>c;
		
		f[c-'a']++;
		
		if(f[c-'a']>=2)
		{
			cout<<"YES";
			return 0;
		}
	}
	
	cout<<"NO";
}