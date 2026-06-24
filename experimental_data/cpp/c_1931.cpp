#include <bits/stdc++.h>
#define ll int
#define nl '\n'
#define pb push_back
#define pll pair<long long, long long>
using namespace std;

ll sum(ll n){
    ll s = 0;
    while(n){
        s += n % 10;
        n /= 10;
    }
    return s;
}

    ll a[200005];
void solve(){
    ll n;
    cin >> n;
    bool ok = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    ll first = a[1], cnt1 = 0 , cnt2 = 0, last = a[n];
    for(int i = 1;  i <= n; i++)
        if(a[i] != first){
            cnt1 = i - 1;
            ok = 1;
            break;
        }
    for(int i = n; i >= 1 ;i--){
        if(a[i] != last){
            cnt2 = n - i;
            ok = 1;
            break;
        }
    }
    if(ok)
        if(last == first)
            cout << n - (cnt1 + cnt2);
        else{
            if(cnt1 > cnt2)
                cout << n - cnt1;
            else cout << n - cnt2;
            
        }
    else cout << 0;
    cout << nl;
}
int main() {
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}