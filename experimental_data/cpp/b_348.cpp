#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 100010
int64_t a[maxn];
int last[maxn],t1,t2;
int64_t sa[maxn];
int64_t maxs[maxn];
int64_t sum[maxn];
struct edges{
	int from,to;
}edge[maxn*2];
int64_t gcd(int64_t a,int64_t b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
void dfs(int v,int pre){
	if(a[v]!=0){
		sa[v]=1;maxs[v]=a[v];sum[v]=1;
		return;
	}
	int ptr=last[v];
	sa[v]=1;sum[v]=0;
	while(ptr!=-1){
		if(edge[ptr].to!=pre){
			dfs(edge[ptr].to,v);
			if(sa[edge[ptr].to]<=0){
				sa[v]=1;maxs[v]=0;return;
			}
			int64_t tmp2=gcd(sa[v],sa[edge[ptr].to]);
			if(tmp2)sa[v]=sa[v]*sa[edge[ptr].to]/tmp2;
			sum[v]++;
		}ptr=edge[ptr].from;
	}
	ptr=last[v];
	int64_t tmp=-1;
	while(ptr!=-1){
		if(edge[ptr].to!=pre){
			if(tmp==-1)tmp=maxs[edge[ptr].to]/sa[v]*sa[v];
			else tmp=min(tmp,maxs[edge[ptr].to]/sa[v]*sa[v]);
		}ptr=edge[ptr].from;
	}
	maxs[v]=tmp*sum[v];
	sa[v]*=sum[v];
	if(maxs[v]==0)sa[v]=1;
	return;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int64_t ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			last[i]=-1;ans+=a[i];
		}
		for(int i=1;i<n;i++){
			scanf("%d %d",&t1,&t2);
			edge[i*2].from=last[t1];last[t1]=i*2;edge[i*2].to=t2;
			edge[i*2+1].from=last[t2];last[t2]=i*2+1;edge[i*2+1].to=t1;
		}
		dfs(1,0);

		printf("%lld\n",ans-maxs[1]);
	}
	return 0;
}