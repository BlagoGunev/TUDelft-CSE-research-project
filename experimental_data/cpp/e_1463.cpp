#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

#define forn(i, x, y) for(int i = (x); i < (y); i++)

#define forr(i, x, y) for(int i = (x); i >= (y); i--)



#define int long long



//#pragma GCC optimize ("O3", "unroll-loops")

//#pragma GCC target ("avx2")



template<class T> void amax(T& a, const T& b) { a = max(a, b); }

template<class T> void amin(T& a, const T& b) { a = min(a, b); }



const int inf = 1e9, mod = 998244353, maxn = 3e5+35;



vector<int> g[maxn];

int nxt[maxn], prv[maxn], p[maxn], used[maxn], col[maxn];

bool good = true;

vector<int> ord;



void dfs(int v) {

    used[v] = 1;

    for(auto to : g[v]) {

        if(used[to] == 1) {

            good = false;

        }

        if(!used[to]) {

            dfs(to);

        }

    }

    used[v] = 2;

    ord.push_back(v);

}



signed main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);



    int n, k;

    cin >> n >> k;

    forn(i, 0, n) {

        cin >> p[i];

        p[i]--;

    }

    forn(i, 0, n) {

        nxt[i] = -1;

        prv[i] = -1;

        col[i] = -1;

    }



    forn(i, 0, k) {

        int x, y;

        cin >> x >> y;

        x--, y--;



        nxt[x] = y;

        prv[y] = x;

    }



    forn(i, 0, n) {

        if(col[i] == -1) {

            int c = i;

            while(prv[c] != -1) {

                c = prv[c];

                if(c == i) {

                    cout << 0;

                    return 0;

                }

            }

            col[c] = c;

            while(nxt[c] != -1) {

                c = nxt[c];

                col[c] = col[prv[c]];

            }

        }

    }



    vector<bool> vis(n);

    forn(i, 0, n) {

        if(i == col[i]) {

            int c = i;

            while(c != -1) {

                vis[c] = 1;

                if(p[c] != -1 && !(col[p[c]] == col[c] && vis[p[c]])) {

                    g[col[p[c]]].push_back(col[c]);

                }

                c = nxt[c];

            }

        }

    }



    forn(i, 0, n) {

        if(i == col[i] && !used[i]) {

            dfs(i);

        }

    }

    if(!good) {

        cout << 0;

        return 0;

    }

    reverse(all(ord));



    for(auto it : ord) {

        int c = it;

        while(c != -1) {

            cout << c + 1 << " ";

            c = nxt[c];

        }

    }



    return 0;

}