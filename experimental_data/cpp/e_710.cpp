#include<stdio.h>

#include<iostream>

#include<string.h>

#include<string>

#include<ctype.h>

#include<math.h>

#include<set>

#include<map>

#include<vector>

#include<queue>

#include<bitset>

#include<algorithm>

#include<time.h>

using namespace std;

void fre() { freopen("c://test//input.in", "r", stdin); freopen("c://test//output.out", "w", stdout); }

#define MS(x,y) memset(x,y,sizeof(x))

#define MC(x,y) memcpy(x,y,sizeof(x))

#define MP(x,y) make_pair(x,y)

#define ls o<<1

#define rs o<<1|1

typedef long long LL;

typedef unsigned long long UL;

typedef unsigned int UI;

template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }

template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }

const int N = 1.5e7, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;

int n, X, Y;

LL ans;

void dfs(int x, LL step)

{

	gmin(ans, step + (LL)x * X);

	if (x == 1 || step >= ans)return;

	if (x & 1)

	{

		dfs(x - 1 >> 1, step + X + Y);

		dfs(x + 1 >> 1, step + X + Y);

	}

	else

	{

		dfs(x >> 1, step + Y);

	}

}

LL solve()

{

	ans = 1e18;

	dfs(n, 0);

	return ans;

}

int main()

{

	while (~scanf("%d%d%d", &n, &X, &Y))

	{

		printf("%lld\n", solve());

	}

	return 0;

}

/*

【trick&&吐槽】





【题意】





【类型】





【分析】





【时间复杂度&&优化】





【数据】





*/