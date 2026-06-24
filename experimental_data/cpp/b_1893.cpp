#include <bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int n,m;
int a[N], b[N], suf[N], ans[2*N];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(b,b+m); reverse(b,b+m);
		suf[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--)
			suf[i]=max(suf[i+1], a[i]);
		int cb=0, idx=0;
		for(int i=0;i<n;i++)
		{
			while(cb<m && suf[i]<=b[cb])
				ans[idx++]=b[cb++];
			ans[idx++]=a[i];
		}
		while(cb<m) ans[idx++]=b[cb++];
		for(int i=0;i<n+m;i++)
			printf("%d ", ans[i]);
		puts("");
	}
}