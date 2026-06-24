#include <bits/stdc++.h>
#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstring>

#include <algorithm>

#include <vector>

#include <map>

#include <cstdlib>

#include <set>

using namespace std;



#define X first

#define Y second

#define Mod 1000000007

#define N 100010

typedef long long ll;

typedef pair<int,int> pii;



inline int Mul(int x,int y){return 1ll*x*y%Mod;}

inline int Add(int x,int y){return ((x+y)%Mod+Mod)%Mod;}



int n;

ll v[N];



int main()

{

	//freopen("in.in","r",stdin);

	//freopen("out.out","w",stdout);

	

	scanf("%d",&n);

	for (int i=1;i<=n;i++) scanf("%lld",&v[i]),v[i]+=v[i-1];

	sort(v+1,v+n+1);

	

	int Ans=0,cnt=0;

	for (int i=1;i<=n;i++)

	{

		if (i==1 || v[i]!=v[i-1]) cnt=1;

		else cnt++;

		Ans=max(Ans,cnt);

	}

	printf("%d\n",n-Ans);

	

	return 0;

}