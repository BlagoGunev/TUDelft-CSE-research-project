#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#define debug(x) cout << #x << " " << x << endl;
typedef long long ll;
typedef pair<int, int> pii;

struct FastIO {
    inline FastIO& operator >> (int& x) {
        x = 0; char f = 0, ch = getchar();
        while(ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
        while(ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
        return x = (f ? -x : x), *this;
    }
    inline FastIO& operator >> (long long& x) {
        x = 0; char f = 0, ch = getchar();
        while(ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
        while(ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
        return x = (f ? -x : x), *this;
    }
    inline FastIO& operator >> (double& x) {
        x = 0; char f = 0, ch = getchar();
        double d = 0.1;
        while(ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
        while(ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
        if(ch == '.') {
            ch = getchar();
            while(ch <= '9' && ch >= '0') x += d * (ch ^ 48), d *= 0.1, ch = getchar();
        }
        return x = (f ? -x : x), *this;
    }
}rin;
int a[100505];
int l[350], r[350];
struct node{int l, r, tag, minn;}t[400005];
int val[100005], tmp;
void build_tree(int now, int l, int r) {
    t[now].l = l, t[now].r = r, t[now].minn = 1 << 30;
    if(l == r) {t[now].minn = a[l]; return ;}
    int ls = now << 1, rs = now << 1 | 1, mid = (t[now].l + t[now].r) >> 1;
    build_tree(ls, l, mid);
    build_tree(rs, mid + 1, r);
    t[now].minn = min(t[ls].minn, t[rs].minn);
}
void tagdown(int now) {
    if(t[now].tag == 0) return ;
    int ls = now << 1, rs = now << 1 | 1;
    t[ls].minn += t[now].tag;
    t[rs].minn += t[now].tag;
    t[ls].tag += t[now].tag;
    t[rs].tag += t[now].tag;
    t[now].tag = 0; 
}
void add(int now, int l, int r, int k) {
    if(t[now].l >= l && t[now].r <= r) {
    	t[now].minn += k;
        t[now].tag += k;
        return ;
    }
    tagdown(now);
    int ls = now << 1, rs = now << 1 | 1, mid = (t[now].l + t[now].r) >> 1;
    if(l <= mid) add(ls, l, r, k);
    if(r > mid) add(rs, l, r, k);
    t[now].minn = min(t[ls].minn, t[rs].minn);
}
void query(int now, int l, int r) {
	if(t[now].minn >= tmp) return ;
    if(t[now].l >= l && t[now].r <= r) {
    	tmp = min(tmp, t[now].minn);
    	return ;
    }
    tagdown(now);
    int ls = now << 1, rs = now << 1 | 1, mid = (t[now].l + t[now].r) >> 1;
    if(l <= mid) query(ls, l, r);
    if(r > mid) query(rs, l, r);
}

vector <int> R[100005], L[100005];

int main (){
	int n, m;
	rin >> n >> m;
	for(int i = 1 ; i <= n ; ++ i) rin >> a[i];
	for(int i = 1 ; i <= m ; ++ i) rin >> l[i] >> r[i], R[r[i]].push_back(i), L[l[i]].push_back(i);
	build_tree(1, 1, n);
	int ans = -(1 << 30);
	int id = -1;
	for(int j = 1 ; j <= m ; ++ j) {
		add(1, l[j], r[j], -1);
	}
	for(int i = 1 ; i <= n ; ++ i) {
		for(int j = 0 ; j < R[i - 1].size() ; ++ j) {
			add(1, l[R[i - 1][j]], r[R[i - 1][j]], -1);
		}
		for(int j = 0 ; j < L[i].size() ; ++ j) {
			add(1, l[L[i][j]], r[L[i][j]], 1);
		}
		tmp = 1 << 30;
		query(1, 1, n);
		if(ans < (a[i] - tmp)) {
			ans = (a[i] - tmp);
			id = i;
		}
	}
	printf("%d\n", ans);
	int tot = 0;
	for(int j = 1 ; j <= m ; ++ j) {
		if(l[j] <= id && r[j] >= id) continue;
		++ tot;
	}
	printf("%d\n", tot);
	for(int j = 1 ; j <= m ; ++ j) {
		if(l[j] <= id && r[j] >= id) continue;
		printf("%d ", j);
	}
	return 0;
}