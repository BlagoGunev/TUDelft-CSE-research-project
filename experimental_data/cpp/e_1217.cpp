//
//  Sum Queries?.cpp
//  National Olympiad in Informatics in Provinces
//
//  Created by 黄子齐 on 2019/9/5.
//  Copyright © 2019 黄子齐. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <string.h>
using std::min;
const int N = 2e5+10;
struct node {
    int mn[10];
    long long mins;
    node() {
        memset(mn, 0x7f, sizeof(mn));
        mins = (long long)2e15+10;
    }
}t[N*5];
#define rint register int
int INF;
inline void pushup(node &now, node ls, node rs) {
    now.mins = min(ls.mins, rs.mins);
    for (rint i=0; i<10; i++) {
        now.mn[i] = min(ls.mn[i], rs.mn[i]);
        now.mins = min(now.mins, (long long)((long long)ls.mn[i]+rs.mn[i]));
    }
    return;
}
inline void Update(int now, int l, int r, int pos, int k) {
    if (l==r) {
        memset(t[now].mn, 0x7f, sizeof(t[now].mn));
        rint j=0;
        int nw = k;
        while (nw) {
            if (nw%10) {
                t[now].mn[j] = k;
            }
            nw/=10;
            j++;
        }
        return;
    }
    int mid=l+r>>1;
    if (pos<=mid) {
        Update(now<<1, l, mid, pos, k);
    } else {
        Update(now<<1|1, mid+1, r, pos, k);
    }
    pushup(t[now], t[now<<1], t[now<<1|1]);
    return;
}
inline node Query(int now, int l, int r, int L, int R) {
    if (l>=L&&r<=R) {
        return t[now];
    }
    int mid=l+r>>1;
    node ret;
    if (L > mid) {
        return Query(now<<1|1, mid+1, r, L, R);
    } else if (R <= mid) {
        return Query(now<<1, l, mid, L, R);
    } else {
        pushup(ret, Query(now<<1, l, mid, L, R), Query(now<<1|1, mid+1, r, L, R));
        return ret;
    }
}
inline int read() {
    int r=0;
    char c=getchar();
    while (c<'0'||c>'9') {
        c=getchar();
    }
    while (c>='0'&&c<='9') {
        r=r*10+c-'0';
        c=getchar();
    }
    return r;
}
int n, m;
int main() {
//    freopen("mytestdata.in", "r", stdin);
    long long INF = t[0].mn[0];
    n=read();
    m=read();
    for (rint i=1; i<=n; i++) {
        int x=read();
        Update(1, 1, n, i, x);
    }
    for (rint i=1; i<=m; i++) {
        int opt=read();
        int l=read();
        int r=read();
        if (opt==1) {
            Update(1, 1, n, l, r);
        } else {
            node now = Query(1, 1, n, l, r);
            if (now.mins >= INF) {
                printf("-1\n");
            } else {
                printf("%lld\n", now.mins);
            }
        }
    }
    return 0;
}