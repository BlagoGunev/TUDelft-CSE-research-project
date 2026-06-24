#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORU(i,j,k) for(int i=(j);i<=(k);++i)
#define FORD(i,j,k) for(int i=(j);i>=(k);--i)

using namespace std;

using lli = long long int;
using pll = pair<lli, lli>;

const long long int oo = 1000*1000*1000;

struct Coord
{
	int x, y;
	Coord(int x = 0, int y = 0) : x(x), y(y) {}
	Coord operator + (const Coord& droite) const
	{
		return Coord(x + droite.x, y + droite.y);
	}
};


int main()
{
	int n, k, a, b;
	scanf("%d%d%d%d", &n, &k, &a, &b);
	if(a == b)
	{
		FOR(i, n)
			printf(i % 2 ? "G" : "B");
		printf("\n");
		return 0;
	}
	bool revert = a > b;
	if(a > b)
		swap(a, b);
	int lowest = b / (a+1);
	int extra = b % (a+1);
	int maxi = lowest;
	if(extra)
		++maxi;
	if(maxi > k)
	{
		printf("NO\n");
		return 0;
	}
	int size = 0;
	FOR(i, n)
	{
		++size;
		if(size > lowest + (extra > 0))
		{
			size = 0;
			--extra;
			printf(revert ? "B" : "G");
		}
		else
			printf(revert ? "G" : "B");
	}
	printf("\n");
	return 0;
}