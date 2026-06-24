#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())
#define lc          id << 1
#define rc          lc | 1

const ll MAXN = 2e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q, n, L[MAXN], R[MAXN], mark[MAXN], seg[2][MAXN << 2], val[2][MAXN];
vector<pii> vec[2];


void build(int ind, int id = 1, int l = 0, int r = n){
    if(r - l == 1){
        seg[ind][id] = val[ind][vec[ind][l].Y];
        // cout << ind << sep << seg[ind][id] << endl;
        return;
    }
    int mid = l + r >> 1;
    build(ind, lc, l, mid);
    build(ind, rc, mid, r);
    seg[ind][id] = min(seg[ind][lc], seg[ind][rc]);
}

int get(int ind, int ql, int qr, int vl, int id = 1, int l = 0, int r = n){
    // cout << ind << sep << id << sep << seg[ind][id] << sep << vl << endl;
    if(qr <= l || r <= ql)  return -1;
    // cout << ind << sep << id << sep << seg[ind][id] << sep << vl << endl;
    if(seg[ind][id] > vl)  return -1;
    if(r - l == 1){
        if(mark[vec[ind][l].Y]){
            seg[ind][id] = MOD;
            return -1;
        }
        return vec[ind][l].Y;
    }
    int mid = l + r >> 1;
    int x = get(ind, ql, qr, vl, lc, l, mid);
    if(x == -1){
        x = get(ind, ql, qr, vl, rc, mid, r);
    }
    seg[ind][id] = min(seg[ind][lc], seg[ind][rc]);
    return x;
}

void DFS(int v){
    // cout << "DFS " << v << endl;
    mark[v] = 1;
    while(1){
        int ind = lower_bound(all(vec[0]), pii(v - R[v], -MOD)) - vec[0].begin();
        int u = get(0, ind, n, v - L[v]);
        if(u == -1) break;
        DFS(u);
    }
    while(1){
        int ind = lower_bound(all(vec[1]), pii(v + L[v], -MOD)) - vec[1].begin();
        int u = get(1, ind, n, v + R[v]);
        if(u == -1) break;
        DFS(u);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        fill(mark, mark + n + 5, 0);
        for(int i = 0; i < (n + 5) * 4; i++){
            seg[0][i] = seg[1][i] = MOD;
        }
        vec[0].clear();
        vec[1].clear();
        for(int i = 0; i < n; i++){
            cin >> L[i] >> R[i];
            vec[0].push_back({i + R[i], i}); val[0][i] = i + L[i];
            vec[1].push_back({i - L[i], i}); val[1][i] = i - R[i];
        }
        for(int i = 0; i < 2; i++){
            sort(all(vec[i]));
            build(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!mark[i]){
                DFS(i);
                ans++;
            }
        }
        cout << ans << endl;
        // cout << "==========" << endl;
    }

    return 0;
}
/*

*/