#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2000005;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;

int a[N];

ll mn[N], lz[N], cnt[N];

int ap[N][3];

void build(int id, int l, int r){
    cnt[id] = r - l + 1;
    if(l == r) return;
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
}

void push(int id, int l, int r){
    mn[id] += lz[id];
    if(l != r){
        lz[id << 1] += lz[id];
        lz[id << 1 | 1] += lz[id];
    }
    lz[id] = 0;
}

void update(int id, int l, int r, int R, ll v){
    push(id, l, r);
    if(l > R) return;
    if(r <= R){
        lz[id] += v;
        push(id, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(id << 1, l, m, R, v);
    update(id << 1 | 1, m + 1, r, R, v);

    mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
    cnt[id] = 0;
    if(mn[id] == mn[id << 1]) cnt[id] += cnt[id << 1];
    if(mn[id] == mn[id << 1 | 1]) cnt[id] += cnt[id << 1 | 1];
}

int val[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    ll ans = 0;

    for(int i = 1; i <= n; ++i)
        cin>>a[i];

    build(1, 1, n);

    for(int i = 1; i <= n; ++i){

        update(1, 1, n, ap[a[i]][2], n);
        update(1, 1, n, ap[a[i]][1], -3);
        update(1, 1, n, i, 1);
        ap[a[i]][2] = ap[a[i]][1]; 
        ap[a[i]][1] = ap[a[i]][0]; 
        ap[a[i]][0] = i; 
        if(mn[1] == 0){
            ans += cnt[1] - (n - i);
        }
    }

    cout<<ans;
}