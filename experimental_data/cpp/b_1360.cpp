// MAS
#include <bits/stdc++.h>
#include <string>
#define Speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pf pop_front
#define ll long long
#define el "\n"
#define llx LONG_MAX
#define lln LONG_MIN
#define ull unsigned long long
#define all(vec) vec.begin(),vec.end()
#define rall(vec) vec.rbegin(),vec.rend()
#define fx(x) fixed<<setprecision(x)
#define For(n) for(ll i=0;i<n;i++)
#define testes ll t;cin>>t;while(t--)
#define mx(x) *max_element(all(x))
#define mn(x) *min_element(all(x))
using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}
;


void PHARAOHS() {}




//ll AKA = 5e5+5 ;
//long long fr[AKA] ;
int main ()
{
    //freopen("scoreboard.in", "r", stdin);
    fast() ;

    testes
    {
        int n ; cin >> n ;
        vector<int>v(n) ;

        bool zero =false ;
        For(n)
        {
           cin >> v[i] ;

        }
        sort(v.begin() , v.end()) ;

        int mn = 5e5+5 ;
        for(int i=1 ;i<n ;i++)
        {
            mn = min(mn , v[i]-v[i-1]) ;
        }

        cout << mn << el ;



    }
}
/*


*/