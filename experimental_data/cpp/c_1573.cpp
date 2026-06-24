#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pin;

#ifndef ONLINE_JUDGE
bool MEMORY_ST;
#endif

const int N = 2e5 + 5;
const ll P = 998244353LL;
const int inf = 0x3f3f3f3f3f;

int T, n, tot, head[N], deg[N], d[N], f[N];
bool vis[N];

struct Edge {
    int to, nxt;
} e[N << 1];

inline void add(int from, int to) {
    e[++tot].to = to;
    e[tot].nxt = head[from];
    head[from] = tot;
    ++deg[to];
}

namespace Fread {
    const int L = 1 << 15;
    
    char buffer[L], *S, *T;
    
    inline char Getchar() {
        if(S == T) {
            T = (S = buffer) + fread(buffer, 1, L, stdin);
            if(S == T) return EOF;
        }
        return *S++;
    }
    
    template <class T> 
    inline void read(T &X) {
        char ch; T op = 1;
        for(ch = Getchar(); ch > '9' || ch < '0'; ch = Getchar())
            if(ch == '-') op = -1;
        for(X = 0; ch >= '0' && ch <= '9'; ch = Getchar()) 
            X = (X << 1) + (X << 3) + ch - '0'; 
        X *= op;
    }
    
} using Fread::read;   

inline bool chk() {
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        d[i] = deg[i];
        if (!d[i]) q.push(i);
    }
    for (; !q.empty(); ) {
        int x = q.front(); 
        q.pop();
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            --d[y];
            if (!d[y]) q.push(y);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            return 0;
    return 1;
}

inline int solve() {
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        d[i] = deg[i];
        f[i] = 0;
        if (!d[i]) {
            f[i] = 1;
            q.push(i);
        } 
    }
    for (; !q.empty(); ) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            --d[y];
            if (y > x) f[y] = max(f[y], f[x]);
            else f[y] = max(f[y], f[x] + 1);
            if (!d[y]) q.push(y);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, f[i]);
    return res;
}

#ifndef ONLINE_JUDGE
bool MEMORY_ED;
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("sample.in", "r", stdin);
    clock_t st_clock = clock();
#endif

    read(T);
    for (; T--; ) {
        read(n);
        tot = 0;
        for (int i = 1; i <= n; i++) head[i] = deg[i] = 0;
        for (int i = 1; i <= n; i++) {
            int k;
            read(k);
            for (int x, j = 1; j <= k; j++) {
                read(x);
                add(x, i);
            }
        }
        if (!chk()) puts("-1");
        else printf("%d\n", solve());
    }

#ifndef ONLINE_JUDGE
    clock_t ed_clock = clock();
    printf("time = %f ms\n", (double)(ed_clock - st_clock) / CLOCKS_PER_SEC * 1000);
    printf("memory = %.2f MB\n", (&MEMORY_ED - &MEMORY_ST) / 1024.0 / 1024.0);
#endif
    return 0;
}