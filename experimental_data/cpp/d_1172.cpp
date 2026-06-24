#include <bits/stdc++.h>
using namespace std;
//{
    #ifdef lawfung
    #define debug(...) do {\
        fprintf(stderr, "%s - %d : (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
        _DO(__VA_ARGS__);\
    }while(0)
    template<typename I> void _DO(I&&x) {cerr << x << '\n';}
    template<typename I, typename ...T> void _DO(I&&x,T&&...tail) {cerr << x << ", "; _DO(tail...);}
    #else
    #define debug(...)
    #endif
    typedef long long ll;
    typedef pair<int,int> pii;
    typedef pair<ll,ll> pll;
    typedef long double ld;
    #define F first
    #define S second
    #define ALL(x) (x).begin(),(x).end()
    #define SZ(x)   (ll)x.size()
    // #define pb push_back
    #define eb emplace_back
    #define stp setprecision(30)<<fixed
    #define YES cout<<"YES"<<'\n'
    #define NO cout<<"NO"<<'\n'
    #define Yes cout<<"Yes"<<'\n'
    #define No cout<<"No"<<'\n'
    const ll INF = 0x3f3f3f3f3f3f3f3f;
    const int NF = 0x3f3f3f3f;
    // const ll MOD = 998244353;
    const ll MOD = 998244353 ;
    const ll MO3 = 1e9 + 87;
    const ll MO4 = 1e9 + 93;
    const ld PI=3.14159265358979323846264338327950288;
    const ld eps=1e-7;
//}
const ll MAX = 1e3 + 6, Mlg = __lg(MAX) + 2;
ll n;
int ar1[MAX];
int ar2[MAX];
int p1[MAX];
int p2[MAX];
int main() {
    ios_base::sync_with_stdio(0);   cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> ar1[i];
        p1[ar1[i]]= i;
    }
    for(int i = 1; i <= n; ++ i) {
        cin >> ar2[i];
        p2[ar2[i]] = i;
    }
    swap(ar1, ar2);
    swap(p1, p2);

    vector<pii> A;
    for(int i = 1; i <= n; ++ i) {
        if(p1[i] == i && p2[i] == i)    continue;
        A.eb(p2[i],i);
        A.eb(i, p1[i]);
        p1[ar1[i]] = p1[i];
        ar1[p1[i]] = ar1[i];
        p2[ar2[i]] = p2[i];
        ar2[p2[i]] = ar2[i];
        // for(int j = 1; j <= n; ++ j ){
        //     cout << ar1[j] << ' '<< ar2[j] << '\n';
        // }
        // cout << '\n';
    }
    cout << SZ(A) / 2 << '\n';
    for(int i = 0; i < SZ(A); ++ i){
        cout << A[i].F << ' ';
        cout << A[i].S;
        if(i & 1)   cout << '\n';
        else        cout << ' ';
    }
    return 0;
}