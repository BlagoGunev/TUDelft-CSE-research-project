// CF template, version 3.0

#include <bits/stdc++.h>

using namespace std;

#define improvePerformance ios_base::sync_with_stdio(false); cin.tie(0)
#define getTest int t; cin >> t
#define eachTest for (int _var=0;_var<t;_var++)
#define get(name) int (name); cin >> (name)
#define out(o) cout << (o)
#define getList(cnt, name) vector<int> (name); for (int _=0;_<(cnt);_++) { get(a); (name).push_back(a); }
#define sortl(name) sort((name).begin(), (name).end())
#define rev(name) reverse((name).begin(), (name).end())
#define forto(name, var) for (int (var) = 0; (var) < (name); (var)++)
#define decision(b) if (b){out("YES");}else{out("NO");}

#define int long long int

template <typename T, typename I>
struct segtree {
    int n;
    vector<T> tree;
    vector<I> initial;
    T id;

    segtree(int i_n, vector<I> i_initial, T i_id): n(i_n), initial(i_initial), id(i_id) {
        tree.resize(4 * n);
    }

    T conquer(T left, T right) {
        // write your conquer function
    }

    T value(I inp) {
        // write your value function
    }

    void build(int v, int l, int r) {
        if (l == r) tree[v] = value(initial[l]);
        else {
            int middle = (l + r) / 2;
            build(2 * v, l, middle);
            build(2 * v + 1, middle + 1, r);
            tree[v] = conquer(tree[2 * v], tree[2 * v + 1]);
        }
    }

    void upd(int v, int l, int r, int i, I x) {
        if (l == r) tree[v] = value(x);
        else {
            int middle = (l + r) / 2;
            if (middle >= i) upd(2 * v, l, middle, i, x);
            else upd(2 * v + 1, middle + 1, r, i, x);
            tree[v] = conquer(tree[2 * v], tree[2 * v + 1]);
        }
    }

    T query(int v, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[v];
        else if (r < ql || qr < l) return id;
        int middle = (l + r) / 2;
        T left = query(2 * v, l, middle, ql, qr);
        T right = query(2 * v + 1, middle + 1, r, ql, qr);
        return conquer(left, right);
    }
};

// vector<int>

signed main() {
    improvePerformance;
    getTest;
    
    eachTest {
        get(n);
        getList(n, nums);
        vector<int> pref;
        int c = 0;
        pref.push_back(0);
        forto(n, i) {
            if (c < nums[i]) c++;
            else if (c > nums[i]) c--;
            pref.push_back(c);
        }
        vector<int> prefmax;
        prefmax.push_back(0);
        forto(n, i) prefmax.push_back(max(prefmax.back(), pref[i + 1]));
        int l = 0;
        int r = n + 1;
        while (r - l > 1) {
            int middle = (l + r) / 2;
            bool can = false;
            int minr = middle;
            if (prefmax[n - 1] >= middle) can = true;
            for (int i = n - 1; i >= 1; i--) {
                int val = nums[i];
                if (val > minr - 1) minr--;
                else minr++;
                if (prefmax[i - 1] >= minr) can = true;
            }
            if (can) l = middle;
            else r = middle;
        }
        out(l);
        out("\n");
    }
}