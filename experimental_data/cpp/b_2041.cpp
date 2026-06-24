#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// priority_queue <ll, vector<ll>, greater<ll>> q;
#define int long long

int w, b;

bool ok(int x) {
    priority_queue<int> pq;
    pq.push(w);
    pq.push(b);
    for (int i = x; i >= 1; i--) {
        int aux = pq.top();
        pq.pop();
        if (aux < i) 
            return 0;
        aux -= i;
        pq.push(aux);
    }
    return 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        cin >> w >> b;
        int st = 1, dr = 1e6;
        while (st <= dr) {
            int mij = (st + dr) / 2;
            if (ok(mij))
                st = mij + 1;
            else dr = mij - 1;
        }
        cout << dr << '\n';
    }
    return 0;
}