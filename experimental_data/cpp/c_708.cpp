#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

#include <iostream>

//#include <assert.h>

#define MAXN 400050



using namespace std;



struct Edge {

    int v, next;

}edge[MAXN * 2];

int e, ft[MAXN];



int n, n0, root, size[MAXN], pre[MAXN], dsu[MAXN], w[MAXN][2];

void add(int u, int v)

{

    edge[e].v = v;

    edge[e].next = ft[u];

    ft[u] = e++;

}



void dfs(int u)

{

    size[u] = 1;

    w[u][0] = w[u][1] = 0;

    if (u == root || pre[u] == root)

        dsu[u] = u;

    else

        dsu[u] = dsu[pre[u]];

    int v;

    for (int i = ft[u]; i != -1; i = edge[i].next) {

        v = edge[i].v;

        if (!pre[v]) {

            pre[v] = u;

            dfs(v);

            size[u] += size[v];

            if (size[v] > w[u][0]) {

                w[u][1] = w[u][0];

                w[u][0] = size[v];

            } else if (size[v] > w[u][1])

                w[u][1] = size[v];

        }

    }

}



inline int fastscanf()

{

	int t=0;

	char c=getchar();

	while (! ((c>47) && (c<58)))

		c=getchar();

	while ((c>47) && (c<58))

		t=t*10+c-48,c=getchar();

	return t;

}



inline int getint()

{

	static char c;

	while (((c = getchar()) < '0' || c > '9') && c != '-');



	if (c == '-') {

		int res = 0;

		while ((c = getchar()) >= '0' && c <= '9')

			res = res * 10 + c - '0';

		return -res;

	} else {

		int res = c - '0';

		while ((c = getchar()) >= '0' && c <= '9')

			res = res * 10 + c - '0';

		return res;

	}

}



int main()

{

	//freopen("c.txt", "r", stdin);

    while (scanf("%d", &n) == 1) {

    	n0 = n / 2;

        e = 0;

        memset(ft, -1, sizeof(ft));

        int u, v;

        for (int i = 1; i < n; i++) {

            //scanf("%d%d", &u, &v);

            //u = fastscanf();

            //v = fastscanf();

            u = getint();

            v = getint();

            add(u, v);

            add(v, u);

        }

        memset(pre, 0, sizeof(pre));

        root = 1;

        pre[root] = root;

        dfs(root);

        root = 0;

        for (int i = 1; i <= n; i++)

            if (w[i][0] <= n0 && n - size[i] <= n0)

                root = i; 

        memset(pre, 0, sizeof(pre));

        pre[root] = root;

        dfs(root);

        int x;

        for (int i = 1; i <= n; i++) {

            if (i == root)

                putchar('1');

            else {

                if (size[dsu[i]] == w[root][0])

                    x = w[root][1];

                else

                    x = w[root][0];

                if (n - size[dsu[i]] <= n0 || n - x - size[i] <= n0)

                    putchar('1');

                else

                	putchar('0');

            }

            putchar(' ');

        }

        putchar('\n');

    }

    return 0;

}