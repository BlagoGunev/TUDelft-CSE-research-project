#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define SI size()
#define F first
#define S second
#define pb push_back
#define lowbit(x) x & -x
#define R return
#define OO (2e18L + 2)*1LL
#define int unsigned int
const ll Mod=998244353;
using namespace std ;

ll n;
ll x,y;
void Solve(){
    cin>>x>>y;
    cout<<max(x,y)<<endl;
}
int32_t main(){
//    freopen("in.txt", "r",stdin);
//    freopen("out.txt", "w",stdout);
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll tests = 1;
    bool multi = true;
    if(multi) cin >> tests;
    while(tests--){ Solve(); }
    return 0;
}