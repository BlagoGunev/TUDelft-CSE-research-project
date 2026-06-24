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

const int N = 2e5 + 10;

int dep[N], deg[N]; vector<int> edge[N];

int main() {

    //file("");

    int T; read(T);

    while(T--) {

        int n, m; read(n), read(m);

        for(int i = 1; i <= n; i++) edge[i].clear(), dep[i] = deg[i] = 0;

        for(int i = 1; i <= m; i++) {

            int x, y; read(x), read(y);

            edge[x].emplace_back(y); deg[y]++;

        }

        queue<int> q;

        for(int i = 1; i <= n; i++)

            if(deg[i] == 0) q.push(i);

        int res = 0;

        while(!q.empty()) {

            int p = q.front(); q.pop(); if(dep[p] == 2) res++;

            for(int i : edge[p]) {

                deg[i]--; if(deg[i] == 0) q.push(i);

                if(dep[p] < 2) dep[i] = max(dep[i], dep[p] + 1);

            }

        } 

        cout << res << '\n';

        for(int i = 1; i <= n; i++)

            if(dep[i] == 2) cout << i << ' ';

        puts("");



    }

    

    #ifdef _MagicDuck

        fprintf(stderr, "# Time: %.3lf s", (double)clock() / CLOCKS_PER_SEC);

    #endif

    return 0;

}