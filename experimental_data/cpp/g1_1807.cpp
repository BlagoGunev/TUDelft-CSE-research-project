#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define mk make_pair
#define pb push_back
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;

ll mod = 998244353 ;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ll fact[200001] ;
ll mul(ll a , ll b){
    return a * b % mod ;
}
ll power(ll a , ll b){
    ll ans = 1 , cur = a;
    while(b){
        if(b%2) ans *= cur ;
        cur *= cur ;
        cur %= mod ;
        ans %= mod ;
        b /= 2;
    }
    return ans % mod ;
}
ll divide(ll a , ll b){
    return mul(a , power(b , mod - 2)) % mod ;
}
ll nck(ll a , ll b){
    return divide(fact[a] , fact[b] * fact[a-b] % mod) % mod ;
}

const int N = 2e5 + 10 ;

void solve(){
    
    int n ; 
    cin >> n ; 
    vector<int> v(n) ; 
    for(int i=0 ; i<n ; i++){
        cin >> v[i] ; 
    }
    sort(v.begin() , v.end()) ; 
    if(v[0] != 1){
        cout << "NO\n" ; 
        return ;
    }
    int can[5001] = {0} ; 
    can[1] = 1 ; 
    for(int i=1 ; i<n ; i++){
        if(can[v[i]] == 0){
            cout << "NO\n" ; 
            return ;
        }
        for(int j=5000-v[i] ; j>=1 ; j--){
            if(can[j]) can[j + v[i]] = 1 ; 
        }
    }
    cout << "YES\n" ;
    
    

}
int main() {

    int t = 1 ;
    cin >> t ;
    while(t--){
        solve();
    }


	return 0;
}