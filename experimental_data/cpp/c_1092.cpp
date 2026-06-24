/// In the name of God ///
#include<bits/stdc++.h>
#define PRIME bool ok(ll x) {ll i ;for(i = 2 ; i * i <= x ; i ++){if(x % i == 0){return 0;}}return 1 ;}
#define MYPOW ll f(ll x, ll y){ll i, s = 1 ;for(i = 1 ; i <= y ; ++ i){s *= x ;}return s ;}
#define DFS vector < ll > v[cs] ; ll us[cs], k ;void dfs(ll x){us[x] = 1 ;k ++ ;for(auto to : v[x]){if(!us[to]){dfs(to) ;}}}
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define sz size
#define se second
#define fr first
#define cs 1001000
#define stt string
#define INF 1000000007
#define sc 300200
#define LETS_GO_TEST PRIME  MYPOW  DFS
#define ios ios_base::sync_with_stdio(false);
using namespace std ;

/**-------**////LETS_GO_TEST////**-------**/

ll n, i, k ,kk, ks, kp, sh, j, t, www;
pair<ll, pair<string, ll> >s[222] ;
char us[222] ;
string a1, a2 ;
int main()
{
    ios
    cin >> n ;
    for(i = 1 ; i <= 2 * n - 2 ; ++ i)
    {
        cin >> s[i].se.fr ;
        s[i].fr = s[i].se.fr.sz() ;
        s[i].se.se = i ;
    }
    sort(s + 1, s + 1 + 2 * n - 2) ;
    a1 = s[2 * n - 3].se.fr ;
    a2 = s[2 * n - 2].se.fr ;
    for(i = 1 ; i <= 2 * n - 4 ; ++ i)
    {
        sh = 0 ;
        for(j = 0 ; j < s[i].se.fr.sz() ; ++ j)
        {
            if(s[i].se.fr[j] != a1[j])
            {
                sh ++ ;
                break ;
            }
        }
        ll xx = a2.sz() ;
        for(j = s[i].se.fr.sz() - 1 ; j >= 0 ; -- j)
        {
            xx -- ;
            if(s[i].se.fr[j] != a2[xx])
            {
                sh ++ ;
                break ;
            }
        }
        if(sh == 2)
        {
            www ++ ;
            swap(a1, a2);
            break ;
        }
    }
    for(i = 1 ; i <= 2 * n - 2 ; ++ i)
    {
        kp = 0 ;
        ks = 0 ;
        sh = 0 ;
        for(j = 0 ; j < s[i].se.fr.sz() ; ++ j)
        {
            if(s[i].se.fr[j] != a1[j])
            {
                sh = 1 ;
                ks ++ ;
                us[s[i].se.se] = 'S' ;
                break ;
            }
        }
        if(sh == 0)
            us[s[i].se.se] = 'P' ;
        i ++ ;
        if(ks > 0)
        {
            us[s[i].se.se] = 'P' ;
        }
        else
            us[s[i].se.se] = 'S' ;
    }
    for(i = 1 ; i <= 2 * n - 2 ; ++ i)
    {
        cout << us[i] ;
    }
    return false ;
}