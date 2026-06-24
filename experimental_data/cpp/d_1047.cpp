#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

#define INF 987654321
#define ll long long

ll N, M;

int main()
{
	scanf("%lld %lld", &N, &M);
	if (N > M) swap(N, M);

	ll res = 0;

	if (N == 1)
	{
		if (M % 6 == 0) res = M / 2;
		else if (M % 6 == 1) res = (M - 1) / 2;
		else if (M % 6 == 2) res = (M - 2) / 2;
		else if (M % 6 == 3) res = (M - 3) / 2;
		else if (M % 6 == 4) res = (M - 4) / 2 + 1;
		else if (M % 6 == 5) res = (M - 5) / 2 + 2;
		res *= 2;
	}
	else if (N == 2)
	{
		if (M == 2) res = 0;
		else if (M == 3) res = 4;
		else if (M == 7) res = 12;
		else res = N * M;
	}
	else
	{
		res = N * M;
		if (N % 2 == 1 && M % 2 == 1) res--;
	}
	
	printf("%lld", res);
	return 0;
}