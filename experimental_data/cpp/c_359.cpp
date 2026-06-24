#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define UL unsigned LL
#define Pi M_PI
using namespace std;
const int pri=1000000007;
int ksm(int x,int y)
{
	if(!y)return 1;
	int t=ksm(x,y/2);
	if(y&1)
		return (LL)t*t%pri*x%pri;
	return (LL)t*t%pri;
}
bool check(int x,int y,int z)
{
	while(z--)
	{
		if(x%y)
			return 0;
		x/=y;
	}
	return 1;
}
int a[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n,m;
	LL sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		sum+=a[i];
	sort(a+1,a+1+n);
	int d=0;
	LL now=sum-a[n];
	for(int i=n;i;i--)
	{
		while(d%m==0&&now<sum-a[i])
			d/=m,now++;
		if(sum-a[i]==now)
			d++;
		else
		{
			printf("%d",ksm(m,now%(pri-1)));
			return 0;
		}
	}
	while(d%m==0)
		d/=m,now++;
	printf("%d",ksm(m,min(now,sum)%(pri-1)));
	return 0;
}