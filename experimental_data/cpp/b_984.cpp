#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define ALL(u) (u).begin(),(u).end()

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

typedef pair<int, int> PII;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

const int MR = 110;

int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
int dy[8] = { -1,1,0,0,-1,1,-1,1 };

int n, m;

bool ok(int x, int y, int k)
{
	return x + dx[k] < n && x + dx[k] >= 0 && y + dy[k] < m && y + dy[k] >= 0;
}

char t[MR][MR];

bool isValid(int x, int y)
{
	if (t[x][y] == '.')
	{
		REP(i, 8)
			if (ok(x, y, i) && t[x + dx[i]][y + dy[i]] == '*')
				return 0;
	}

	if (t[x][y] > '0' && t[x][y] < '9')
	{
		int ile = t[x][y] - '0';
		int cnt = 0;
		REP(i, 8)
			if (ok(x, y, i) && t[x + dx[i]][y + dy[i]] == '*')
				cnt++;

		if (cnt != ile)
			return 0;
	}

	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	REP(i, n)
		scanf("%s", t[i]);

	REP(i,n)REP(j,m)
		if (!isValid(i, j))
		{
			printf("NO\n");
			return 0;
		}

	printf("YES\n");

	return 0;
}