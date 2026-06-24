#include "bits/stdc++.h"
using ll = long long  ;
const ll mod = 998244353 ;
const ll OO = 3e18 + 5 ;
const ll N = 5e5 + 5   ;
using namespace std;
ll n , tt = 1 ;
string s[N] ;
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;


     cin >> tt ;
    while(tt--)
    {
        cin >> n ;

        for(int i = 0 ; i < n ; ++i)cin >> s[i];


        ll ans = 0 ;
        for(int level = 0 ; level < n ; ++level)
        {
            map < char , ll > cnt[n + 1] ;
            ll flag = 0 ;
            for(int j = level ; j < n - level - 1 ; ++j)
            {
                cnt[flag++][s[level][j]] += 1 ;
            }
            flag = 0 ;
            for(int j = n - level - 1 ; j > level ; --j)
            {
                cnt[flag++][s[n - level - 1][j]] += 1 ;
            }
            flag = 0 ;
            for(int j = level ; j < n - level - 1 ; ++j)
            {
                cnt[flag++][s[j][n - level - 1]] += 1 ;
            }
            flag = 0 ;
            for(int j = n - level - 1 ; j > level ; --j)
            {
                cnt[flag++][s[j][level]] += 1 ;
            }

            for(int j = 0 ; j < flag  ; ++j)
            {
                ll mx = 0 , sum = 0 ;
                for(auto x : cnt[j])mx = max(mx ,(ll) (x.first - 'a')) ;
                for(auto x : cnt[j])
                {
                    ans += (mx - (x.first - 'a')) * x.second  ;
                }
            }

        }

        cout << ans << "\n";


    }



}