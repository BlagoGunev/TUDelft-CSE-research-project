#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef long long qw;

#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif

const int maxn = 100010;

int n, m, a[maxn], b[maxn], r[maxn], c, l, s[maxn], bp[maxn], bt;
qw d, x;

qw getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
	int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

inline bool cmpR(int x, int y) {
	return a[x] > a[y];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("out.txt", "w", stdout);
#endif

	memset(s, -1, sizeof(s));
	scanf("%d" lld lld, &n, &d, &x);
	initAB();
	for (int i = 0; i < n; i ++)
		r[i] = i;
	sort(r, r + n, cmpR);
	bt = 0;
	for (int i = 0; i < n; i ++)
		if (b[i])
			bp[bt ++] = i;
	c = n;
	l = n;
	for (int i = 0; i < n && c; i ++)
		for (int j = 0; r[i] + bp[j] < l && j < bt; j ++)
			if (s[r[i] + bp[j]] == -1) {
				s[r[i] + bp[j]] = a[r[i]], c --;
				while (l && s[l - 1] > -1)
					l --;
			}
	for (int i = 0; i < n; i ++)
		if (s[i] == -1)
			puts("0");
		else
			printf("%d\n", s[i]);
}