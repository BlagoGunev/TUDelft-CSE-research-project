#include<bits/stdc++.h>
using namespace std;
int T,n;
vector<int> v[200010];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int L=1,R=n,flag=1;
		for(int i=1,x;i<=n;i++)
		{
			scanf("%d",&x),v[x].push_back(i);
			L=max(L,i-x+1),R=min(R,i+x-1);
		}
		int l=n,r=1;
		for(int i=1;i<=n;i++)
		{
			for(auto x:v[i]) l=min(l,x),r=max(r,x);
			for(int x:v[i]) if(x-l+1>i||r-x+1>i) flag=0;
			v[i].clear();
		}
		printf("%d\n",flag?max(R-L+1,0):0);
	}
}