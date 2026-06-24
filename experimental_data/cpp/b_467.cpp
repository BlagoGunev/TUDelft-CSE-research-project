#include <cstdio>

#include <cstdlib>

#include <cstring>

int n,m,k;

int w[1007];



int count(int x)

{

	int res=0;

	for(;x>0;x>>=1) res+=x&1;

	return res;

}



int main()

{

	int i,x,xx,ans=0;

	scanf("%d%d%d",&n,&m,&k);

	for(i=1;i<=m;i++) scanf("%d",w+i);

	scanf("%d",&xx);

	for(i=1;i<=m;i++)

	{

		x=xx^w[i];

		if(count(x)<=k) ans++;

	}

	printf("%d\n",ans);

	return 0;

}