#include <bits/stdc++.h>
#include <iostream>
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
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-11;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

template<class T> inline void Min(T &a,T b){if(b<a) a=b;}
template<class T> inline void Max(T &a,T b){if(b>a) a=b;}

template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T euclide(T a,T b,T &x,T &y)
{if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}

const int mod=(int) 1e9+7;
const int inf=0x7fffffff;


//const int N=100001;
//int n,m,a[N];
//int low[N+1],dfn[N+1],instack[N+1],tmpdfn;
//int id[N+1],cnt; //cnt����ͨ������  id[i]:�ڵ�i�����ĸ���ͨ����
//stack<int> st;
//vector<int> ve[N],ve1[N];
//void dfs(int u)
//{
//	int j;
//	low[u]=dfn[u]=++tmpdfn;
//	st.push(u);
//	instack[u]=1;
//	for(int i=0;i<ve[u].size();i++)
//	{
//		int v=ve[u][i];
//		if(!dfn[v])
//		{
//			dfs(v);
//			low[u]=min(low[u],low[v]);
//		}
//		else if(instack[v])
//			low[u]=min(low[u],dfn[v]);
//	}
//	if(dfn[u]==low[u])
//	{
//		cnt++;
//		do 
//		{
//			j=st.top();
//			st.pop();
//			instack[j]=0;
//			id[j]=cnt;
//			ve1[cnt].push_back(j);
//		} while (u!=j);
//	}
//}
//int main()
//{
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++)
//		scanf("%d",&a[i]);
//	scanf("%d",&m);
//	int u,v;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&u,&v);
//		ve[u].push_back(v);
//	}
//	tmpdfn=0,cnt=0;
//	for(int i=1;i<=n;i++)
//		if(!dfn[i])
//			dfs(i);
//	int way=1;
//	LL ans=0;
//	for(int i=1;i<=cnt;i++)
//	{
//		int mn=inf,num=0;
//		for(int j=0;j<ve1[i].size();j++)
//			mn=min(mn,a[ve1[i][j]]);
//		for(int j=0;j<ve1[i].size();j++)
//			if(a[ve1[i][j]]==mn)
//				num++;
//		ans+=mn;
//		way=1ll*way*num%mod;
//	}
//	printf("%lld %d\n",ans,way);
//	return 0;
//}


int n,m;
int a[1000001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(2*m>=n)
	{
		printf("%lld\n",2ll*(a[n-1]-a[0]));
		return 0;
	}
	int cnt=n/m;
	LL ans=0;
	for(int i=0;i<cnt/2;i++)
		ans+=(a[n-1-i*m]-a[i*m])*2ll;
	if(cnt/2*m<n-1-cnt/2*m)
		ans+=(a[n-1-cnt/2*m]-a[cnt/2*m])*2ll;
	printf("%lld\n",ans);
	return 0;
}