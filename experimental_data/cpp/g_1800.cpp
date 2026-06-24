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
 
using namespace std;
 
#define _int64 long long
#define mo 998244353

vector<int> a[210000];
int ind[210000];
int p[210000];
map<vector<int>,int> mp;
vector<vector<int> > all;

int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1;
	vector<int> q;
	vector<int> aa;
	set<int> st;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			a[i].clear();
			p[i]=-1;
		}
		for (i=0;i+1<n;i++)
		{
			scanf("%d%d",&x,&y);
			x--;y--;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		all.clear();
		mp.clear();
		q.clear();
		q.push_back(0);
		for (i=0;i<q.size();i++)
		{
			x=q[i];
			for (j=0;j<a[x].size();j++)
			{
				y=a[x][j];
				if (y==p[x]) continue;
				p[y]=x;
				q.push_back(y);
			}
		}
		m=1;
		aa.clear();
		mp[aa]=0;
		all.push_back(aa);
		for (i=q.size()-1;i>=0;i--)
		{
			x=q[i];
			aa.clear();
			for (j=0;j<a[x].size();j++)
			{
				y=a[x][j];
				if (y==p[x]) continue;
				aa.push_back(ind[y]);
			}
			sort(aa.begin(),aa.end());
			if (mp.find(aa)==mp.end())
			{
				all.push_back(aa);
				mp[aa]=m;
				m++;
			}
			ind[x]=mp[aa];
		}/*
		for (i=0;i<n;i++)
			cerr<<"ind:"<<i<<" "<<ind[i]<<endl;
		*/
		x=m-1;
		b1=0;
		while (1)
		{
			//cerr<<"x:"<<x<<endl;
			st.clear();
			for (j=0;j<all[x].size();j++)
			{
				y=all[x][j];
				if (st.find(y)==st.end()) st.insert(y);
				else st.erase(y);
			}
			//cerr<<"size:"<<st.size()<<endl;
			if (st.empty())
			{
				b1=1;
				break;
			}
			if (st.size()>=2) break;
			x=*st.begin();
		}
		if (b1==1) printf("YES\n");
		else printf("NO\n");
	}
}