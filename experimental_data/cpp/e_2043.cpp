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

int a[1100][1100];
int b[1100][1100];

int dd[2][1100];
int in1[2][1100];
vector<pair<int,int> > aa[2][1100];
vector<pair<int,int> > q;

void add1(int ty,int x)
{
	if (dd[ty][x]==1) return;
	dd[ty][x]=1;
	q.push_back(make_pair(ty,x));
}

int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,x1,x2,ty,v1,v2,cnt,ty1;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d",&m,&n);
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				scanf("%d",&b[i][j]);
		b1=1;
		for (o=0;o<30;o++)
		{
			q.clear();
			memset(dd,0,sizeof(dd));
			for (i=0;i<m;i++)
				for (j=0;j<n;j++)
				{
					if (((1<<o)&a[i][j])==0) x1=0;
					else x1=1;
					if (((1<<o)&b[i][j])==0) x2=0;
					else x2=1;
					if (x1!=x2)
					{
						if (x1==0)
							add1(0,j);
						else add1(1,i);
					}
				}
			for (i=0;i<2;i++)
				for (j=0;j<1100;j++)
					aa[i][j].clear();
			memset(in1,0,sizeof(in1));
			for (i=0;i<q.size();i++)
			{
				ty=q[i].first;
				x=q[i].second;
				if (ty==0)
				{
					for (j=0;j<m;j++)
					{
						x1=1;
						if (((1<<o)&b[j][x])==0) x2=0;
						else x2=1;
						if (x1!=x2)
						{
							aa[ty][x].push_back(make_pair(1,j));
							in1[1][j]++;
							add1(1,j);
						}
					}
				}
				else
				{
					for (j=0;j<n;j++)
					{
						x1=0;
						if (((1<<o)&b[x][j])==0) x2=0;
						else x2=1;
						if (x1!=x2)
						{
							aa[ty][x].push_back(make_pair(0,j));
							in1[0][j]++;
							add1(0,j);
						}
					}
				}
			}
			cnt=q.size();
			q.clear();
			for (i=0;i<2;i++)
				for (j=0;j<1100;j++)
					if ((dd[i][j]==1)&&(in1[i][j]==0))
					{
						q.push_back(make_pair(i,j));
					}
			for (i=0;i<q.size();i++)
			{
				ty=q[i].first;
				x=q[i].second;
				for (j=0;j<aa[ty][x].size();j++)
				{
					ty1=aa[ty][x][j].first;
					x1=aa[ty][x][j].second;
					in1[ty1][x1]--;
					if (in1[ty1][x1]==0)
					{
						q.push_back(make_pair(ty1,x1));
					}
				}
			}
			if (q.size()!=cnt)
			{
				b1=0;break;
			}
		}
		if (b1==1) printf("Yes\n");
		else printf("No\n");
	}
}