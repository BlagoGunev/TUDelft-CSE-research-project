#include<bits/stdc++.h>

using namespace std;

#define int long long

typedef long long ll;

const double PI = acos(-1.0);

const double eps = 1e-6;

const int maxn = 2e5 + 7;

int n,m, a[maxn], b[maxn], pos[maxn], val[maxn]; 

                  

struct segment_tree {

    struct tree {

        int l, r, lazy, mi;

    }tr[maxn * 4];

    inline void build(int p, int l, int r) {

        tr[p].l = l, tr[p].r = r;

        if (l == r) {

            tr[p].mi = a[l];

            tr[p].lazy = 0;

            return;

        }

        int mid = (l + r) >> 1;

        build(p * 2, l, mid);

        build(p * 2 + 1, mid + 1, r);

        tr[p].mi = min(tr[p * 2].mi, tr[p * 2 + 1].mi);

        return;

    }

    inline void push_down(int p) {

        if (tr[p].lazy != 0) { //如果父节点lazy标记不为0，既让lazy标记下传

            tr[p * 2].lazy += tr[p].lazy;

            tr[p * 2 + 1].lazy += tr[p].lazy;

            int mid = (tr[p].l + tr[p].r) >> 1;

            tr[p * 2].mi += tr[p].lazy;//改变两个子节点的maxv

            tr[p * 2 + 1].mi += tr[p].lazy;

            tr[p].lazy = 0;//下传后自己的lazy标记变为0

        }

    }

    inline void add(int p, int l, int r, int k) {

        if (tr[p].l >= l && tr[p].r <= r) {

            tr[p].mi += k;

            tr[p].lazy += k; //完全包含就将lazy标记加上k用来之后传给子节点

            return;

        }

        push_down(p); //如果没有完全找到就往下找，同时下传lazy和子节点的maxv；

        if (tr[p * 2].r >= l) add(p * 2, l, r, k); //哪边有交集就往哪边走；

        if (tr[p * 2 + 1].l <= r) add(p * 2 + 1, l, r, k);

        tr[p].mi = min(tr[p * 2].mi , tr[p * 2 + 1].mi);//自下向上更新maxv

        return;

    }

    inline int search(int p, int l, int r) {

        if (tr[p].l >= l && tr[p].r <= r) { //如果完全包含就返回maxv，并加在s上

            return tr[p].mi;

        }

        if (tr[p].l > r || tr[p].r < l) return 0;

        push_down(p);////如果没有完全找到就往下找，同时下传lazy和子节点的maxv；

        int s = 0;

        if (tr[p * 2].r >= l) s = min(s, search(p * 2, l, r));

        if (tr[p * 2 + 1].l <= r) s = min(s, search(p * 2 + 1, l, r)); 

        return s;

    }

}ST;



signed main(){

    ios::sync_with_stdio(false);

    cin.tie(0), cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){

        cin >> b[i];

        pos[b[i]] = i;

    }

    for(int i = 1, x; i <= n; i++){

        cin >> x;

        val[b[i]] = x;

        a[i] = a[i - 1] + x;

    }

    ST.build(1, 1, n - 1);

    ll ans = ST.tr[1].mi;

    for(int i = 1; i <= n; i++){

        // cout << ST.tr[1].mi << '\n';

        if(1 <= pos[i] - 1)ST.add(1, 1, pos[i] - 1, val[i]);

        if(pos[i] <= n - 1)ST.add(1, pos[i], n - 1, -val[i]);

        ans = min(ans, ST.tr[1].mi);

    }

    cout << ans << '\n';

}