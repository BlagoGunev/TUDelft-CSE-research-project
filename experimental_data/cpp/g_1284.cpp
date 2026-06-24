// LUOGU_RID: 98792725
#include<bits/stdc++.h>

#define gc()(xS==xTT&&(xTT=(xS=xB)+fread(xB,1,1<<20,stdin),xS==xTT)?0:*xS++)

#define pc(x)(p3-obuf<1000000)?(*p3++=x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x)

using namespace std;typedef long long ll;typedef double db;typedef long double ld;typedef unsigned long long ull;typedef unsigned int ui;char xch,xB[1<<20],*xS=xB,*xTT=xB,obuf[1000000],*p3=obuf;inline ll read(){char ch=gc();ll x=0,f=1;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}while('0'<=ch&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return x*f;}static char cc[20];template<typename item>inline void pt( item x){ int len=0;if(!x)pc('0');if(x<0)x=-x,pc('-');while(x)cc[len++]=x%10+'0',x/=10;while(len--)pc(cc[len]);}inline void pS(string s){for(int i=0;i<s.length();i++)pc(s[i]);}inline ll read2(){char ch=gc();ll x=0,f=1;while(ch<'0'||ch>'1'){if(ch=='-')f=-1;ch=gc();}while('0'<=ch&&ch<='9'){x=(x<<1)+(ch^48);ch=gc();}return x*f;}

const int maxn=410,maxh=25;

int h,w,n,a[maxh][maxh],T,tx[4]={0,0,1,-1},ty[4]={1,-1,0,0},hd,u[maxn<<2],v[maxn<<2],cnt,du[maxn],pre[maxn<<2],rt[maxn];bool isx[maxn<<2],isy[maxn<<2],xz[maxn<<2],vis[maxn<<2];char ans[maxh<<1][maxh<<1];

int go(){char c=gc();while(c!='O'&&c!='X')c=gc();return c=='X';}

bool in(int x,int y){return x>=1&&x<=h&&y>=1&&y<=w;}

int get(int x,int y){return (x-1)*w+y;}

int fr(int p){return rt[p]==p?p:rt[p]=fr(rt[p]);}

bool mg(int x,int y)

{

	x=fr(x),y=fr(y);

	if(x==y)return 0;

	rt[y]=x;return 1;

}

bool zg()

{

	memset(isx,0,sizeof isx),memset(isy,0,sizeof isy),memset(pre,0,sizeof pre),memset(du,0,sizeof du),memset(vis,0,sizeof vis);

	queue<int>Q;

	for(int i=1;i<=n;i++)rt[i]=i;

	for(int i=1;i<=cnt;i++)if(xz[i])du[u[i]]++,du[v[i]]++,mg(u[i],v[i]);

	for(int i=1;i<=cnt;i++)

	{

		if(xz[i])continue;

		if(fr(u[i])!=fr(v[i]))isx[i]=1,Q.push(i),vis[i]=1;

		if(du[u[i]]<2)

		{

			isy[i]=1;

			if(isx[i]){xz[i]=1;return 1;}

		}

	}

	while(!Q.empty())

	{

		int p=Q.front();Q.pop();

		if(isy[p])

		{

			while(p)xz[p]^=1,p=pre[p];

			return 1;

		}

		if(xz[p])

		{

			for(int i=1;i<=n;i++)rt[i]=i;

			for(int i=1;i<=cnt;i++)if(xz[i]&&i!=p)mg(u[i],v[i]);

			for(int i=1;i<=cnt;i++)

			{

				if(xz[i]||vis[i]||fr(u[i])==fr(v[i]))continue;

				pre[i]=p,vis[i]=1,Q.push(i);

			}

		}

		else

		{

			for(int i=1;i<=cnt;i++)

			{

				if(!xz[i]||vis[i]||du[u[p]]-(u[i]==u[p])>=2)continue;

				pre[i]=p,vis[i]=1,Q.push(i);

			}

		}

	}

	return 0;

}

signed main()

{

	T=read();

	while(T--)

	{

		cnt=0;memset(xz,0,sizeof xz),hd=0;

		h=read(),w=read();n=get(h,w);

		for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)a[i][j]=go();

		for(int i=1;i<=h;i++)

		{

			for(int j=(i==1?2:1);j<=w;j++)

			{

				if(!(i+j&1)&&!a[i][j])

				{

					hd+=2;

					for(int t=0;t<4;t++)

					{

						int i2=i+tx[t],j2=j+ty[t];

						if(in(i2,j2)&&!a[i2][j2])u[++cnt]=get(i,j),v[cnt]=get(i2,j2);

					}

				}

			}

		}

		while(zg())hd--;

		if(hd)pS("NO\n");

		else

		{

			pS("YES\n");

			if(!a[1][2])u[++cnt]=get(1,1),v[cnt]=get(1,2);

			if(!a[2][1])u[++cnt]=get(1,1),v[cnt]=get(2,1);

			for(int i=1;i<h<<1;i++)for(int j=1;j<w<<1;j++)ans[i][j]=' ';

			for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)if(a[i][j])ans[(i<<1)-1][(j<<1)-1]='X';else ans[(i<<1)-1][(j<<1)-1]='O';

			for(int i=1;i<=n;i++)rt[i]=i;

			for(int i=1;i<=cnt;i++)

			{

				if(!xz[i])continue;

				mg(u[i],v[i]);

				int x1=(u[i]-1)/w+1,y1=(u[i]-1)%w+1;

				int x2=(v[i]-1)/w+1,y2=(v[i]-1)%w+1;

				if(x1==x2&&y1+1==y2)ans[(x1<<1)-1][y1<<1]='O';

				else if(x1==x2&&y1-1==y2)ans[(x1<<1)-1][(y1-1)<<1]='O';

				else if(y1==y2&&x1+1==x2)ans[x1<<1][(y1<<1)-1]='O';

				else ans[(x1-1)<<1][(y1<<1)-1]='O';

			}

			for(int i=1;i<=cnt;i++)

			{

				if(xz[i]||fr(u[i])==fr(v[i]))continue;

				mg(u[i],v[i]);

				int x1=(u[i]-1)/w+1,y1=(u[i]-1)%w+1;

				int x2=(v[i]-1)/w+1,y2=(v[i]-1)%w+1;

				if(x1==x2&&y1+1==y2)ans[(x1<<1)-1][y1<<1]='O';

				else if(x1==x2&&y1-1==y2)ans[(x1<<1)-1][(y1-1)<<1]='O';

				else if(y1==y2&&x1+1==x2)ans[x1<<1][(y1<<1)-1]='O';

				else ans[(x1-1)<<1][(y1<<1)-1]='O';

			}

			for(int i=1;i<h<<1;i++)

			{

				for(int j=1;j<w<<1;j++)pc(ans[i][j]);

				pc('\n');

			}

		}

	}

	fwrite(obuf,p3-obuf,1,stdout);

    return 0;

}