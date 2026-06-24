#include <stdio.h>
#include <string.h>

#define LIM 2000000000

typedef struct {
	int r, c;
} pair;

pair dir[4];
int n, m;

pair who[1500][1500];
char M[1500][1501];

int dfs (pair curr, pair g) {
	int i;
	pair next, gnext, tmp;
	for (i = 0; i < 4; i++) {
		gnext.r = g.r; gnext.c = g.c;
		next.r = curr.r+dir[i].r;
		next.c = curr.c+dir[i].c;
		if (next.r < 0)	{
			next.r = n-1;
			gnext.r = g.r-1;
		} else if (next.r == n) {
			next.r = 0;
			gnext.r = g.r+1;
		}
		if (next.c < 0) {
			next.c = m-1;
			gnext.c = g.c-1;
		} else if (next.c == m) {
			next.c = 0;
			gnext.c = g.c+1;
		}
		if (M[next.r][next.c] != '#') {
//			printf ("next %d %d in %d %d\n", next.r, next.c, gnext.r, gnext.c);
			if (who[next.r][next.c].r == LIM) {
				who[next.r][next.c].r = gnext.r;
				who[next.r][next.c].c = gnext.c;
				if (dfs(next, gnext))	return 1;
			} else {
				tmp.r = who[next.r][next.c].r;
				tmp.c = who[next.r][next.c].c;
				if (tmp.r != gnext.r || tmp.c != gnext.c)	return 1;
			}
		}
	}
	return 0;
}

int main (void) {
	int i, j;
	pair s, g;
	dir[0].r = 0; dir[0].c = -1;
	dir[1].r = 0; dir[1].c = 1;
	dir[2].r = -1; dir[2].c = 0;
	dir[3].r = 1; dir[3].c = 0;

	scanf ("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf ("%s", M[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (M[i][j] == 'S') {
				s.r = i;	s.c = j;
			}
			who[i][j].r = LIM;
		}
	g.r = 0; g.c = 0;
	who[s.r][s.c].r = 0;
	who[s.r][s.c].c = 0;
	if (dfs (s, g)) printf ("Yes\n");
	else	printf ("No\n");
	
	return 0;
}