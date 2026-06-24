#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, greater<T>, rb_tree_tag,tree_order_statistics_node_update>;
// ordered_set.find_by_order(k) returns the iterator to kth element
// ordered_set.order_of_key(k) returns the number of elements strictly less than k 
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define fastio ios_base::sync_with_stdio(0)
#define flush_off cin.tie(0)
#define mod 998244353
// #define int ll





void solve()
{
    int n,k; cin>>n>>k;
    int p[n]; for(auto &i:p) cin>>i;
    int q[k]; 
    ordered_set<ll>st;
    ll NOI = 0;
    for(auto &i:q)
    {
        cin>>i;

        NOI += st.order_of_key(i);

        st.insert(i);
    }
    st.clear();
    ll ans = 0;

    int mx = 0;

    for(int j=0; j<n; ++j)
    {
        for(int y=0; (1ll<<y)<mx and y<k;++y)
        {
            ll val = (1ll<<y)*p[j];
            ans += 1ll * (k-y) * st.order_of_key(val);
            ans  %= mod;


        }

        ll rem = k-1;
        for(int y=1; (1ll<<y)<p[j] and y<k; ++y)
        {
            ll val = p[j]/(1ll<<y);
            --rem;
            ans += 1ll * (k-y)*st.order_of_key(val);
            ans  %= mod;
        }

        ans += ((((rem*(rem+1)) / 2)%mod) *(st.size()))%mod;
        ans %= mod;

        st.insert(p[j]);
        mx = max(p[j],mx);
    }
    NOI %= mod;
    ans += (NOI*n)%mod;
    ans %= mod;

    cout<<ans<<'\n';
}

signed main()
{
    fastio;
    flush_off; //turn this off if cout needs to be flushed
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    cin>>t;
    while(t--) solve();
}