#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tp = tuple<ll,bool,ll>;

const ll inf = 9223372036854775807;

/*
1
5 5 3
411593 520888 718692 111623 920350
1 1 5 1 85964
1 4 4 1 419928
4 2 5 4 569448
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n,m,k;
        cin >> n >> m >> k;
        vector<ll> x(n);
        for(ll i=0;i<n;++i)
            cin >> x[i];
        vector<ll> dp(k+2,inf);
        dp[0] = 0;
        vector<ll> p(k+2);
        vector<vector<tp> > g(n);
        g[0].push_back(make_tuple(0,false,0));
        g[n-1].push_back(make_tuple(m-1,true,k+1));
        for(ll i=1;i<k+1;++i){
            ll a,b,c,d,h;
            cin >> a >> b >> c >> d >> h;
            --a;
            --b;
            --c;
            --d;
            p[i] = -h;
            g[a].push_back(make_tuple(b,true,i));
            g[c].push_back(make_tuple(d,false,i));
        }
        for(ll i=0;i<n;++i){
            sort(g[i].begin(),g[i].end());
            pair<ll,ll> w = make_pair(-1,inf);
            for(const auto& temp:g[i]){
                auto [j,f,id] = temp;
                if(!f){
                    if(dp[id] != inf)
                        if(w.second == inf || dp[id]+p[id]-w.second < x[i]*(j-w.first))
                            w = make_pair(j,dp[id]+p[id]);
                }
                else{
                    if(w.second != inf)
                        dp[id] = min(dp[id],w.second+x[i]*(j-w.first));
                }
            }
            w = make_pair(m,inf);
            for(ll r=g[i].size()-1;r>-1;--r){
                auto [j,f,id] = g[i][r];
                if(!f){
                    if(dp[id] != inf)
                        if(w.second == inf || dp[id]+p[id]-w.second < x[i]*(w.first-j))
                            w = make_pair(j,dp[id]+p[id]);
                }
                else{
                    if(w.second != inf)
                        dp[id] = min(dp[id],w.second+x[i]*(w.first-j));
                }
            }
        }
        if(dp[k+1] == inf)
            cout << "NO ESCAPE\n";
        else
            cout << dp[k+1] << "\n";
    }
    return 0;
}