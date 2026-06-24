#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

pii p[2555];

int du[55], fa[55];

int l[2555], r[2555];



bool solve(int n) {

	for(int i = 2; i <= n; i++) {

		if(fa[i] == fa[1]) continue;

		return false;

	}

	return true;

}



int find(int x){    

    return fa[x]==x?x:find(fa[x]);    

}    



void Union(int x, int y){    

    int fx = find(x);    

    int fy = find(y);    

    fa[fy] = fx;    

}



int main() {

	int n, m, u, v;

	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++) fa[i] = i;

	for(int i = 1; i <= m; i++) {

		scanf("%d%d", &u, &v);

		du[u]++, du[v]++;

		Union(u, v);

	}

	for(int i = 1; i <= n; i++) {

		if(du[i] > 2) {

			printf("NO\n");

			return 0;

		}

	}

	for(int i = 1; i <= n; i++) fa[i] = find(fa[i]);

	int id = 0;

	for(int i = 1; i <= n; i++) {

		if(du[i] == 2) continue;

		for(int j = 1; j < i; j++) {

			if(du[i] <2 && du[j] < 2 && find(fa[i]) != find(fa[j])) {

				Union(i, j);

				l[id] = j, r[id] = i, id++;

				du[i]++, du[j]++;

			}

		}

	}

	int x = -1, y = -1;

	for(int i = 1; i <= n; i++) {

		if(du[i] == 0) x = i, y = i;

		if(du[i] == 1) {

			if(x == -1) x = i;

			else y = i;

		} 

	}

	if(x!=-1 && y!=-1) {

		l[id] = x, r[id] = y, id++;

		du[x]++, du[y]++;

	}

	for(int i = 1; i <= n; i++) fa[i] = find(i);

	if(solve(n)) {

		printf("YES\n%d\n", id);

		for(int i = 0; i < id; i++) {

			printf("%d %d\n", l[i], r[i]);

		}

	}

	else printf("NO\n"); 

	return 0;

}