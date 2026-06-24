#include <bits/stdc++.h>
using namespace std;
template<typename Data, typename Aux>
class LazySegmentTree {
private:
    int n;
    vector<Data> t;
    vector<Aux> lz;
    void build(int L, int R, int v, const vector<Data> &a) {
        if (L == R) {
            t[v] = a[L];
            return;
        }
        int M = (L + R)>>1;
        build(L, M, v<<1, a);
        build(M + 1, R, v<<1|1, a);
        t[v] = Data::merge(t[v<<1], t[v<<1|1]);
    }
    void push(int v, int len) {
        lz[v].apply(t[v<<1], lz[v<<1], (len + 1) / 2);
        lz[v].apply(t[v<<1|1], lz[v<<1|1], len / 2);
        lz[v] = Aux();
    }
    void update(int qL, int qR, const Aux &val, int L, int R, int v) {
        if (qL <= L && R <= qR) {
            val.apply(t[v], lz[v], R - L + 1);
            return;
        }
        if (L > qR || R < qL) return;
        push(v, R - L + 1);
        int M = (L + R)>>1;
        update(qL, qR, val, L, M, v<<1);
        update(qL, qR, val, M + 1, R, v<<1|1);
        t[v] = Data::merge(t[v<<1], t[v<<1|1]);
    }
    Data query(int qL, int qR, int L, int R, int v) {
        if (qL <= L && R <= qR) return t[v];
        if (L > qR || R < qL) return Data();
        push(v, R - L + 1);
        int M = (L + R)>>1;
        return Data::merge(query(qL, qR, L, M, v<<1), query(qL, qR, M + 1, R, v<<1|1));
    }
public:
    LazySegmentTree(int n) : n(n) {
        t.resize(n<<2);
        lz.resize(n<<2);
    }
    LazySegmentTree(int n, const vector<Data> &a) : n(n) {
        t.resize(n<<2);
        lz.resize(n<<2);
        build(1, n, 1, a);
    }
    void update(int qL, int qR, const Aux &val) {
        update(qL, qR, val, 1, n, 1);
    }
    Data query(int qL, int qR) {
        return query(qL, qR, 1, n, 1);
    }
};
const long long INF = 1e18;
struct Data {
    long long minVal;
    int count;
    Data(long long val, int count=1) : minVal(val), count(count) {}
    Data() : minVal(INF), count(0) {};
    static Data merge(const Data &data1, const Data &data2);
};
Data Data::merge(const Data &data1, const Data &data2) {
    if (data1.minVal < data2.minVal) {
        return data1;
    }
    if (data2.minVal < data1.minVal) {
        return data2;
    }
    return Data(data1.minVal, data1.count + data2.count);
}
struct Aux {
    long long add;
    Aux(long long add) : add(add) {}
    Aux() : add(0) {}
    void apply(Data &data, Aux &aux, int len) const {
        data.minVal += add;
        aux.add += add;
    }
};
void solve(int testCase=1) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> forward(2 * n + 1);
    for (int i = 1, a, b; i <= m; ++i) {
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        forward[a].push_back(b);
        forward[b].push_back(a + n);
        forward[a + n].push_back(b + n);
    }
    int ans = n;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    vector<Data> a(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = Data(0);
    }
    LazySegmentTree<Data, Aux> st(2 * n, a);
    for (int i = 1; i <= 2 * n; ++i) {
        for (int R : forward[i]) {
            q.push({R, i});
        }
        while (!q.empty() && q.top()[0] <= i) {
            auto [R, L] = q.top();
            q.pop();
            st.update(L, R - 1, Aux(1));
        }
        if (i >= n) {
            int j = i - n + 1;
            Data d = st.query(j, i - 1);
            int curAns = n - 1;
            if (d.minVal == 0) {
                curAns -= d.count;
            }
            ans = min(ans, curAns);
            for (int R : forward[j]) {
                int L = j;
                st.update(L, R - 1, Aux(-1));
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //solve();
    int t = 10;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
}