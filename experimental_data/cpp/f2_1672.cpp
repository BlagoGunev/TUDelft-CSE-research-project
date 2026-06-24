#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

 

using ll = long long;

using namespace std;

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define ft first

#define sd second

 

constexpr ll N = ll(2e5) + 5;

constexpr int MOD = int(1e9) + 7;

constexpr int inf = 0x7f7f7f7f;



bool c;

int a[N], b[N], f[N], d[N], mx = 0;

vector<int> v[N];



void dfs(int n){

    d[n]++;

    for(auto& i : v[n]){

        if(d[i] == 1) c = true;

        if(!d[i]) dfs(i);

    }

    d[n]++;

}

void solve(){

    int n;

    cin >> n;



    for(int i = 0; i < n; i++){

        cin >> a[i];

        if(++f[a[i]] > f[mx]) mx = a[i];

    } 

    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n; i++) v[a[i]].push_back(b[i]);



    d[mx] = 2;

    c = false;



    for(int i = 1; i <= n; i++){

        if(i != mx) dfs(i);

    }

    if(c) cout << "WA\n";

    else cout << "AC\n";



    for(int i = 1; i <= n; i++){

        d[i] = f[i] = 0;

        v[i].clear();

    }

}

int main() {

    //freopen("lemonade.in", "r", stdin);

    //freopen("lemonade.out", "w", stdout);

 

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int tt = 1;

    cin >> tt;

 

    for(int i = 0; i < tt; i++) {

        solve();

    }

    

}