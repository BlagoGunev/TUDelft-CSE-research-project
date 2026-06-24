#include <bits/stdc++.h>
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

#include <cstring>

#include <fstream>

using namespace std;

typedef int64_t ll;

const int V=2000005;

const int E=2000005;

int to0[E<<1],to1[E<<1],id0[E<<1],id1[E<<1],nxt0[E<<1],nxt1[E<<1];

int head0[V],head1[V],cnt0,cnt1;

int fa[V],son[V],dep[V],edg[V];

bool vis[V];

void addedge(int u,int v,int edgeid)

{

	to0[cnt0]=v;id0[cnt0]=edgeid;nxt0[cnt0]=head0[u];head0[u]=cnt0++;

	to0[cnt0]=u;id0[cnt0]=edgeid;nxt0[cnt0]=head0[v];head0[v]=cnt0++;

}



void adde(int u,int v,int edgeid)

{

	to1[cnt1]=v;id1[cnt1]=edgeid;nxt1[cnt1]=head1[u];head1[u]=cnt1++;

}



void dfs(int s)

{

	vis[s]=true;

	for(int i=head0[s];i!=-1;i=nxt0[i])

	{

		int v=to0[i];

		if(v==fa[s])continue;

		if(!vis[v])

		{

			edg[v]=id0[i];

			dep[v]=dep[s]+1;

			son[s]=v;

			fa[v]=s;

			dfs(v);

		}

		else if(dep[v]<dep[s])

			adde(son[v],s,id0[i]);

	}

}



pair<int,int> que[V<<1];

int dire[E];



void bfs(int t)

{

	int tal=0,hed=0;

	queue<pair<int,int> > que;

	que.push(make_pair(t,0));

	while(!que.empty())

	{

		pair<int,int> pii=que.front();

		int u=pii.first,di=pii.second;

		que.pop();

		while(fa[u]!=-1 && dire[edg[u]]==-1)

		{

			dire[edg[u]]=di;

			for(int i=head1[u];i!=-1;i=nxt1[i])

			{

				int v=to1[i];

				dire[id1[i]]=di;

				que.push(make_pair(v,di^1));

			}

			u=fa[u];

		}

	}

}



int tu[V],tv[V];



int main()

{

	int T,n,m,s,t,i;

	scanf("%d",&T);

	while(T--)

	{

		bool flag=false;

		scanf("%d%d%d%d",&n,&m,&s,&t);

		memset(dire,-1,sizeof(int)*(m+3));

		memset(vis,0,sizeof(bool)*(n+3));

		memset(head0,-1,sizeof(int)*(n+3));cnt0=0;

		memset(head1,-1,sizeof(int)*(n+3));cnt1=0;

		for(i=0;i<m;i++)

		{

			scanf("%d%d",tu+i,tv+i);

			addedge(tu[i],tv[i],i);

		}

		dep[s]=0;fa[s]=-1;

		dfs(s);

		bfs(t);

		for(i=0;i<m;i++)

		{

			if(dire[i]==-1){flag=true;break;}

		}

		if(flag)puts("No");

		else

		{

			puts("Yes");

			for(i=0;i<m;i++)

			{

				if((dep[tu[i]]<dep[tv[i]])==dire[i])tu[i]^=tv[i]^=tu[i]^=tv[i];

				printf("%d %d\n",tu[i],tv[i]);

			}

		}

	}

	return 0;

}