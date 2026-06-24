#include<bits/stdc++.h>

using namespace std;

const int mxn=1505;

const int mul=233383;

const int mod=998244353;//924844033;

int n,m,i,j,t,k,s,a[mxn][mxn],b[mxn][mxn],loc[mxn],f[mxn][mxn];

int ha[mxn],hb[mxn],ida[mxn],idb[mxn],stk[mxn],tp;

bool vis[mxn],tag[mxn];

int nowp,num[mxn],lstp[mxn];

bool cmpa(int x,int y){return ha[x]<ha[y];}

bool cmpb(int x,int y){return hb[x]<hb[y];}

char cha;

inline int Read()

{

	int x=0;cha=getchar();

	while (cha<'0'||cha>'9') cha=getchar();

	while (cha>='0'&&cha<='9')

	{

		x=(x<<3)+(x<<1)+(cha-'0');cha=getchar();

	}return x;

}



int main()

{

	//freopen("hhh.in","r",stdin);

	n=Read();m=Read();//scanf("%d%d",&n,&m);

	for (i=1;i<=n;++i)

	{

		ida[i]=i;

		for (j=1;j<=m;++j)

		 //scanf("%d",&a[i][j]),

		 a[i][j]=Read(),ha[i]=(ha[i]*1ll*mul+a[i][j])%mod;

	}

	stable_sort(ida+1,ida+n+1,cmpa);

	for (i=1;i<=n;++i)

	{

		idb[i]=i;

		for (j=1;j<=m;++j)

		 //scanf("%d",&b[i][j]),

		 b[i][j]=Read(),hb[i]=(hb[i]*1ll*mul+b[i][j])%mod;

	}

	stable_sort(idb+1,idb+n+1,cmpb);

	for (i=1;i<=n;++i)

	{

		t=ida[i];k=idb[i];

		//printf("%d sa %d %d h %d %d\n",i,t,k,ha[t],hb[k]);

		if (ha[t]^hb[k]){puts("-1");return 0;}

		loc[k]=t;

	}

	for (i=1;i<=n;++i)

	{

		//printf("%d loc %d\n",i,loc[i]);

		for (j=1;j<=m;++j)

		{

			if (b[i][j]>=b[i-1][j]&&i>1) f[i][j]=f[i-1][j];

			else f[i][j]=i;

		}

	}

	nowp=1;tag[n]=1;

	for (i=1;i<=n;++i) lstp[i]=0;

	for (i=1;i<=m;++i) num[i]=(f[n][i]==1);

	while (1)

	{

		for (i=1;i<=m;++i) if (!vis[i]&&num[i]==nowp) break;

		if (i>m) break;

		//printf("%d\n",i);

		stk[++tp]=t=i;vis[i]=1;bool New=0;int lst=0;

		for (i=1;i<=n;++i)

		{

			if (b[i][t]<b[i+1][t]&&!tag[i])//brand new one

			{

				tag[i]=1;++nowp;

				for (j=1;j<=m;++j)

				 num[j]+=(f[i][j]<=lst+1);

				lstp[i]=lst;

				lst=i;New=1;

			}

			else if (tag[i])

			{

				if (New)//new then update or the complexity will explode

				{

					New=0;

					for (j=1;j<=m;++j)

					 num[j]+=-(f[i][j]<=lstp[i]+1)+(f[i][j]<=lst+1);

					lstp[i]=lst;

				}

				lst=i;

			}

		}

	}

	for (i=1;i<n;++i) if (!tag[i] &&loc[i]>loc[i+1]) {puts("-1");return 0;}

	printf("%d\n",tp);

	while (tp) printf("%d ",stk[tp]),--tp;puts("");

	return 0;//n m!!!!

}