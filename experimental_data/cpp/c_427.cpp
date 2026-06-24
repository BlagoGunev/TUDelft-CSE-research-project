#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

inline int readint() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	int x = 0;
	while (isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

inline long long readlong() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	long long x = 0;
	while (isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define CIR(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define ADJ(i, u) for (int i = hd[u]; i != -1; i = edge[i].nxt)
#define ECH(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define PII pair<int, int>
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(v) v.size()
#define ALL(v) v.begin(), v.end()
#define CLR(v, a) memset(v, a, sizeof(v))
#define IT iterator
#define LL long long
#define ULL unsigned long long
#define DB double
#define PI 3.1415926
#define INF 1000000000

#define N 100005
#define M (3 * N)
#define mod 1000000007

int power[N];
int wht[N];

void init() {
	power[0] = 1;
	REP(i, 1, N - 1) {
		power[i] = (LL) power[i - 1] * 2 % mod;
	}
}

struct SCC {
	
	struct Edge {
		int to, nxt;

		void init(int a, int b) {
			to = a, nxt = b;		
		}
	}edge[M];

	int hd[N];
	int low[N], pre[N], no[N];
	int n, E, id, tdfn;
	stack<int> stk;

	int key[N];
	int cnt[N];

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) {
			hd[i] = -1;
			no[i] = -1;
			pre[i] = 0;
		}
		E = 0, id = 0, tdfn = 0;
	}

	void add(int u, int v) {
		edge[E].init(v, hd[u]);
		hd[u] = E++;
	}

	void dfs(int u) {
		pre[u] = low[u] = ++tdfn;
		stk.push(u);
		ADJ(i, u) {
			int v =	edge[i].to;
			if (!pre[v]) {
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else if (no[v] == -1)
				low[u] = min(low[u], pre[v]);
		}
		if (low[u] == pre[u]) {
			id++;
			while(1) {
				int x = stk.top();
				stk.pop();
				no[x] = id - 1;
				if (x == u) break;
			}
		}
	}

	void run() {
		for (int i = 0; i < n; i++)
			if (pre[i] == 0)
				dfs(i);

		FOR(i, n) {
			key[i] = INF;
		}	

		FOR(i, n) {
			if (key[no[i]] > wht[i]) {
				key[no[i]] = wht[i];
				cnt[no[i]] = 1;
			}
			else if (key[no[i]] == wht[i]) {
				cnt[no[i]]++;
			}
		}
		
		LL res = 1;
		LL kk = 0;

		FOR(i, id) {
			kk += key[i];
			res *= cnt[i];
			res %= mod;		
		}		

		printf("%I64d %I64d\n", kk, res);
	}
}G;

int main() {
	init();
	int n, m, a, b;
	scanf("%d", &n);

	FOR(i, n) {
		scanf("%d", wht + i);
	}

	scanf("%d", &m);

	G.init(n);

	FOR(tt, m) {
		scanf("%d%d", &a, &b);
		--a, --b;
		G.add(a, b);
	}

	G.run();
	return 0;
}