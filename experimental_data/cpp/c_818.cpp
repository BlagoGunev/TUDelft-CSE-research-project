#include<cstdio>
#include<iostream>
#define M 100005
int n,m,k;
int sum[M],X[M][2],Y[M][2],cnt[4],vis[M];
main()
{
	//freopen("random.in","r",stdin);
	scanf("%d%d%d",&k,&n,&m);
	for (int i=1;i<=k;++i)
		scanf("%d%d%d%d",X[i]+0,Y[i]+0,X[i]+1,Y[i]+1);
	for (int i=0;i<4;++i) scanf("%d",cnt+i);
	for (int o=0;o<4;++o)
	{
		for (int i=1;i<=(o<=2?n:m);++i) sum[i]=0;
		for (int i=1;i<=k;++i)
		{
			if (o==0)
				if (X[i][0]==X[i][1]) ++sum[X[i][0]];
				else ++sum[(X[i][0]+X[i][1])/2];
			else if (o==1)
				if (X[i][0]==X[i][1]) ++sum[X[i][0]];
				else ++sum[(X[i][0]+X[i][1]+1)/2];
			else if (o==2)
				if (Y[i][0]==Y[i][1]) ++sum[Y[i][0]];
				else ++sum[(Y[i][0]+Y[i][1])/2];
			else
				if (Y[i][0]==Y[i][1]) ++sum[Y[i][0]];
				else ++sum[(Y[i][0]+Y[i][1]+1)/2];
		}
		if (o==0)
			for (int i=1;i<=n;++i) sum[i]+=sum[i-1];
		else if (o==1)
			for (int i=n;i>=1;--i) sum[i]+=sum[i+1];
		else if (o==2)
			for (int i=1;i<=m;++i) sum[i]+=sum[i-1];
		else
			for (int i=m;i>=1;--i) sum[i]+=sum[i+1];
		for (int t,i=1;i<=k;++i)
		{
			bool flag=0;
			if (o==0)
				if (X[i][0]==X[i][1]) t=X[i][0],flag=1;
				else t=(X[i][0]+X[i][1]+1)/2;
			else if (o==1)
				if (X[i][0]==X[i][1]) t=X[i][0],flag=1;
				else t=(X[i][0]+X[i][1])/2;
			else if (o==2)
				if (Y[i][0]==Y[i][1]) t=Y[i][0],flag=1;
				else t=(Y[i][0]+Y[i][1]+1)/2;
			else
				if (Y[i][0]==Y[i][1]) t=Y[i][0],flag=1;
				else t=(Y[i][0]+Y[i][1])/2;
			if (sum[t+((o&1)?1:-1)]-1+flag==cnt[o]) ++vis[i];
		}
	}
	for (int i=1;i<=k;++i)
		if (vis[i]==4) return printf("%d\n",i),0;
	puts("-1");
}