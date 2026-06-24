/***************************************

      Authur : zzblack                **

      Created: 2016-07-09             **

      Orz                             **

****************************************/

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <cmath>

#include <string>

#include <cctype>

#include <cstdio>

#include <vector>

#include <cstdlib>

#include <cstring>

#include <iomanip>

#include <sstream>

#include <iostream>

#include <algorithm>

using namespace std;

#define ls id<<1,l,mid

#define rs id<<1|1,mid+1,r

#define OFF(x) memset(x,-1,sizeof x)

#define CLR(x) memset(x,0,sizeof x)

#define MEM(x) memset(x,0x3f,sizeof x)

typedef long long ll ;

typedef pair<int,int> pii ;

const int maxn = 2e3 + 50 ;

const int maxm = 4e6 + 50;

const double eps = 1e-10;

const int max_index = 62;

const int inf = 0x3f3f3f3f ;

const int MOD = 1e9+7 ;



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

int n, cnt;

int head[maxn];

int pnt[maxm], nxt[maxm];



void add_edge(int u, int v) {

	pnt[cnt] = v;

	nxt[cnt] = head[u];

	head[u] = cnt++;

}



bool mat[maxn][maxn];

bool dis[maxn];

bool bfs(int i) {

	memset(dis, 0x00, sizeof dis);

	queue<int> q;

	q.push(i);

	dis[i] = 1;

	while (q.size()) {

		int u = q.front(); q.pop();

		for (int i = head[u]; ~i; i = nxt[i]) {

			int v = pnt[i];

			if (dis[v]) continue;

			dis[v] = 1;

			q.push(v);

		}

	}

	for (int i = 1; i <= n; i++) if (dis[i] == 0) return 1;

	return 0;

}



int main () {

#ifdef LOCAL

  	freopen("C:\\Users\\zzblack\\Desktop\\case.in","r",stdin);

    freopen("C:\\Users\\zzblack\\Desktop\\case.out","w",stdout);

#endif

    n = read();

    cnt = 0;

    memset(head, 0xff, sizeof head);

    for (int i = 1; i <= n; i++) {

    	for (int j = 1; j <= n; j++) {

    		int x = read();

    		if (x) add_edge(i, j), mat[i][j] = 1;

    	}

    }

    for (int i = 1; i <= n; i++) {

    	bool flag = 1;

    	for (int j = 1; j < i; j++) if (mat[i][j]) flag = 0;

    	if (flag && bfs(i)) {

    		puts("NO");

    		exit(0);

    	}

    }

    puts("YES");



	return 0;

}