#include <bits/stdc++.h>
#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

using namespace std;

typedef int64_t ll;

int tree[3005],n,x,ans;

#define lowbit(x) x&(-x) 

void add(int x){while(x<=n){tree[x]++;x+=lowbit(x);}}

int sum(int x){int s=0;while(x){s+=tree[x];x-=lowbit(x);}return s;}

int main()

{

	scanf("%d",&n);

	for(int i=0;i<n;i++)

	{

		scanf("%d",&x);

		ans+=sum(n-x+1);

		add(n-x+1);

	}

    printf("%d",(ans&1)?ans*2-1:ans*2);

}