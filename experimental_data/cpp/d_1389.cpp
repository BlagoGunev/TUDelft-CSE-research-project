#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FOR(i,a,n) for(ll (i) = (a); i < (n); ++i)

const ll MOD = 1e9 + 7, inf = 1e18, N = 3e5 + 7;

void doWork(){
    ll n, k;
    cin >> n >> k;
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    ll sum = 0, ans = 0, anss = inf;
    if(l1 > l2){
        swap(l2, l1);
        swap(r2, r1);
    }
    ll mx = max(l1, l2);
    ll mn = min(r1, r2);
    bool noIntersection = 1;
    if(mn >= l2){
        sum += (mn - mx) * n;
        noIntersection = 0;
    }
    if(sum >= k){
        cout << 0 << '\n';
        return;
    }
    for(ll i = 0; i < n; i++){
        if(sum < k){
            if(noIntersection){
                ans += l2 - r1;
                if(r2 - l2 >= k - sum){
                    ans += k - sum;
                    cout << min(anss, ans) << '\n';
                    return;
                }
                else{
                    ans += r2 - l2;
                    sum += r2 - l2;
                }

                if(l2 - l1 >= k - sum){
                    ans += k - sum;
                    cout << min(anss, ans) << '\n';
                    return;
                }
                else{
                    ans += l2 - l1;
                    sum += l2 - l1;
                }
                anss = min(anss, ans + (k - sum) * 2);
            }
            else{
                if(max(r1, r2) - mn >= k - sum){
                    ans += k - sum;
                    cout << min(anss, ans) << '\n';
                    return;
                }
                else{
                    ans += max(r1, r2) - mn;
                    sum += max(r1, r2) - mn;
                }
                if(mx - min(l1, l2) >= k - sum){
                    ans += k - sum;
                    cout << min(anss, ans) << '\n';
                    return;
                }
                else{
                    ans += mx - min(l1, l2);
                    sum += mx - min(l1, l2);
                }
                anss = min(anss, ans + (k - sum) * 2);
            }
        }
    }
    cout << anss << '\n';
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    FOR(i, 1, T + 1) {
        doWork();
    }
}