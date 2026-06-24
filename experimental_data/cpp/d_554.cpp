#include <bits/stdc++.h>

using namespace std;

#include <cstdio>



long long f[100];

int i,n;

long long m;



int main()

{

	scanf("%d%lld",&n,&m);

	f[n+1]=1,f[n]=1,f[n-1]=2;

	for (i=n-2;i>0;i--)

		f[i]=f[i+1]+f[i+2];

	for (i=1;i<=n;)

		if (m>f[i+1])

			m=m-f[i+1],printf("%d %d ",i+1,i),i=i+2;

		else

			printf("%d ",i),i++;

	return 0;

}