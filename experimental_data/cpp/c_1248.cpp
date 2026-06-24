#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long 
#define mod 1000000007
using namespace std;
int n,m;
ll ans;
int nn,mm;
ll fa[100004];
int main()
{
	cin>>n>>m;
	nn=min(n,m);
	mm=min(n,m);
	fa[1]=2;
	fa[2]=4;
	for (int i=3;i<=100000;i++)
	{
		fa[i]=fa[i-1]+fa[i-2];
		fa[i]=fa[i]%mod;
	}
	ans=fa[m]+fa[n];
	ans=ans-2;
	ans=(ans+mod)%mod;
	cout<<ans;
	
	
}