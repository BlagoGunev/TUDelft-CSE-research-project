#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long LL;
#define FOR(x, b, e) for (int x = (b); x <= (e); ++x)
#define FORD(x, b, e) for (int x = (b); x >= (e); --x)
#define REP(x, n) for (int x = 0; x < (n); ++x)
#define VAR(v, n) typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int) (x).size())
#define EACH(i, c) for (VAR(i, (c).begin()); i != (c).end(); ++i)
#define REACH(i, c) for (VAR(i,(c).rbegin()); i != (c).rend(); ++i)
#define UNIQUE(v) do { sort(ALL(v)); (v).resize(unique(ALL(v)) - (v).begin()); } while (0)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define skip continue
const int INF = 1000000001;

#define GET(x)			(scanf("%d", &(x)) == 1)
#define GET2(x, y)		(scanf("%d %d", &(x), &(y)) == 2)
#define GET3(x, y, z)	(scanf("%d %d %d", &(x), &(y), &(z)) == 3)
#define GETS(x)			(scanf("%s", (x)) == 1)
#define DGET(x)			int x; GET(x);

const int N = 1001;

char A[N][N];
int r, c;
bool VR[N], VC[N];

queue<pair<int,int> > Q;

void go_row(int y, int t) {
	if (!y) {
		printf("%d\n", t);
		exit(0);
	}
	VR[y] = 1;
	++t;
	t = -t;
	REP (x, c) {
		if (A[y][x] == '#' && !VC[x]) {
			Q.push(MP(x, t));
			VC[x] = 1;
		}
	}
}
void go_col(int x, int t) {
	t = -t;
	++t;
	REP (y, r) {
		if (A[y][x] == '#' && !VR[y]) {
			Q.push(MP(y, t));
			VR[y] = 1;
		}
	}
}

#define FORQ(x, Q) for (typeof((Q).front()) x; !(Q).empty() && (x = (Q).front(), (Q).pop(), true); )

int main()
{
	GET2(r, c);
	
	REP (y, r) {
		GETS(A[y]);
	}
	
	go_row(r-1, 0);
	
	FORQ (x, Q) {
		if (x.ND > 0) { // row
			go_row(x.ST, x.ND);
		} else {
			go_col(x.ST, x.ND);
		}
	}
	
	puts("-1");
}