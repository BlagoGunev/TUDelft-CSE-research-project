#include<bits/stdc++.h>
#define int long long
using namespace std;
int t; 
int n;
int a[606060];
int ans[606060];
int qz_mx[606060];
int qz_mx_pi[606060];
void div(int lim)
{
	if(lim<=0)	return ;
	
	
	int mx=qz_mx[lim];
	int mx_pi=qz_mx_pi[lim];
	int mn1=0x3f3f3f3f;
	for(int i=mx_pi;i<=lim;i++)
	{
		mn1=min(mn1,a[i]);
	}
	int ok=mx_pi;
	for(int i=mx_pi;i>=1;i--)
	{
		if(qz_mx[i]<=mn1)
		{
			break;
		}
		
		if(a[i]>mn1)
		{
			ok=i;
		}
		mn1=min(mn1,a[i]);
	}
	for(int i=ok;i<=lim;i++)
	{
		ans[i]=mx;
	}
	div(ok-1);
}
signed main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]>qz_mx[i-1])
			{
				qz_mx_pi[i]=i;
				qz_mx[i]=a[i];
			}
			else
			{
				qz_mx_pi[i]=qz_mx_pi[i-1];
				qz_mx[i]=qz_mx[i-1];
			}
		}
		div(n);
		for(int i=1;i<=n;i++)	cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}