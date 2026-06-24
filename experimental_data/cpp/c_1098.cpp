#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,ans,f[100005];ll s; 
int main()
{
	scanf("%d%lld",&n,&s);
	if(s<2*n-1){puts("No");return 0;}
	if(s>1ll*n*(n+1)/2){puts("No");return 0;}
	ans=1;
	for(int i=n-1;i;i--)
	{
		ll t=1,r=n,rr=0;
		for(int j=1;;j++)
		{
			rr+=min(t,r)*j;
			r-=t;t=t*i;
			if(r<=0)break;
		}
		if(rr>s)
		{
			ans=i+1;
			break;
		}
	}
	puts("Yes");
	if(ans==1)
	{
		for(int i=1;i<n;i++)printf("%d ",i);
		return 0;
	}
	ll S=0;
	for(int i=1;i<=n;i++)f[i]=1,S+=i;
	int t=2,l=n;
	while(S>s)
	{
		if(l-t<=S-s)
		{
			f[t]++;S-=l-t;f[l]--;
			if(f[t]==f[t-1]*ans)t++;
			if(f[l]==0)l--;
		}
		else
		{
			f[l-(S-s)]++;f[l]--;break;
		}
	}
//	for(int i=1;i<=n;i++)cout<<f[i]<<endl;
	int s=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<f[i];j++)
		{
			printf("%d ",s+j/ans);
		}
		s+=f[i-1];
	}
	return 0;
}