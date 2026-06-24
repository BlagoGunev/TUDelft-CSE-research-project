#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll myceil(ll a,ll b){
    if(a < 0 && b < 0){
        a = -a;
        b = -b;
    }
    if(a%b == 0)
        return a/b;
    if(a < 0)
        return a/b;
    return a/b+1;
}

ll myfloor(ll a,ll b){
    if(a < 0 && b < 0){
        a = -a;
        b = -b;
    }
    if(a%b == 0)
        return a/b;
    if(a < 0)
        return a/b-1;
    return a/b;
}

bool go(ll x,ll y,ll a,ll b,ll k){
    ll l = myceil(k*a-y,a-b);
    ll r = myfloor(x-k*b,a-b);
    if(l > r || r < 0 || max(0LL,l) > k)
        return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll x,y,a,b;
        cin >> x >> y >> a >> b;
        if(a < b)
            swap(a,b);
        if(a == b){
            cout << min(x,y)/a << "\n";
        }
        else{
            ll q = 0;
            for(ll i=30;i>-1;--i)
                if(go(x,y,a,b,q|(1<<i)))
                    q |= (1<<i);
            cout << q << "\n";
        }
    }
    return 0;
}