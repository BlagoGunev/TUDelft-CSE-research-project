#include<bits/stdc++.h>

using namespace std ;

#define ll long long

#define pb push_back

#define __ ios_base::sync_with_stdio(false); cin.tie(NULL);





const int N = 2e5 + 5;

vector <int> adj[N];

priority_queue<ll>q[N] ;



void dfs(ll u , ll p) {

    for (auto v: adj[u]) {

        if (v!=p) {

            dfs(v,u) ;

            if (q[u].size() < q[v].size()) swap(q[u],q[v]) ;

            while(q[v].size()) {

                ll f = q[v].top() ;

                q[v].pop() ;

                q[u].push(f) ;

            }

        }

    }

    if (q[u].size() == 0) q[u].push(1) ;

    else {

        ll f = q[u].top() ;

        q[u].pop() ;

        q[u].push(f+1) ;

    }

}



void sol() {

    ll n , k , i;

    cin >> n >> k ;

    for(i = 1 ; i< n ; i++) {

        ll u , v ;

        cin >> u >> v ;

        u-- , v-- ;

        adj[u].pb(v) ;

        adj[v].pb(u) ;

    }

    dfs(0,-1) ;

    ll ans = LLONG_MIN, del = 0 ;

    for (i = 0 ; i<= k ; i++) {

        ll b = min(n/2,n-del) ;

        ans = max(ans, (n-b-i) * (i-b)) ;

        if (q[0].size()) {

        ll f = q[0].top() ; q[0].pop() ;

        del += f ;}

    }

    cout << ans << endl ;



}



int main() {__



    int t = 1;

    //cin >> t ;

    while(t--) {

        sol() ;

    }

    return 0 ;

}