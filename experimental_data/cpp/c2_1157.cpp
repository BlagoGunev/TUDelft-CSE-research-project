// #include C/C++ {
#include <bits/stdc++.h>
// }
using namespace std;
// #typedef {
typedef long long int64;
typedef pair <int, int> PII;
typedef pair <int64, int64> PLL;
// }

// #parameter{
#ifdef DEBUG_MODE

#define TYPE decltype
#define RF(filename) {freopen((filename), "r", stdin);}
#define WF(filename) {freopen((filename), "w", stdout);}
#define DF(filename) {freopen((filename), "w", stderr);}
#define eprintf printf

#else

#define TYPE __typeof
#define RF(filename) {;}
#define WF(filename) {;}
#define DF(filename) {;}
#define eprintf(...)
#define fprintf(...)

#endif

// #define {
#define SZ(a) ((int)(a).size())
#define X first
#define Y second
#define MP make_pair
#define L(x) ((x)<<1)
#define R(x) ((x)<<1 | 1)
#define max3(x, y, z) (max(max((x), (y)), (z)))
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ALL(it) (it).begin(), (it).end()
#define FILL(__space, __val) memset(__space, __val, sizeof(__space))
#define MOVE(__spaceTo, __spaceFrom) memmove(__spaceTo, __spaceFrom, sizeof(__spaceTo))
#define UNIQUE(__vector) sort(ALL(__vector)), __vector.resize(unique(ALL(__vector)) - __vector.begin())
#define FOR(it, c) for( TYPE((c).begin()) it = (c).begin(); it != (c).end(); it++)
/////////////////////////////////////////////////////////////
const double PI = acos(-1.0);
const double EPS = 1e-6;

#define MAX_N 200005
#define MAX_M 55
#define MOD (int)(1e9+7)
#define INF ((1 << 30) - 1)
#define BINF ((1LL << 62) - 1LL)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
int main() {
	RF("input.txt");
	//  WF("output.txt");
	DF("err.txt");

	int n;
	scanf("%d", &n);
	int a[MAX_N];
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	string res;
	int lptr = 0, rptr = n - 1;
	int last = 0;
	while (lptr <= rptr) {
		eprintf("@ %d %d\n", lptr, rptr);
		if (lptr == rptr) {
			if (a[lptr] > last) res.push_back('L');
			break;
		}
		else if (a[lptr] < a[rptr]) {
			if (a[lptr] > last) {
				last = a[lptr++];
				res.push_back('L');
			}
			else if (a[rptr] > last) {
				last = a[rptr--];
				res.push_back('R');
			}
			else
				break;
		}
		else if (a[lptr] > a[rptr]) {
			if (a[rptr] > last) {
				last = a[rptr--];
				res.push_back('R');
			}
			else if (a[lptr] > last) {
				last = a[lptr++];
				res.push_back('L');
			}
			else break;
		}
		else {
			if (a[lptr] <= last) break;

			int left_count = 0;
			for (int i = lptr + 1; i < rptr and a[i] > a[i - 1]; i++) left_count = i - lptr + 1;
			int right_count = 0;
			for (int j = rptr - 1; j > lptr and a[j] > a[j + 1]; j--) right_count = rptr - j + 1;
			if (left_count == 0 and right_count == 0) {
				res.push_back('L');
			}
			else if (left_count > right_count) {
				while (left_count--) res.push_back('L');
			}
			else {
				while (right_count--) res.push_back('R');
			}
			break;
		}
	}
	printf("%d\n", res.size());
	puts(res.c_str());

	return 0;
}