#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <ctime>


using namespace std;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

inline int myrand() {
	return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
	return myrand() % x;
}

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

const int maxn = (int)1e5 + 10;
char s[maxn];
int a[maxn], b[maxn];

bool read(int *a, int &n) {
	if (scanf("%s", s) < 1)
		return false;
	n = strlen(s);
  for (int i = 0; i < n; ++i) {
		a[n - 1 - i] = s[i] - '0';	
	}

	while (n && a[n - 1] == 0)
		--n;
	return true;
}

bool solve() {
	int n, m;
	if (!read(a, n) || !read(b, m))
		return 0;
	
	int t = max(n, m);
	for (int i = n; i < t; ++i)
		a[i] = 0;
 	for (int i = m; i < t; ++i)
 		b[i] = 0;

 	int cm = 0;
 	int toadd = 0;
 	for (int i = t - 1; i >= 0; --i) {
 		int val = a[i] - b[i];
 		if (cm != 0) {
 			if (cm * val != -1) {
 				printf("%c\n", cm > 0 ? '>' : '<');
 				return 1;
 			}
 			toadd = cm;
 			cm = 0;
 			continue;
 		}
 		
 		val += toadd;
 		toadd = 0;

 		if (abs(val) == 2) {
 			printf("%c\n", val > 0 ? '>' : '<');
 			return 1;
 		}
 		if (val)
 			cm = val;
 	}
 	//eprintf("%d %d\n", cm, toadd);
 	if (cm > 0 || toadd > 0) {
 		printf(">\n");
 		return 1;
 	}
 	if (cm < 0 || toadd < 0) {
 		printf("<\n");
 		return 1;
 	}

 	printf("=\n");
	return 1;
}

int main() {
	srand(rdtsc());
#ifdef DEBUG
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif
	
	while (1) {
		if (!solve())
			break;
		#ifdef DEBUG
			eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
		#endif
	}
	return 0;
}