#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;


int n,a[200005],q[200005],t=0;

int dfs(int i,int x)
{
	int k=lower_bound(q+i+1,q+t+2,2*x)-q;
	if(k>t) return x;
	else return x+dfs(k,2*x);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
	sort(a+1,a+1+n);
	int k=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) k++;
		else 
		{
			q[++t]=k;
			k=1;
		}
	}
	q[++t]=k;
	sort(q+1,q+1+t); 
	q[t+1]=2*n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		k=lower_bound(q+1,q+t+2,i)-q;
		if(k>t) break;
		ans=max(ans,dfs(k,i));
	}
	cout<<ans;
	return 0;
 }