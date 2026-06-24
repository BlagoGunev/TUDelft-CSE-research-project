#include <bits/stdc++.h>

using namespace std;



#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



#ifdef LOCAL

#include "/home/elt0khy/comp/debug.h"

#endif



#define rep(n) for (int i=0; i<n; i++)

#define V vector

#define all(x) (x).begin(), ((x).end())

using ll = long long;



int tc;



const int N = 1e3 + 10;

char g[N][N];

int n, m, q, x, y;

void print() {

    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) 

        cout << g[i][j] << " \n"[j==m];

}



void solve() {

    cin >> n >> m >> q;

    int n_on = 0, n_good = 0;

    auto is_good = [&](int i, int j) {

        int max_col = n_on / n;

        if(n_on % n) max_col++;

        int max_row = (n_on % n);

        if(max_row == 0) max_row = n;

        if(j < max_col) return true;

        if(j > max_col) return false;

        return (i <= max_row);

    };

    auto last_good = [&]() {

        int max_col = n_on / n;

        if(n_on % n) max_col++;

        int max_row = (n_on % n);

        if(max_row == 0) max_row = n;

        return make_pair(max_row, max_col);

    };

    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {

            cin >> g[i][j];

            if(g[i][j] == '*') n_on++;

        }

    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) 

        if(g[i][j] == '*') 

            n_good += (is_good(i, j));



    while(q--) {

        cin >> x >> y;

        if(g[x][y] == '*') {

            auto u = last_good();

            n_on--;

            if(is_good(x, y)) n_good--;

            if(g[u.first][u.second]=='*') n_good--;

            g[x][y] = '.';

        } else {

            n_on++;

            if(is_good(x, y)) n_good++;

            auto u = last_good();

            if(g[u.first][u.second]=='*') n_good++;

            g[x][y] = '*';

        }

        cout << n_on - n_good << '\n';

        //print();

    }





}



int main() {

    ios::sync_with_stdio(0), cin.tie(0);

    //freopen("in", "r", stdin);



    int t = 1;

    while( t-- ) tc++, solve();

    return 0;

}



/*

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



*/