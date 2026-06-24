#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#define endl '\n'

using namespace std;

using ll = long long;
using i3 = tuple<int,int,int>;
using ii = pair<int,int>;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif

const int maxn = 2005;
using T = array<int, maxn>;

struct Item {
    int w, v;
    Item() { w = v = 0; }
    Item(int _w, int _v) : w(_w), v(_v) {}
};

struct Query {
    int W, id;
    Query() {
        W = id = -1;
    }
    Query(int _W, int _id) : W(_W), id(_id) {}
};

T OP(const T& a, Item x) {
    T ans = a;
    for (int i = x.w; i < maxn; i++) {
        ans[i] = max(ans[i], a[i - x.w] + x.v);
    }
    return ans;
}

T make(Item x) {
    T ans;
    ans.fill(0);
    for (int i = x.w; i < maxn; i++) {
        ans[i] = x.v;
    }
    return ans;
}

struct Stack {
    vector<pair<Item, T>> stk;
    void push(Item x) {
        T y = stk.empty() ? make(x) : OP(stk.back().second, x);
        stk.emplace_back(x, y);
    }
    void pop() {
        stk.pop_back();
    }
    T get() {
        return stk.back().second;
    }
    Item top() {
        return stk.back().first;
    }
    Item bottom() {
        return stk.front().first;
    }
    bool empty() {
        return stk.empty();
    }
    int size() {
        return int(stk.size());
    }
};

struct Queue {
    Stack in, out;
    void push_back(Item x) {
        in.push(x);
    }
    void push_front(Item x) {
        out.push(x);
    }
    void work_front() {
        Stack to;
        int m = in.size();
        for (int i = 0; i < m / 2; i++) {
            to.push(in.top());
            in.pop();
        }
        while (in.size()) {
            out.push(in.top());
            in.pop();
        }
        while (to.size()) {
            in.push(to.top());
            to.pop();
        }
    }
    void work_back() {
        Stack to;
        int m = out.size();
        for (int i = 0; i < m / 2; i++) {
            to.push(out.top());
            out.pop();
        }
        while (out.size()) {
            in.push(out.top());
            out.pop();
        }
        while (to.size()) {
            out.push(to.top());
            to.pop();
        }
    }
    Item pop_front() {
        if (out.empty()) {
            work_front();
        }
        assert(!out.empty());
        Item ret = out.top();
        out.pop();
        return ret;
    }
    Item pop_back() {
        if (in.empty()) {
            work_back();
        }
        assert(!in.empty());
        Item ret = in.top();
        in.pop();
        return ret;
    }
    int get(int W) {
        if (in.empty() && out.empty()) return 0;
        if (in.empty()) return out.get()[W];
        if (out.empty()) return in.get()[W];
        int ans = 0;
        const auto& L = in.get();
        const auto& R = out.get();
        for (int i = 0; i <= W; i++) {
            ans = max(ans, L[i] + R[W - i]);
        }
        return ans;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(1);
    vector<vector<Item>> add_item(1);
    vector<vector<Query>> query(1);
    vector<vector<int>> types(1);
    int query_cnt = 0;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        int o;
        cin >> o;
        if (o == 1) {
            int x;
            cin >> x;
            --x;
            types[x].emplace_back(o);
            adj[x].emplace_back(cur);
            types.emplace_back();
            add_item.emplace_back();
            query.emplace_back();
            adj.emplace_back();
            cur++;
        } else if (o == 2) {
            int x, p, t;
            cin >> x >> p >> t;
            --x;
            add_item[x].emplace_back(p, t);
            types[x].emplace_back(o);
        } else if (o == 3) {
            int x;
            cin >> x;
            --x;
            types[x].emplace_back(o);
        } else {
            int x, p;
            cin >> x >> p;
            --x;
            types[x].emplace_back(o);
            query[x].emplace_back(p, query_cnt++);
        }
    }
    vector<int> ans(query_cnt);
    vector<int> adj_ptr(cur);
    vector<int> add_item_ptr(cur);
    vector<int> query_ptr(cur);
    Queue q;
    auto dfs = [&](auto&& dfs, int v) -> void {
        vector<Item> to_push_front;
        for (int o : types[v]) {
            if (o == 1) {
                int u = adj[v][adj_ptr[v]++];
                dfs(dfs, u);
            } else if (o == 2) {
                Item x = add_item[v][add_item_ptr[v]++];
                q.push_back(x);
            } else if (o == 3) {
                to_push_front.emplace_back(q.pop_front());
            } else {
                Query x = query[v][query_ptr[v]++];
                ans[x.id] = q.get(x.W);
            }
        }
        reverse(to_push_front.begin(), to_push_front.end());
        for (Item x : to_push_front) {
            q.push_front(x);
        }
        while (add_item_ptr[v]--) {
            q.pop_back();
        }
    };
    dfs(dfs, 0);
    for (int i = 0; i < query_cnt; i++) {
        cout << ans[i] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
#ifdef LOCAL_DEBUG
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}