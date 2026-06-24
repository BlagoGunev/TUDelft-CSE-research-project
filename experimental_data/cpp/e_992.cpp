#include<cstdio>
#include<algorithm>
#pragma GCC optimize("Ofast")
using namespace std;

const int N = 2e5 + 5;


int n, m, a[N], p, x;
long long t[4 * N], ob[4 * N];

void build(int v, int l, int r){
    if(l == r){
        t[v] = a[l];
        return;
    }
    int mid = (r + l) >> 1;
    build(v + v, l, mid);
    build(v + v + 1, mid + 1, r);
    t[v] = max(t[v + v], t[v + v + 1]);
}

inline void push(int v){
    if(ob[v]){
        ob[v + v] += ob[v];
        ob[v + v + 1] += ob[v];
        t[v + v] += ob[v];
        t[v + v + 1] += ob[v];
        ob[v] = 0;
        return;
    }
}

void update(int v, int l, int r, int tl, int tr, int val){
    if(l > r || l > tr || tl > r){
        return;
    }
    if(tl <= l && r <= tr){
        t[v] += val;
        ob[v] += val;
        return;
    }
    push(v);
    int mid = (r + l) >> 1;
    update(v + v, l, mid, tl, tr, val);
    update(v + v + 1, mid + 1, r, tl, tr, val);
    t[v] = max(t[v + v], t[v + v + 1]);
}

int get(int v, int l, int r){
    if(t[v] < 0){
        return -1;
    }
    if(l == r){
        return t[v] == 0 ? l : -1;
    }
    push(v);
    int mid = (r + l) >> 1;
    if(t[v + v] == 0){
        return get(v + v, l, mid);
    }
    if(t[v + v + 1] == 0){
        return get(v + v + 1, mid + 1, r);
    }
    int y = get(v + v, l, mid);
    return y == -1 ? get(v + v + 1, mid + 1, r) : y;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    for(int i = 1; i < n; i++){
        update(1, 1, n, i + 1, n, -a[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &p, &x);
        if(p + 1 <= n){
            update(1, 1, n, p + 1, n, +a[p]);
        }
        update(1, 1, n, p, p, -a[p]);
        a[p] = x;
        update(1, 1, n, p, p, +a[p]);
        if(p + 1 <= n){
            update(1, 1, n, p + 1, n, -a[p]);
        }
        printf("%d\n", get(1, 1, n));
    }
}