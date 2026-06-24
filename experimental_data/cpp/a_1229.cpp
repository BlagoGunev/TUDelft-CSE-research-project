#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 7010
struct Num {long long num1,num2;}num[N];
long long ans; int n,idx; bool is[N];
bool cmp(const Num &a,const Num &b) {return a.num1<b.num1;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&num[i].num1);
	for(int i=1;i<=n;i++) scanf("%lld",&num[i].num2);
	sort(num+1,num+n+1,cmp),idx=1;
	for(int i=2;i<=n;i++)
		if(num[i].num1==num[i-1].num1) is[idx]=true,num[idx].num2+=num[i].num2;
		else num[++idx]=num[i];
	for(int i=idx;i;i--) if(is[i])
	{
		ans+=num[i].num2;
		for(int j=i-1;j;j--) if((num[i].num1&num[j].num1)==num[j].num1) is[j]=true;
	} printf("%lld\n",ans);
}