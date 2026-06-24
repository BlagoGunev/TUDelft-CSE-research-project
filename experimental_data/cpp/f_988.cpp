#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<bitset>
#include<fstream>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 200000000000ll
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint()
{
	int x=0,p=1;char c=getchar();
	while (c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while (c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//
const int maxn=4000;
int A,m,n;
ll val[maxn],dp[maxn][2];
set<int>sA,sB;
set<pii >S;
set<int>::iterator it,it2;
//
int main()
{
	A=getint();n=getint();m=getint();
	rep(i,n)
	{
		int l=getint(),r=getint();
		sA.insert(l);sB.insert(r);S.insert(mp(l,r));
	}
	rep(i,A+1)val[i]=INF;
	rep(i,m)
	{
		int x=getint();ll y;scanf("%I64d",&y);
		val[x]=min(val[x],y);
	}
	dp[0][0]=0;if(sA.find(0)!=sA.end())dp[0][0]=INF;
	if(val[0]!=INF)dp[0][1]=0;else dp[0][1]=INF;
	for(int i=1;i<=A;i++)
	{
		bool flag=true;
		it=sA.upper_bound(i);
		if(it==sA.begin())flag=false;
		else
		{
			it--;
			it2=sB.lower_bound(i);
			if(S.find(mp(*it,*it2))!=S.end()&&*it2!=i)flag=true;
			else flag=false;
		}
		dp[i][0]=INF;
		if(!flag)
		{
			dp[i][0]=dp[i-1][0];
			rep(j,i)dp[i][0]=min(dp[i][0],dp[j][1]+(1ll*i-j)*val[j]);
		}
		dp[i][1]=INF;
		
		if(val[i]!=INF)dp[i][1]=dp[i-1][0];
		rep(j,i)dp[i][1]=min(dp[i][1],(1ll*i-j)*val[j]+dp[j][1]);
	}
	ll res=min(dp[A][0],dp[A][1]);
	if(res>=INF)printf("%d\n",-1);
	else printf("%I64d\n",res);
	return 0;
}