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

const int mod = 998244353;

class int_mod {
private:

    int x;

    static int q_pow(int a, int x = mod - 2) {
        int res = 1;
        a = a % mod;
        while(x) {
            if(x&1) {
                res = 1LL * res * a % mod;
            }
            a = 1LL * a * a % mod;
            x >>= 1;
        }
        return res;
    }
 
public:

    int_mod(int v = 0) : x(v < 0 ? v + mod : v >= mod ? v - mod : v) {}

    int to_int() const { return x; }

    int_mod inv() const {
        assert(x);
        return int_mod(q_pow(x));
    }

    int_mod pow(int k) const {
        return int_mod(q_pow(x, k));
    }

    int_mod operator-() const { return int_mod(mod - x); }

    int_mod& operator+=(const int_mod& oth) {
        x += oth.x;
        if(x >= mod) { x -= mod; }
        return *this;
    }

    int_mod& operator-=(const int_mod& oth) {
        x -= oth.x;
        if(x < 0) { x += mod; }
        return *this;
    }

    int_mod& operator*=(const int_mod& oth) {
        x = 1LL * x * oth.x % mod;
        return *this;
    }

    int_mod& operator/=(const int_mod& oth) {
        x = 1LL * x * q_pow(oth.x) % mod;
        return *this;
    }

    inline friend int_mod operator+(const int_mod &a, const int_mod &b) { return int_mod(a) += b; }
    
    inline friend int_mod operator-(const int_mod &a, const int_mod &b) { return int_mod(a) -= b; }
    
    inline friend int_mod operator*(const int_mod &a, const int_mod &b) { return int_mod(a) *= b; }
    
    inline friend int_mod operator/(const int_mod &a, const int_mod &b) { return int_mod(a) /= b; }

};

namespace euler
{

const int maxn = 2e5 + 50;

int prime[maxn], tot;
int divs[maxn];

void euler(int n) {
    tot = 0;
    divs[1] = 1;
    for(int i = 2;i <= n;++i) {
        if(divs[i] == 0) {
            prime[++tot] = i;
            divs[i] = i;
        }
        for(int j = 1;j <= tot && i * prime[j] <= n;++j) {
            divs[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) {
                break;
            }
        }
    }   
}

}

const int maxn = 2e5 + 50;

int n;
int_mod wi[maxn];

struct edge_node {
    int to, nxt;
    int x, y;
} edge[maxn<<1];

int head[maxn], id = 1;

inline void add_edge(int u, int v, int x, int y) {
    edge[id] = edge_node {v, head[u], x, y};
    head[u] = id++;
    edge[id] = edge_node {u, head[v], y, x};
    head[v] = id++;
}

void dfs1(int u, int fa) {
    for(int i = head[u]; i;i = edge[i].nxt) {
        int v = edge[i].to;
        if(v == fa) { continue; }
        int x = edge[i].x, y = edge[i].y;
        wi[v] = wi[u] * int_mod(y) / int_mod(x);
        dfs1(v, u);
    }
}

int fenzi[maxn], fenmu[maxn];
int mxfenmu[maxn];

void dfs2(int u, int fa) {
    for(int i = head[u]; i;i = edge[i].nxt) {
        int v = edge[i].to;
        if(v == fa) { continue; }
        int x = edge[i].x, y = edge[i].y;
        map<int, int> fenmu_mp, fenzi_mp;
        while(y != 1) {
            if(fenmu[euler::divs[y]]) {
                fenmu[euler::divs[y]]--;
                fenmu_mp[euler::divs[y]]++;
            } else {
                fenzi[euler::divs[y]]++;
                fenzi_mp[euler::divs[y]]--;
            }
            y /= euler::divs[y];
        }
        while(x != 1) {
            if(fenzi[euler::divs[x]]) {
                fenzi[euler::divs[x]]--;
                fenzi_mp[euler::divs[x]]++;
            } else {
                fenmu[euler::divs[x]]++;
                fenmu_mp[euler::divs[x]]--;
                mxfenmu[euler::divs[x]] = max(mxfenmu[euler::divs[x]], fenmu[euler::divs[x]]);
            }
            x /= euler::divs[x];
        }
        dfs2(v, u);
        for(auto& _ : fenmu_mp) {
            fenmu[_.first] += _.second;
        }
        for(auto& _ : fenzi_mp) {
            fenzi[_.first] += _.second;
        }
    }
}

inline void solve() {
    cin >> n;
    for(int i = 1;i <= n - 1;++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        int tmp = __gcd(x, y);
        x /= tmp, y /= tmp;
        add_edge(u, v, x, y);
    }
    wi[1] = 1;
    dfs1(1, 0);
    int_mod ans = 0;
    for(int i = 1;i <= n;++i) {
        ans += wi[i];
    }
    dfs2(1, 0);
    int_mod add = 1;
    for(int i = 1;i <= n;++i) {
        if(mxfenmu[i]) {
            add *= int_mod(i).pow(mxfenmu[i]);
        }
    }
    ans *= add;
    cout << ans.to_int() << '\n';
}

inline void clear() {
    id = 1;
    for(int i = 1;i <= n;++i) {
        head[i] = 0;
        wi[i] = 0;
        fenzi[i] = fenmu[i] = mxfenmu[i] = 0;
    }
}

signed main() {	
    // freopen("a.in", "r", stdin);
    euler::euler(200000);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
        clear();
    }
    return 0;
}