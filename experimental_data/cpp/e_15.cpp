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

#define MOD 1000000009

Int Res[1 << 19];
Int A[1 << 19];

int main()
{
	int N;
	scanf("%d", &N);
	N >>= 1;

	int i;

	A[0] = 1;
	FOR(i, 1, N)
		A[i] = (3 + 2*A[i - 1]) % MOD;

	Res[0] = 2;
	Int mul = A[0];
	FOR(i, 1, N)
	{
		Res[i] = (Res[i - 1] + 4*mul) % MOD;
		mul = mul*A[i] % MOD;
	}

	printf("%d\n", int((2 + 2*Res[N - 1]*Res[N - 1]) % MOD));

	return 0;
};