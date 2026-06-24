#include <bits/stdc++.h>
using namespace std;

const int N = 4;

long long a;

void Read()
{
	scanf("%lld", &a);
}

void Solve()
{
	long long res = 1LL;

	while (a > 0)
	{
		if (a % 2) res *= 2;
		a /= 2;
	}

	printf("%lld\n", res);
}

int main() {
	#ifdef __NMH__
		assert(freopen("in.txt", "r", stdin));
		//assert(freopen("out.txt", "w", stdout));
	#endif

	int tc; scanf("%d", &tc);
	while (tc--)
	{
		Read();
		Solve();
	}

	return 0;
}