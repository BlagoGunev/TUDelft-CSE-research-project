#if __has_include("pch.hpp")
#include "pch.hpp"
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#include <atcoder/modint>
//#include <atcoder/fenwicktree>
#endif
using namespace std;
//using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;
mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
//ld rand(ld a, ld b) {uniform_real_distribution<ld> uni(a, b); return uni(mt_rand);}
//const ld PI=3.141592653589793238462643383279;
const int mxN=1e6+50000;
const int mod=1e9+7;
const int mxlogN=19;
const ll inf=1e17;
const int iinf=1e9;
const int K=26;
ll a[mxN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        map<ll,vector<ll>> adj;
        set<ll> vis;
        for(int i=2; i<=n; i++)
        {
            ll sz=a[i]-1+i;
            adj[sz].push_back(sz+i-1);
        }
        queue<ll> q;
        vis.insert(n);
        q.push(n);
        while(q.size())
        {
            ll x=q.front(); q.pop();
            if(adj.count(x))
            for(ll y:adj[x])
            {
                if(!vis.count(y))
                {
                    vis.insert(y);
                    q.push(y);
                }
            }
        }
        cout << *vis.rbegin() << "\n";
    }
}