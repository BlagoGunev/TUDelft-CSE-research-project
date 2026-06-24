#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ii,ll>
#define f(i,a,b) for(ll i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
///I hope I will get uprating and don't make mistakes
///I will never stop programming
///sqrt(-1) Love C++
///Please don't hack me
///@TheofanisOrfanou Theo830
///Think different approaches (bs,dp,greedy,graphs,shortest paths,mst)
///Stay Calm
///Look for special cases
///Beware of overflow and array bounds
///Think the problem backwards
///Codeforces Round 954 (Div. 3)
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll posa = 0;
        ll ans = 0;
        ll arr[n];
        map<ll,vector<ll> >mp;
        f(i,0,n){
            cin>>arr[i];
            mp[arr[i] % k].pb(arr[i]);
        }
        for(auto y:mp){
            sort(all(y.S));
            if(y.S.size() % 2){
                posa++;
                ll sum = 0;
                ll m = y.S.size();
                f(i,1,m){
                    if(i % 2){
                        sum -= y.S[i];
                    }
                    else{
                        sum += y.S[i];
                    }
                }
                ll cur = sum;
                f(i,2,m){
                    sum -= y.S[i-2];
                    sum += y.S[i-1];
                    sum += y.S[i-1];
                    sum -= y.S[i];
                    i++;
                    cur = min(cur,sum);
                }
                cur /= k;
                ans += cur;
            }
            else{
                ll res = 0;
                ll p = 0;
                for(auto x:y.S){
                    if(!p){
                        res -= x;
                    }
                    else{
                        res += x;
                    }
                    p ^= 1;
                }
                res /= k;
                ans += res;
            }
        }
        if(posa >= 2){
            ans = -1;
        }
        cout<<ans<<"\n";
    }
}