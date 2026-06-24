// LUOGU_RID: 158349485
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>

#define int long long

using namespace std;

const int N = 3e5 + 10;
const int M = 4400010;
const int MV = M + 100;

int n;
int a[N];

int gt1;
int gt[M];
set<int> rs, nw, ti;
int ans;
int gcd(int a, int b)
{
	if(!b){return a;}
	return gcd(b, a % b);
}
int lcm(int a, int b)
{
	int res = a * b;
	res /= gcd(a, b);
	return res;
}

signed main()
{
//	pre();
	
	int T; scanf("%lld", &T);
	while(T --)
	{
		gt1 = 0;
		ans = 1e9 + 7;
		rs.clear(); nw.clear();
		
		scanf("%lld", &n);
		for(int i = 1; i <= n; i ++)
		{
			scanf("%lld", &a[i]);
			if(a[i] == 1){gt1 = 1;}
		}
		
		if(!gt1){puts("1"); continue;}
		for(int i = n; i >= 1; i --)
		{
			ti.clear();
			if(a[i] <= M){ti.insert(a[i]);}
			for(auto j : nw)
			{
//				cout << "[" << j << "," << a[i] << "]=";
				int tm = lcm(j, a[i]);
//				cout << tm << "\n";
				if(tm <= M){ti.insert(tm);}
			}
			nw.clear();
			for(auto j : ti){rs.insert(j); nw.insert(j);}
		}
		for(auto j : rs){gt[j] = 1;}
		for(auto j : rs)
		{
			if(j - 1 > 0)
			{
				if(!gt[j - 1]){ans = min(ans, j - 1);}
			}
			if(!gt[j + 1]){ans = min(ans, j + 1);}
		}
		for(auto j : rs){gt[j] = 0;}
		
//		cout << "ANS:";
		printf("%lld\n", ans);
	}
	
	return 0;
}