#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

#define MOD 1000000007

int A[1 << 20];
int L[1 << 10];
Int C[1 << 10][1 << 10];
Int Fact[1 << 20];

int F(int a)
{
	while(a != 0)
	{
		if(a % 10 != 4 && a % 10 != 7)
			return 0;

		a /= 10;
	}

	return 1;
}

Int G(int a)
{
	Int res = 1;
	int i;
	FOR(i, 0, a)
	{
		res *= i + 1;
		res %= MOD;
	}

	return res;
}

Int Pow(Int a, int b)
{
	Int res = 1;
	int i;
	for(i = 1; i <= b; i <<= 1)
	{
		if(b & i)
		{
			res *= a;
			res %= MOD;
		}

		a *= a;
		a %= MOD;
	}

	return res;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	int i, j;
	FOR(i, 0, n)
		scanf("%d", &A[i]);

	sort(A, A + n);
	int prev = 0;
	int cnt = 0;
	int m = 0;
	FOR(i, 1, n + 1)
		if(i == n || A[i] != A[i - 1])
		{
			if(F(A[i - 1]) != 0)
			{
				L[cnt] = i - prev;
				++cnt;
			}
			else
				m += i - prev;

			prev = i;
		}

	Fact[0] = 1;
	FOR(i, 1, 1 << 17)
		Fact[i] = Fact[i - 1]*i % MOD;

	CLEAR(C, 0);
	C[0][0] = 1;
	FOR(i, 0, cnt)
		FOR(j, 0, i + 1)
		{
			C[i + 1][j] += C[i][j];
			C[i + 1][j] %= MOD;

			C[i + 1][j + 1] += C[i][j]*L[i];
			C[i + 1][j + 1] %= MOD;
		}
/*
	FOR(i, 0, cnt + 1)
	{
		C[cnt][i] *= Fact[i];
		C[cnt][i] %= MOD;
	}
*/
	Int res = 0;
	FOR(i, 0, cnt + 1)
		if(i <= k && k - i <= m)
		{
			Int a = Fact[m]*Pow(Fact[m - (k - i)]*Fact[k - i] % MOD, MOD - 2) % MOD;
			res += a*C[cnt][i] % MOD;
		}


	printf("%d\n", int(res % MOD));
	return 0;
};