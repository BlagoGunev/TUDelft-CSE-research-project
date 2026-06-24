#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define IOS std::cin.tie(nullptr)->sync_with_stdio(false);
using namespace std;
struct InputOutputStream {
    enum { SIZE = 1000001 };
    char ibuf[SIZE], *s, *t, obuf[SIZE], *oh;
    bool eof;
 
    InputOutputStream() : s(), t(), oh(obuf), eof(false) {}
    ~InputOutputStream() { fwrite(obuf, 1, oh - obuf, stdout); }
 
    explicit operator bool() const {
        return static_cast<bool>(eof == false);
    }
 
    inline char read() {
        if (s == t) t = (s = ibuf) + fread(ibuf, 1, SIZE, stdin);
        return s == t ? -1 : *s++;
    }
 
    inline InputOutputStream &operator>>(char* x) {
        static char c;
        for (c = read(); isspace(c); c = read())
            if (c == -1) {eof = true; return *this;}
        for (; !isspace(c); c = read()) *x = c, ++x;
        *x = 0;
        return *this;
    }
 
    template <typename T>
    inline InputOutputStream &operator>>(T &x) {
        static char c;
        static bool iosig;
        for (c = read(), iosig = false; !isdigit(c); c = read()) {
            if (c == -1) {eof = true; return *this;}
            iosig |= c == '-';
        }
        for (x = 0; isdigit(c); c = read()) x = x * 10 + (c ^ '0');
        if (iosig) x = -x;
        return *this;
    }
 
    inline void print(char c) {
        if (oh == obuf + SIZE) {
            fwrite(obuf, 1, SIZE, stdout);
            oh = obuf;
        }
        *oh++ = c;
    }
 
    template <typename T>
    inline void print(T x) {
        static int buf[23], cnt;
        if (x != 0) {
            if (x < 0) print('-'), x = -x;
            for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 | 48;
            while (cnt) print((char)buf[cnt--]);
        } else print('0');
    }
 
    template <typename T>
    inline InputOutputStream &operator<<(const T &x) {
        print(x);
        return *this;
    }
 
    inline void print(const char* x) {
        for(; *x; x++)
            print(*x);
    }

    inline void print(char* x) {
        for(; *x; x++)
            print(*x);
    }    
} io;

#define cin io
#define cout io

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using sta = pair<bool, pii>;

const int maxn = 2e5 + 50;

int n, k;
vector<int> a, sum;

inline int query(int l, int r) {
    return sum[r] - sum[l - 1];
}

inline sta is_valid(int diff) {
    for(int x = 1;x <= n - diff;++x) {
        int y = x + diff;
        int res = query(x, y);
        if(res - (n - res) >= k) {
            return sta(true, {x, y});
        }
    }
    return sta(false, {-1, -1});
}

/*
1
2 1
1 2

*/

inline void solve() {
    cin >> n >> k;
    a = vector<int>(n + 1);
    for(int i = 1;i <= n;++i) { cin >> a[i]; }
    sum = vector<int>(n + 1);
    for(int i = 1;i <= n;++i) {
        sum[a[i]]++;
    }
    for(int i = 1;i <= n;++i) {
        sum[i] += sum[i - 1];
    }
    int l = 0, r = n - 1;
    pii ans = {-1, -1};
    while(l <= r) {
        int mid = l + ((r - l) >> 1);
        auto res = is_valid(mid);
        if(res.first) {
            r = mid - 1;
            ans = res.second;
        }  else {
            l = mid + 1;
        }
    }
    vector<pii> ans2;
    int cnt1 = 0, cnt0 = 0, pre = 1;
    for(int i = 1;i <= n;++i) {
        if(ans.first <= a[i] && a[i] <= ans.second) {
            ++cnt1;
        } else {
            ++cnt0;
        }
        if(cnt1 > cnt0 && ans2.size() < k - 1) {
            ans2.emplace_back(pii(pre, i));
            pre = i + 1;
            cnt1 = 0, cnt0 = 0;
        }
    }
    ans2.emplace_back(pii(pre, n));
    cout << ans.first << ' ' << ans.second << '\n';
    for (auto p : ans2) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

signed main() {	
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}