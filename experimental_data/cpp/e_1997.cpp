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

//#define int long long int

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
    //getTest;
    
    //eachTest {
        get(n);
        get(q);
        getList(n, nums);
        vector<int> ans(q, false);
        vector<pair<int, int>> queries;
        vector<array<int, 3>> small;
        vector<vector<pair<int, int>>> large(n + 1);
        forto(q, i) {
            get(j);
            get(k);
            j--;
            if (k <= 450) {
                small.push_back({k, j, i});
            } else {
                large[k].push_back({j, i});
            }
            queries.push_back({k, j});
        }
        forto(n + 1, i) sortl(large[i]);
        sortl(small);
        int ptr = 0;
        int s1 = small.size();
        vector<bool> fight(n, false);
        forto(451, k) {
            if (k == 0) continue;
            int level = 1;
            int fights = 0;
            vector<int> inds;
            forto(n, i) {
                if (level <= nums[i]) fights++, fight[i] = true, inds.push_back(i);
                if (fights == k) {
                    fights = 0;
                    level++;
                }
            }
            while (ptr < s1 && small[ptr][0] == k) {
                ans[small[ptr][2]] = fight[small[ptr][1]];
                ptr++;
            }
            for (int ind: inds) fight[ind] = false;
        }
        vector<int> where(n + 1, -1);
        vector<int> ptrs(n + 1, 0);
        vector<int> pref(n, 0);
        forto(451, L) {
            if (L == 0) continue;
            pref[0] = nums[0] >= L;
            forto(n - 1, j) pref[j + 1] = pref[j] + (nums[j + 1] >= L);
            for (int k = 451; k <= min(n, L == 1? n: (n + L - 2) / (L - 1) + 3); k++) {
                if (where[k] == n) continue;
                int l = where[k] + 1;
                int r = n;
                while (r - l >= 1) {
                    int middle = (l + r) / 2;
                    if (pref[middle] >= (where[k] == -1? 0: pref[where[k]]) + k) r = middle;
                    else l = middle + 1;
                }
                while (ptrs[k] < large[k].size() && large[k][ptrs[k]].first <= l) {
                    ans[large[k][ptrs[k]].second] = nums[large[k][ptrs[k]].first] >= L;
                    ptrs[k]++;
                }
                where[k] = l;
            }
        }
        forto(q, i) {
            decision(ans[i]);
            out("\n");
        }
    //}
}