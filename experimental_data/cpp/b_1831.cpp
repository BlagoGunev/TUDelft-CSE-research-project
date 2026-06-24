#pragma comment(linker, "/STACK:2216777216")
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define cy cout<<"Yes"<<endl
#define cn cout<<"No"<<endl
#define cm cout<<-1<<endl
#define watch(x) cout << (#x) << " : " << x << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mod 1000000007
#define md 998244353
#define inf 1000000000000000000
#define point pair <ll,ll>
//#define int ll

typedef long long ll;
typedef long double ld;
using namespace std;

template<typename T> istream&operator>>(istream&is,vector<T>&vec){for(T&element:vec){is>>element;}return is;}
template<typename T> ostream&operator<<(ostream&is,vector<T>&vec){for(T&element:vec){is<<element << " ";}return is;}

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n);
    vector <ll> vv(n);
    cin >> v >> vv;
    map <ll, ll> mp1, mp2;
    ll k = 1;
    for (ll i = 1; i < n; i++){
        if (v[i - 1] != v[i]){
            mp1[v[i - 1]] = max(mp1[v[i - 1]], k);
            k = 1;
        } else k++;
    }mp1[v[n - 1]] = max(mp1[v[n - 1]], k);
    k = 1;

    for (ll i = 1; i < n; i++){
        if (vv[i - 1] != vv[i]){
            mp2[vv[i - 1]] = max(mp2[vv[i - 1]], k);
            k = 1;
        } else k++;
    }
    ll ans = 0;
    mp2[vv[n - 1]] = max(mp2[vv[n - 1]], k);
    for (auto t : mp1){
        ans = max(ans, t.ss + mp2[t.ff]);
    }
    for (auto t : mp2){
        ans = max(ans, t.ss + mp1[t.ff]);
    }
    cout << ans << endl;
}
signed main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        //cout << t << endl;
        solve();
    }
    return 0;
    }