#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

template <typename T> inline void read(T &F) {

    int R = 1; F = 0; char CH = getchar();

    for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;

    for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;

    F *= R;

}

inline void file(string str) {

    freopen((str + ".in").c_str(), "r", stdin);

    freopen((str + ".out").c_str(), "w", stdout);

}

const int N = 19;

LL g[1 << N][N], t[N][1 << N], f[1 << N]; __int128 c[N][1 << N];

int n, edge[N][N]; char s[N]; vector<int> p; map<vector<int>, LL> M;

void FMT(LL *x) {

    for(int i = 0; i < n; i++)

        for(int j = 0; j < (1 << n); j++)

            if(j >> i & 1) x[j] += x[j ^ (1 << i)];

}

void dfs(int x, int y) {

    if(!x) {

        __int128 res = 0;

        for(int i = 0; i < (1 << n); i++)

            if((n - __builtin_popcount(i)) & 1) res -= c[0][i]; 

            else res += c[0][i];

        M[p] = (LL)res;

        return;

    }

    for(int i = y; i <= x; i++) {

        if(x != i && 2 * i > x) continue;

        for(int j = 0; j < (1 << n); j++) c[x - i][j] = c[x][j] * t[i][j];

        p.emplace_back(i); dfs(x - i, i); p.pop_back();

    }

}

int main() {

    //file("");

    read(n);

    for(int i = 0; i < n; i++) {

        scanf("%s", s);

        for(int j = 0; j < n; j++)

            edge[i][j] = (s[j] == '1');

    }

    for(int i = 0; i < n; i++) g[1 << i][i] = 1;

    for(int i = 1; i < (1 << n); i++) {

        if(__builtin_popcount(i) == 1) continue;

        for(int j = 0; j < n; j++)

            if(i >> j & 1) {

                for(int k = 0; k < n; k++)

                    if(edge[k][j]) g[i][j] += g[i ^ (1 << j)][k];

            }

    }

    for(int i = 0; i < (1 << n); i++) {

        const int x = __builtin_popcount(i);

        for(int j = 0; j < n; j++) t[x][i] += g[i][j];

    }

    for(int i = 0; i <= n; i++) FMT(t[i]);

    for(int i = 0; i < (1 << n); i++) c[n][i] = 1;

    dfs(n, 1);

    for(int i = 0; i < (1 << (n - 1)); i++) {

        int cnt = 1; vector<int> v;

        for(int j = 0; j + 1 < n; j++)

            if(i >> j & 1) cnt++;

            else v.emplace_back(cnt), cnt = 1;

        v.emplace_back(cnt); sort(v.begin(), v.end());

        f[i] = M[v];

    }

    for(int i = 0; i < n - 1; i++)

        for(int j = 0; j < (1 << (n - 1)); j++)

            if(!(j >> i & 1)) f[j] -= f[j | (1 << i)];

    for(int i = 0; i < (1 << (n - 1)); i++)

        cout << f[i] << ' '; puts("");

    #ifdef _MagicDuck

        fprintf(stderr, "# Time: %.3lf s", (double)clock() / CLOCKS_PER_SEC);

    #endif

    return 0;

}