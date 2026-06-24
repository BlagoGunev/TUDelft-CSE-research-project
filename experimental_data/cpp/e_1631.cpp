#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cmath>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define ll long long

char buf[1 << 20], *p1, *p2;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)?EOF: *p1++)
template <typename T> inline void read(T &t) {
	int v = getchar();T f = 1;t = 0;
	while (!isdigit(v)) {if (v == '-')f = -1;v = getchar();}
	while (isdigit(v)) {t = t * 10 + v - 48;v = getchar();}
	t *= f;
}
template <typename T,typename... Args> inline void read(T &t,Args&... args) {
	read(t);read(args...);
}

const int N = 2e5 + 10;

struct node {
    int l,r;
    friend inline bool operator < (const node &a,const node &b) {
        return a.l < b.l;
    }
}p[N];

int n,a[N],pos1[N],pos2[N],tot,ans;

void work(int x,int flag) {
    if (x > tot) return ;
    if (flag) ans += p[x].r - p[x].l - 1;
    int pos = x;
    int maxx = 0,maxpos = 0;
    while (p[pos+1].l <= p[x].r && pos < tot) {
        ++pos;
        if (p[pos].r > maxx) {
            maxx = p[pos].r;
            maxpos = pos;
        }
    }
    if (maxpos > x && maxx > p[x].r) {
            ans += maxx - p[x].r - 1;
            work(maxpos,0);
    } else {
        work(pos + 1,1);
    }
}


void solve() {
    read(n);
    for (int i = 1;i <= n;++i) read(a[i]);
    for (int i = 1;i <= n;++i) {
        if (!pos1[a[i]]) pos1[a[i]] = i,pos2[a[i]] = i;
        pos2[a[i]] = i;
    }
    for (int i = 1;i <= n;++i) {
        if (pos1[i] != pos2[i]) {
            p[++tot] = (node){pos1[i],pos2[i]};
        }
    }
    sort(p+1,p+1+tot);
    work(1,1);
    printf("%d\n",ans);
}

signed main() {
    solve();
	return 0;
}