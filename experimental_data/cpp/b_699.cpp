#include<cstdio>

#include<cstring>



char s[1010][1010];

int ansx,ansy,x[1010],y[1010],sum,n,m;



bool check()

{

	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)

	if(x[i]+y[j]-(s[i][j]=='*')==sum)

	{

		ansx=i,ansy=j;return 1;

	}

	return 0;

}

int main()

{

	while(scanf("%d %d",&n,&m)==2)

	{

		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);

		for(int i=1;i<=n;i++)

		{

			x[i]=0;

			for(int j=1;j<=m;j++) x[i]+=(s[i][j]=='*');

		}

		for(int j=1;j<=m;j++)

		{

			y[j]=0;

			for(int i=1;i<=n;i++) y[j]+=(s[i][j]=='*');

		}

		sum=0;

		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) sum+=(s[i][j]=='*');

		if(check()) printf("YES\n%d %d\n",ansx,ansy);

		else puts("NO");

	}

}