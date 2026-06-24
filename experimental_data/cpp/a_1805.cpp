#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N];

int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]), a[i]^=a[i-1];
		if((n&1)||a[n]==0) printf("%d\n",a[n]);
		else puts("-1");
	}
	return 0;
}