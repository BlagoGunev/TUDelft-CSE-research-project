#include<bits/stdc++.h>





using namespace std;

const int maxn = 100000 + 5;

const int inf = 0x3f3f3f3f;

struct point{

    int mini, minicnt;

    int g;

}tree[maxn << 2];

int n, cnt, q, gd;

int a[maxn];

pair <int, int> t;



int gcd(int a, int b){

    return b == 0 ? a : gcd(b, a % b);

}



void pushup(int o){

    int lb = o << 1, rb = o << 1 | 1;

    tree[o].g = gcd(tree[lb].g, tree[rb].g);

    if (tree[lb].mini > tree[rb].mini){

        tree[o].mini = tree[rb].mini;

        tree[o].minicnt = tree[rb].minicnt;

    }

    else if (tree[lb].mini < tree[rb].mini){

        tree[o].mini = tree[lb].mini;

        tree[o].minicnt = tree[lb].minicnt;

    }

    else {

        tree[o].mini = tree[lb].mini;

        tree[o].minicnt = tree[lb].minicnt + tree[rb].minicnt;

    }

}



void buildtree(int l, int r, int o){

    if (l == r){

        scanf("%d", &tree[o].mini);

        tree[o].minicnt = 1;

        tree[o].g = tree[o].mini;

        a[++cnt] = tree[o].mini;

        return ;

    }

    else {

        int mid = (l + r) / 2;

        if (l <= mid) buildtree(l, mid, o << 1);

        if (r > mid) buildtree(mid + 1, r, o << 1 | 1);

        pushup(o);

    }

}



void query(int l, int r, int ql, int qr, int o){

    if (ql <= l && qr >= r){

        gd = gcd(gd, tree[o].g);

        if (t.first > tree[o].mini){

            t.first = tree[o].mini;

            t.second = tree[o].minicnt;

        }

        else if (t.first == tree[o].mini){

            t.second += tree[o].minicnt;

        }

        return ;

    }

    else {

        int mid = (l + r) / 2;

        if (ql <= mid) query(l, mid, ql, qr, o << 1);

        if (qr > mid) query(mid + 1, r, ql, qr, o << 1 | 1);

    }

}



int main(){

    cin >> n;

    cnt = 0;

    buildtree(1, n, 1);

    cin >> q;

    while (q--){

        int ql, qr;

        scanf("%d%d", &ql, &qr);

        gd = a[ql];

        t = make_pair(inf, 1);

        query(1, n, ql, qr, 1);

        int ans = 0;

        if (gd == t.first){

            ans = qr - ql + 1;

            ans -= t.second;

        }

        else ans = qr - ql + 1;

        printf("%d\n", ans);

    }

    return 0;

}