#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT =
#define enl "\n";
#define debug(k)                             \
    for (int _ = 0; _ < DEBUG_INDENT; _++) { \
        cout << "  ";                        \
    }                                        \
    cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

const int MX = 2e5 + 5;

vi nei[MX];

bool sucs[MX];
int root[MX];
int sz[MX];
stack<int> upds;
bool used[MX];
priority_queue<pi, vector<pi>, greater<pi>> nes[MX];
int get_root(int node) {
    if (root[node] == node) {
        return node;
    }
    return root[node] = get_root(root[node]);
}

void unify(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (a == b) {
        return;
    }
    if (nes[a].size() < nes[b].size()) {
        swap(a, b);
    }
    sucs[a] = true;
    sz[a] += sz[b];
    while (!nes[b].empty()) {
        nes[a].push(nes[b].top());
        nes[b].pop();
    }
    root[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        vi as(n + 1);
        for (int i = 1; i <= n; i++) {
            nei[i].clear();
            while (!nes[i].empty()) {
                nes[i].pop();
            }
            root[i] = i;
            sz[i] = 1;
            used[i] = false;
            sucs[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            cin >> as[i];
            if (as[i] == 0) {
                used[i] = true;
                upds.push(i);
                sucs[i] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            nei[a].push_back(b);
            nei[b].push_back(a);
            nes[a].push({as[b], b});
            nes[b].push({as[a], a});
        }
        while (!upds.empty()) {
            int cur = upds.top();
            // cout << cur << endl;
            upds.pop();
            for (int ne : nei[cur]) {
                if (sucs[get_root(ne)]) {
                    unify(cur, ne);
                }
            }
            int newc = get_root(cur);
            while (!nes[newc].empty()) {
                pi tp = nes[newc].top();
                if (tp.f > sz[newc]) {
                    break;
                }
                nes[newc].pop();
                if (used[tp.s]) {
                    continue;
                }
                // cout << tp.f << " " << tp.s << endl;
                used[tp.s] = true;
                upds.push(tp.s);
            }
        }
        bool suc = sz[get_root(1)] == n;
        cout << (suc ? "YES\n" : "NO\n");
    }
    return 0;
}