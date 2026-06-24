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

const int N = 1e6+10, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;

int n;

int main()

{

	while (~scanf("%d", &n))

	{

		if (n == 1)

		{

			puts("0");

			continue;

		}



		int ans = 1e9;

		for (int j = n - 1; j; --j)

		{

			int x = n;

			int y = j;

			int step = 0;

			while (x > 1 || y > 1)

			{

				if (y == 1)

				{

					step += x - 1;

					break;

				}

				x -= y;

				if (x < y)swap(x, y);

				if (++step >= ans)break;

			}

			gmin(ans, step);

		}

		printf("%d\n", ans);

	}

}