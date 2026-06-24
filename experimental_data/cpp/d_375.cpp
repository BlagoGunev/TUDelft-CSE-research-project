/***************************************

	  Authur : zzblack                **

	  Created: 2016-08-26             **

	  Orz                             **

****************************************/

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <ctime>

#include <cmath>

#include <string>

#include <cctype>

#include <cstdio>

#include <vector>

#include <bitset>

#include <cstdlib>

#include <cstring>

#include <iomanip>

#include <sstream>

#include <iostream>

#include <assert.h>

#include <algorithm>

using namespace std;

#define ls id<<1,l,mid

#define rs id<<1|1,mid+1,r

#define OFF(x) memset(x,-1,sizeof x)

#define CLR(x) memset(x,0,sizeof x)

#define MEM(x) memset(x,0x3f,sizeof x)

typedef long long ll ;

typedef unsigned long long ull ;

typedef pair<int,int> pii ;

const int maxn = 1e5 + 50 ;

const int maxm = 1e6 + 50;

const double eps = 1e-10;

const int max_index = 26;

const int inf = 0x3f3f3f3f ;

const int MOD = 1e9+7 ;

const double PI = acos(-1.);



inline int read(){

	char c = getchar();

	while (!isdigit(c)) c = getchar();

	int x = 0;

	while (isdigit(c)) {

	    x = x * 10 + c - '0';

	    c = getchar();

	}

	return x;

}



int l[maxn], r[maxn];

int block[maxn];

int cnt;



struct Query

{

	int l, r, k;

	int id;

	Query(){}

	Query(int l, int r, int k, int id):l(l),r(r),k(k),id(id){}

	bool operator < (const Query&rhs) const{

		if (block[l] == block[rhs.l]) return r < rhs.r;

		return l < rhs.l;

	}

}ask[maxn];



std::vector<int> G[maxn];

int a[maxn], val[maxn];



void dfs(int u, int fa) {

	l[u] = ++cnt;

	a[cnt] = val[u];

	for (int &v:G[u]) {

		if (v == fa) continue;

		dfs(v, u);

	}

	r[u] = cnt;

}



int num[maxn];

int Hash[maxn];

int ans[maxn];



void update(int id, int add) {

    int x = a[id];

    if (add < 0) num[Hash[x]]--;

    Hash[x] += add;

    if (add > 0) num[Hash[x]]++;

}



void Move(int &fr, int to, int t) {   // d presents the direction, t represents l or r

    int d = fr < to ? 1 : -1;

    while (fr != to) {

        fr += d * t > 0 ? d : 0;    //if this movement makes interval larger , then move first

        update(fr, t * d); // if S means [l - 1, r](in some special problems) && t represents l, then fr - 1;

        fr += d * t > 0 ? 0 : d;   // if smaller ,update first

    }

}



int main () {

#ifdef LOCAL

	freopen("C:\\Users\\zzblack\\Desktop\\case.in","r",stdin);

	freopen("C:\\Users\\zzblack\\Desktop\\case.out","w",stdout);

#endif

	int n = read(), limit = sqrt(n+0.5), q = read();

	for (int i = 1; i <= n; i++) val[i] = read();

	for (int i = 2; i <= n; i++) {

		int u = read(), v = read();

		G[u].push_back(v);

		G[v].push_back(u);

	}

	for (int i = 1; i <= n; i++) block[i] = (i-1)/limit+1;

	dfs(1, 0);

	num[0] = n;

	for (int i = 1; i <= q; i++) {

		int u = read(), k = read();

		ask[i] = Query(l[u], r[u], k, i);

	}

	sort(ask + 1, ask + 1 + q);

	int l = 1, r = 0;

	for (int i = 1; i <= q; i++) {

		Move(l, ask[i].l,-1);

		Move(r, ask[i].r, 1);

		ans[ask[i].id] = num[ask[i].k];

	}

	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);





	return 0;

}