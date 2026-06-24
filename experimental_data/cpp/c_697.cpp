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

const int N = 0, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;

int n;

map<LL, LL>mop;

void add(LL x, LL y, LL z)

{

	while (x != y)

	{

		if (y > x)swap(x, y);

		mop[x] += z;

		x >>= 1;

	}

}

LL check(LL x, LL y)

{

	LL sum = 0;

	while (x != y)

	{

		if (y > x)swap(x, y);

		if (mop.count(x))sum += mop[x];

		x >>= 1;

	}

	return sum;

}

int main()

{

	while (~scanf("%d", &n))

	{

		mop.clear();

		int op;

		LL x, y, z;

		for (int i = 1; i <= n; ++i)

		{

			scanf("%d", &op);

			if (op == 1)

			{

				scanf("%lld%lld%lld", &x, &y, &z);

				add(x, y, z);

			}

			else

			{

				scanf("%lld%lld", &x, &y);

				printf("%lld\n", check(x, y));

			}

		}

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