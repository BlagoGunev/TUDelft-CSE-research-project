//In the name of Allah
//
//
//////////////////////
// Program: 
// Written By Alireza Farhadi (LGM)
//////////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <vector>
#include <bitset>
#include <deque>
#include <iomanip>
#include <complex>
#include <fstream>
#include <sstream>
#include <map>
//#include <climits>
//#include <list>

using namespace std;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define show(x) cerr<<((#x))<<" = "<<((x))<<" "<<endl
#define bit(a,b) (((a)>>(b))&1)
#define gcd __gcd
#define endl '\n'
#define bcnt(x) ((__builtin_popcount(x)))
#define sz(x) ((int((x).size())))
#define sqr(x) ((((x))*((x))))
#define fx(x) fixed<<setprecision(x)

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T rev(const T & a){T _=a; reverse(_.begin(),_.end()); return _;}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pie;

const double eps=1e-9;
const ld leps=1e-14;
const int MN=100*1000+100;
int n,m,k;
bool mark[MN];
int par[MN][20];
int up[MN];
int h[MN];
int d[MN];
bool is[MN];
vector <int> list[MN];
int s,e,res;
void dfs(int a)
{
	mark[a]=1;
	up[a]=h[a];
	for (int i=0;i<list[a].size();i++) if (mark[list[a][i]])
	{
		int v=list[a][i];
		if (v!=par[a][0])
			smn(up[a],h[v]);
	}
	for (int i=0;i<list[a].size();i++) if (!mark[list[a][i]])
	{
		par[list[a][i]][0]=a;
		int v=list[a][i];
		h[v]=h[a]+1;
		for (int i=1;i<20;i++)
		{
			int t=par[v][i-1];
			if (t==-1)
				par[v][i]=-1;
			else
				par[v][i]=par[t][i-1];
		}
		dfs(v);
		smn(up[a],up[v]);
	}
	if (up[a]==h[a]) is[a]=1;
}
void dfs2(int a)
{
	mark[a]=1;
	for (int i=0;i<list[a].size();i++) if (!mark[list[a][i]])
	{
		int v=list[a][i];
		d[v]=d[a]+is[v];
		dfs2(v);
	}
}
int nup(int a,int b)
{
	for (int i=19;i>=0;i--) if (b>=(1<<i))
	{
		a=par[a][i];
		b-=(1<<i);
	}
	return a;
}
int lca(int a,int b)
{
	if (h[a]<h[b]) swap(a,b);
	a=nup(a,h[a]-h[b]);
	if (a==b) return a;
	for (int i=19;i>=0;i--) if (par[a][i]!=-1 && par[b][i]!=-1 && par[a][i]!=par[b][i])
	{
		a=par[a][i];
		b=par[b][i];
	}
	if (a==b) return a;
	return par[a][0];
}
int calc()
{
	int t=lca(s,e);
	return d[s]+d[e]-2*d[t];
}
int main(int argc,char * argv[])
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b; a--; b--;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	for (int i=0;i<20;i++) par[0][i]=-1;
	dfs(0);
	memset(mark,0,sizeof(mark));
	dfs2(0);
	cin>>k;
	for (int i=0;i<k;i++)
	{
		cin>>s>>e; s--; e--;
		cout<<calc()<<endl;
	}
	return 0;
}