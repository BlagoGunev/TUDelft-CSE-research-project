#include "bits/stdc++.h"
using ll = long long  ;
const ll mod = 1e9 + 7 ;
const ll OO = 1e18 + 5 ;
const ll N = 2e5 + 5   ;
using namespace std;
int n , a[N] ,  k , tt = 1 ;
deque < int > adj[N] ;
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;

    cin >> tt ;
    while(tt--)
    {
        for(ll i = 0 ; i <= k ; ++i)adj[i].clear() ;

        cin >> n >> k ;

        for(ll i = 1 ; i <= n ; ++i)
            cin >> a[i] ;

        for(ll i = 1 ; i <= n  ; ++i)
        {
            adj[i % k].push_back(a[i] % k) ;
        }

        ll cnt = 0 ;
        for(ll i = 0 ; i < k ; ++i)
        {
            sort(adj[i].begin() , adj[i].end()) ;
            for(ll j = 0 ; j < adj[i].size() ; ++j)
            {
                if(adj[i][j] != i)
                {
                    ++cnt ;
                }
            }
        }
        if(cnt == 0)
        {
            cout << 0 << "\n";
            continue ;
        }
        if(cnt == 2)
        {
            cout << 1 << "\n";
            continue ;
        }

        cout << "-1\n";






    }




}