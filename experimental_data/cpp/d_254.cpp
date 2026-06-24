#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstring>

#include <vector>

#include <queue>

#include <cstdlib>

#include <algorithm>

#include <ctime>

#define pb push_back

#define mp make_pair

#define ff first

#define ss second

using namespace std;



typedef pair<int,int> pii;



const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};



int n,m,d;

char map[1005][1005];

bool vis[30][30];

int val[1005][1005];

int cnt[1005][1005];

vector<pii> rat;

vector<pii> v;

int st[150];

pii p1,p2;



inline int CalcX(int x,int x1)

{

	return 15+x1-x;

}



inline int CalcY(int y,int y1)

{

	return 15+y1-y;

}



inline bool cmp(pii a,pii b)

{

	return val[a.ff][a.ss]<val[b.ff][b.ss];

}



void bfs(int x,int y,int fl)

{

	memset(vis,false,sizeof(vis));

	queue<int> q;

	q.push(x),q.push(y),q.push(0);

	

	while(!q.empty())

	{

		int a,b,D;

		a=q.front(),q.pop();

		b=q.front(),q.pop();

		D=q.front(),q.pop();

		

		if(vis[CalcX(x,a)][CalcY(y,b)])

			continue;

		

		vis[CalcX(x,a)][CalcY(y,b)]=true;

		

		if(fl)

			val[a][b]++;

		else

			cnt[a][b]++;

		

		for(int i=0;i<4;i++)

		{

			int na=a+dx[i],nb=b+dy[i];

			if(na>=1 && na<=n && nb>=1 && nb<=m)

				if(map[na][nb]!='X')

					if(!vis[CalcX(x,na)][CalcY(y,nb)] && D<d)

						q.push(na),q.push(nb),q.push(D+1);

		}

	}

}



int main()

{

	freopen("input.txt","r",stdin);

	freopen("output.txt","w",stdout);

	scanf("%d%d%d",&n,&m,&d);

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

		{

			map[i][j]=getchar();

			while(map[i][j]==' ' || map[i][j]=='\n')

				map[i][j]=getchar();

			if(map[i][j]=='R')

				rat.pb(mp(i,j));

		}

	

	if(rat.size()>300)

	{

		printf("-1\n");

		return 0;

	}

	

	for(int i=0;i<rat.size();i++)

		bfs(rat[i].ff,rat[i].ss,1);

	

	bool AddZero=false;

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			if(val[i][j]>0)

				v.pb(mp(i,j));

			else

				if(map[i][j]=='.' && !AddZero)

				{

					AddZero=true;

					v.pb(mp(i,j));

				}

	

	sort(v.begin(),v.end(),cmp);

	

	int pnt=0,mx=0;

	for(int i=0;i<=150 && pnt<v.size();i++)

	{

		st[i]=pnt;

		while(pnt<v.size() && val[v[pnt].ff][v[pnt].ss]==i)

			pnt++,mx=i;

	}

	

	int lb=(rat.size()+1)/2;

	for(int i=v.size()-1;i>=st[lb];i--)

	{

		p1=v[i];

		

		int nlb=max((int)rat.size()-val[p1.ff][p1.ss],0);

		

		for(int j=st[nlb];j<i;j++)

		{

			p2=v[j];

			

			memset(cnt,0,sizeof(cnt));

			bfs(p1.ff,p1.ss,0);

			bfs(p2.ff,p2.ss,0);

			

			bool flag=true;

			for(int i=0;i<rat.size();i++)

				if(cnt[rat[i].ff][rat[i].ss]==0)

				{

					flag=false;

					break;

				}

			

			if(flag)

			{

				printf("%d %d %d %d\n",p1.ff,p1.ss,p2.ff,p2.ss);

				return 0;

			}

		}

	}

	

	printf("-1\n");

	return 0;

}