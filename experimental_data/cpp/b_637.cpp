#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int ll;
typedef long double ld;

const int SIZE = 200010;
const int STRSIZE = 11;

struct MAN {
	char s[STRSIZE];
	int t;
} a[SIZE];

int cmp1(const void *a, const void *b)
{
	struct MAN *p = (struct MAN *)a, *q = (struct MAN *)b;

	int k = strcmp(p->s, q->s);

	if (k == 0)
		return q->t - p->t;
	else
		return k;
}

int cmp2(const void *a, const void *b)
{
	return ((struct MAN *)b)->t - ((struct MAN *)a)->t;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int n;

	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		gets(a[i].s);
		a[i].t = i;
	}

	qsort(a, n, sizeof a[0], cmp1);

	int p = 1;
	for (int i = 1; i < n; i++)
		if (strcmp(a[i].s, a[i - 1].s) != 0)
			a[p++] = a[i];

	qsort(a, p, sizeof a[0], cmp2);

	for (int i = 0; i < p; i++)
		puts(a[i].s);
}