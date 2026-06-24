#include<bits/stdc++.h>

using namespace std;



struct LazySeg {

    int l, r;

    int val = 0, tag = 0;

    bool is_lazy = false;

    LazySeg * l_child = NULL, * r_child = NULL;



    LazySeg(int _l, int _r) {

        l = _l;

        r = _r;

        if (r - l > 1) {

            int m = (l + r) / 2;

            l_child = new LazySeg(l, m);

            r_child = new LazySeg(m, r);

        }

    }~LazySeg() {

        delete l_child;

        delete r_child;

    }

    void unlazy() {

        if (!is_lazy) return;

        val = (r - l) * tag;

        if (r - l <= 1) return;

        l_child -> tag = tag;

        l_child -> is_lazy = true;

        r_child -> tag = tag;

        r_child -> is_lazy = true;

        tag = 0;

        is_lazy = false;

    }

    void update(int from, int to, int x) {

        unlazy();

        if (from >= r || l >= to) return;

        if (from <= l && to >= r) {

            tag = x;

            is_lazy = true;

            unlazy();

        } else {

            l_child -> update(from, to, x);

            r_child -> update(from, to, x);

            val = l_child -> val + r_child -> val;

        }

    }

    int query(int from, int to) {

        if (from >= r || l >= to) return 0;

        unlazy();

        if (from <= l && to >= r) return val;

        else {

            if (l_child == NULL) return 0;

            return l_child -> query(from, to) + r_child -> query(from, to);

        }

    }

    //pre = prefix in [l,k)

    int max_right(int k, int pre, int v) {

        unlazy();

        if (r - l == 1) {

            if (val == v) return l;

            else return l - 1;

        }

        l_child -> unlazy();

        int mid = (l + r) / 2;

        if (mid <= k) {

            return r_child -> max_right(k, pre - l_child -> val, v);

        } else if (l_child -> val - pre == v * (mid - k)) {

            //left to mid-1 has all 1's => answer must be >= mid-1

            return r_child -> max_right(mid, 0, v);

        } else {

            return l_child -> max_right(k, pre, v);

        }

    }

    //suff = suffix

    int get_answer() {

        unlazy();

        if (r - l == 1) {

            if (val == 1) return l;

            else return l - 1;

        }

        r_child -> unlazy();

        if (r_child -> val == 0) {

            //[mid to end] are all 0

            return l_child -> get_answer();

        } else {

            return r_child -> get_answer();

        }

    }

};



signed main() {

    ios_base::sync_with_stdio(0);

    cin.tie(NULL);

    cout.tie(NULL);



    int n, q;

    cin >> n >> q;

    LazySeg tr(0, 200100);



    auto add = [ & ](int x) {

        int y = tr.max_right(x, tr.query(0, x), 1) + 1;

        if (y == x) { //no carry; just change 0 to 1

            tr.update(x, x + 1, 1);

        } else { //there is a carry; set the whole block of 1's to 0

            tr.update(x, y, 0);

            tr.update(y, y + 1, 1);

        }

    };



    auto remove = [ & ](int x) {

        int y = tr.max_right(x, tr.query(0, x), 0) + 1;

        if (y == x) {

            tr.update(x, x + 1, 0);

        } else {

            tr.update(x, y, 1);

            tr.update(y, y + 1, 0);

        }

    };

    vector < int > a(n);

    for (int i = 0; i < n; ++i) {

        cin >> a[i];

        add(a[i]);

    }

    while (q--) {

        int k, l; cin >> k >> l;

        k--; 

        remove(a[k]); add(l);

        a[k] = l;

        cout << tr.get_answer() << "\n";

    }

}