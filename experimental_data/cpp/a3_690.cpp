#include <bits/stdc++.h>

using namespace std;

int T,n,r;

int main()

{

	scanf("%d",&T);

	while(T--)

	{

		scanf("%d%d",&n,&r);

		int sum=0;

		for(int i=1,x;i<n;i++)

			scanf("%d",&x),sum+=x;

		sum=((r-sum)%n+n)%n;

		printf("%d\n",sum ? sum:n);

	}

}