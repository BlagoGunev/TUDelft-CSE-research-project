#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <chrono>
 
using namespace std;
 
#define _int64 long long
#define mo 998244353

int neigh[3][2]={{0,0},{0,1},{1,0}};

int a[200][3];

int sr[11000];
int sc[11000];


int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,qq,z,now,ind,xx,yy,ans,tmpind,tt;
	vector<pair<int,pair<int,int> > > a;
	vector<pair<int,int> > q[2];
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d",&m,&n);
		for (i=0;i<=m;i++)
			sr[i]=0;
		for (i=0;i<=n;i++)
			sc[i]=0;
		vector<vector<int> > can=vector<vector<int> >(m+1,vector<int>(n+1,0));
		scanf("%d",&qq);
		a.clear();
		for (o=0;o<qq;o++)
		{
			scanf("%d%d%d",&x,&y,&z);
			a.push_back(make_pair(x,make_pair(y,z)));
		}
		sort(a.begin(),a.end());
		now=0;ind=0;
		q[0].clear();
		q[0].push_back(make_pair(0,0));
		ans=-1;
		for (tt=1;;tt++)
		{
			if (q[now].size()==0) break;
			tmpind=ind;
			while ((ind<a.size())&&(a[ind].first==tt))
			{
				if (a[ind].second.first==1)
				{
					sr[a[ind].second.second]=1;
				}
				else
				{
					sc[a[ind].second.second]=1;
				}
				ind++;

			}
			q[1-now].clear();
			for (i=0;i<q[now].size();i++)
			{
				x=q[now][i].first;
				y=q[now][i].second;
				for (k=0;k<3;k++)
				{
					xx=x+neigh[k][0];
					yy=y+neigh[k][1];
					if ((xx>=0)&&(xx<=m)&&(yy>=0)&&(yy<=n))
					{
						if (sr[xx]==1) continue;
						if (sc[yy]==1) continue;
						if (can[xx][yy]==1) continue;
						q[1-now].push_back(make_pair(xx,yy));
						can[xx][yy]=1;
					}
				}
			}

			for (i=tmpind;i<ind;i++)
			{
				if (a[i].second.first==1)
				{
					sr[a[i].second.second]=0;
				}
				else
				{
					sc[a[i].second.second]=0;
				}
			}
			if (can[m][n]==1)
			{
				ans=tt;
				break;
			}
			now=1-now;
			for (i=0;i<q[now].size();i++)
			{
				x=q[now][i].first;
				y=q[now][i].second;
				can[x][y]=0;
			}
		}
		printf("%d\n",ans);
	}
}