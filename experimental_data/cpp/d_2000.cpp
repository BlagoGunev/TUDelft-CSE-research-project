#include <bits/stdc++.h>

using namespace std;

#define TL ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define rall(s) s.rbegin(),s.rend()
#define all(s) s.begin(),s.end()
#define pb push_back
#define se second
#define fi first
#define ll long long
#define ld long double
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"


const int N = 5e5 + 9 , mod = 1e9 + 7;
ll a[N] , dp[N] , c[N] , d[N] ,b[N];

void solve()
{
    ll n , q , i , j ,l ,r , x , y , s = 0 , f , k , m , mn = 1e18, mx = 0 ;
    cin>>n;
    for(i =1 ; i <= n; i++){
        cin>>a[i];
        c[i] = c[i -1 ] + a[i];
    }
    char ch;
    deque<int>v[4];
    for(j = 1; j <= n; j++){
        cin>>ch;
        b[j] = (ch == 'R');
        v[b[j]].pb(j);
    }
    while(v[0].size() && v[1].size() && v[0].front() < v[1].back()){
        s += c[v[1].back()] - c[v[0].front() - 1];
        v[0].pop_front();
        v[1].pop_back();
    }
    cout<<s<<"\n";

}

int main(){
    TL;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/
    int t = 1;
    cin>>t;
    while(t--)
     {
        solve();
     }
}