#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const int INF = 1e9;
struct Info{
    int mn = INF, mx = -INF;
};

struct Tag{
    int mul = 1, add = 0;
};

Info operator+(const Info &a, const Info &b){
    return {min(a.mn, b.mn), max(a.mx, b.mx)};
}

void apply(Info &x, Tag &a, Tag f){
    x.mn = x.mn * f.mul + f.add;
    x.mx = x.mx * f.mul + f.add;
    if (x.mn > x.mx) swap(x.mn, x.mx);
    a.mul *= f.mul;
    a.add = a.add * f.mul + f.add;
}

template<class Info, class Tag>
struct LazySegmentTree{
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree() {}

    LazySegmentTree(int n, Info _init = Info()){
        init(vector<Info>(n, _init));
    }

    LazySegmentTree(const vector<Info> &_init){
        init(_init);
    }

    void init(const vector<Info> &_init){
        n = (int)_init.size();
        info.assign((n << 2) + 1, Info());
        tag.assign((n << 2) + 1, Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r){
            if (l == r){
                info[p] = _init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            pull(p);
        };
        build(1, 0, n - 1);
    }
    
    void pull(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void apply(int p, const Tag &v){
        ::apply(info[p], tag[p], v);
    }
    
    void push(int p){
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    
    void modify(int p, int l, int r, int x, const Info &v){
        if (l == r){
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x <= m){
            modify(2 * p, l, m, x, v);
        } 
        else{
            modify(2 * p + 1, m + 1, r, x, v);
        }
        pull(p);
    }
    
    void modify(int p, const Info &v){
        modify(1, 0, n - 1, p, v);
    }
    
    Info query(int p, int l, int r, int x, int y){
        if (l > y || r < x){
            return Info();
        }
        if (l >= x && r <= y){
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m + 1, r, x, y);
    }
    
    Info query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }
    
    void modify(int p, int l, int r, int x, int y, const Tag &v){
        if (l > y || r < x){
            return;
        }
        if (l >= x && r <= y){
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        modify(2 * p, l, m, x, y, v);
        modify(2 * p + 1, m + 1, r, x, y, v);
        pull(p);
    }
    
    void modify(int l, int r, const Tag &v){
        return modify(1, 0, n - 1, l, r, v);
    }

    int find_first(int p, int l, int r, int L, int R, const function<bool(const Info&)> &f, Info &pre){
        if (l > R || r < L){
            return r + 1;
        }
        if (l >= L && r <= R){
            if (!f(pre + info[p])){
                pre = pre + info[p];
                return r + 1;
            }
            if (l == r) return r;
            int m = (l + r) / 2;
            push(p);
            int res;
            if (f(pre + info[2 * p])){
                res = find_first(2 * p, l, m, L, R, f, pre);
            }
            else{
                pre = pre + info[2 * p];
                res = find_first(2 * p + 1, m + 1, r, L, R, f, pre);
            }
            return res;
        }
        int m = (l + r) / 2;
        push(p);
        int res = m + 1;
        if (L <= m){
            res = find_first(2 * p, l, m, L, R, f, pre);
        }
        if (R > m && res == m + 1){
            res = find_first(2 * p + 1, m + 1, r, L, R, f, pre);
        }
        return res;
    }

    int find_first(int l, int r, const function<bool(const Info&)> &f){
        Info pre = Info();
        return find_first(1, 0, n - 1, l, r, f, pre);
    }

    int find_last(int p, int l, int r, int L, int R, const function<bool(const Info&)> &f, Info &suf){
        if (l > R || r < L){
            return l - 1;
        }
        if (l >= L && r <= R){
            if (!f(info[p] + suf)){
                suf = info[p] + suf;
                return l - 1;
            }
            if (l == r) return r;
            int m = (l + r) / 2;
            push(p);
            int res;
            if (f(info[2 * p + 1] + suf)){
                res = find_last(2 * p + 1, m + 1, r, L, R, f, suf);
            }
            else{
                suf = info[2 * p + 1] + suf;
                res = find_last(2 * p, l, m, L, R, f, suf);
            }
            return res;
        }
        int m = (l + r) / 2;
        push(p);
        int res = m;
        if (R > m){
            res = find_last(2 * p + 1, m + 1, r, L, R, f, suf);
        }
        if (L <= m && res == m){
            res = find_last(2 * p, l, m, L, R, f, suf);
        }
        return res;        
    }

    int find_last(int l, int r, const function<bool(const Info&)> &f){
        Info suf = Info();
        return find_last(1, 0, n - 1, l, r, f, suf);
    }
};

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        const int n = s.size();
        vector<Info> init(n + 1);
        int sum = 0;
        init[0] = {sum, sum};
        vector<int> pre(n + 1);
        for(int i = 1; i <= n; i++){
            sum += (s[i - 1] == '(' ? 1 : -1);
            pre[i] = sum;
            init[i] = {sum, sum};
        }
        LazySegmentTree<Info, Tag> seg(init);

        map<int, vector<int> > mp;
        for(int i = 0; i <= n; i++){
            mp[pre[i]].push_back(i);
        }

        auto update = [&](int x){
            int sum = seg.query(x, x).mn;
            seg.modify(1, x, {-1, 0});
            seg.modify(x + 1, n, {1, -2 * sum});
        };

        LL ans = 0;

        for(auto &[x, v] : mp){
            for(int i = 0, j = 0; i < v.size(); i++){
                j = max(j, i + 1);

                auto check = [&](int l, int r){
                    update(l - 1);
                    update(r);
                    bool ans = seg.query(1, n).mn >= 0;
                    update(l - 1);
                    update(r);
                    return ans;
                };

                while(j < v.size() && check(v[i] + 1, v[j])) j++;
                ans += j - i - 1;
            }
        }
        cout << ans << '\n';
    }

}