// Nothing is Given, Everything is Earned.

#include<bits/stdc++.h>

using namespace std;

#define updmax(i_,j_) ((i_)<(j_)?(i_)=(j_),1:0)

#define updmin(i_,j_) ((i_)>(j_)?(i_)=(j_),1:0)

using L=long long;



const int N=15,M=120;

int n,m,x[N],y[N];

struct dot{ int X,Y,t; } d[M];

L diss[1<<N][M],dis[M][M];

L f[1<<N][M],g[1<<N][M];



int main()

{

	cin>>n>>m;

	for(int i=0;i<n;i++)

		cin>>x[i]>>y[i],

		d[i+m]={x[i],y[i],0};

	for(int i=0;i<m;i++)

		cin>>d[i].X>>d[i].Y>>d[i].t;

	sort(d,d+m,[](dot i,dot j) { return i.t<j.t; });



	for(int i=0;i<m;i++) for(int j=0;j<n+m;j++)

		dis[i][j]=abs(d[i].X-d[j].X)+abs(d[i].Y-d[j].Y);

	for(int mask=0;mask<(1<<n);mask++)

	{

		for(int i=0;i<n+m;i++)

		{

			diss[mask][i]=LLONG_MAX/3;

			for(int j=0;j<n;j++) if(mask>>j&1)

				updmin(diss[mask][i],abs(x[j]-d[i].X)+abs(y[j]-d[i].Y));

		}

	}



	memset(f,63,sizeof(f));

	memset(g,192,sizeof(g));

	for(int i=0;i<n;i++) f[1<<i][0]=0;

	for(int i=0;i<m;i++) g[0][i]=1;



	for(int mask=0;mask<1<<n;mask++)

	{

		for(int i=0;i<m;i++)

		{

			for(int j=i;~j;j--) if(f[mask][j]+diss[mask][i]<=d[i].t)

			{

				updmax(g[mask][i],j+1);

				break;

			}

			for(int j=0;j<i;j++)

				if(d[j].t+dis[j][i]<=d[i].t)

					updmax(g[mask][i],g[mask][j]+1);

			if(g[mask][i]<0) continue;



			updmin(f[mask][g[mask][i]],d[i].t);

			for(int j=0;j<n;j++) if(!(mask>>j&1))

				updmin(f[mask|1<<j][g[mask][i]],d[i].t+dis[i][j+m]);

		}



		for(int i=0;i<=m;i++)

			for(int j=0;j<n;j++) if(!(mask>>j&1))

				updmin(f[mask|1<<j][i],f[mask][i]+diss[mask][j+m]);

	}



	for(int i=m;~i;i--) for(int mask=0;mask<1<<n;mask++)

		if(f[mask][i]<LLONG_MAX/3)

		{

			cout<<i<<endl;

			return 0;

		}

	return 0;

}