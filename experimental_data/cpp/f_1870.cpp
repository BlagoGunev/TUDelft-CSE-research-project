#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<ll> cc(ll x, ll k){
    vector<ll> res;
    while(x != 0){
        res.push_back(x % k);
        x /= k;
    }
    reverse(res.begin(), res.end());
    return res;
}
vector<ll> y;
ll n, k;

const ll inf = (ll)1e18 + 10;
const int LG = 65;
ll kk[LG];
ll cum[LG];
ll num[LG];

ll f(ll w){
    int len = 0;
    ll wii = w;
    while(wii > 0){
        num[len] = wii % k;
        len ++ ;
        wii /= k;
    }
    ll cnt = 0;
    ll pre;
    int qq;
    int m = (int)y.size();
    for(int l = 0 ; l < len; l ++ ){
        // should be less than somewhere in here
        if(l + 1 < len){
            cnt ++ ;
        }
        pre = (l == 0 ? num[len - l - 1] - 1 : num[len - l - 1]);
        qq = m - (l + 1);
        cnt += pre * 1ll * ((kk[qq] - 1) / (k - 1));
        // for(int q = 0; (l + 1) + q < (int)y.size(); q ++ ){
        //     cnt += pre * 1ll * kk[q];
        // }
    }
    ll zhao = w;
    int tk = m - len;
    zhao = min(n + 1, min((n + 1) / kk[tk] + 1, zhao) * 1ll * kk[tk]);
    cnt += zhao - kk[m - 1];
    return cnt + 1;
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        cin >> n >> k;
        kk[0] = 1;
        cum[0] = 1;
        for(int i = 1; i < LG; i ++ ){
            kk[i] = min(n, min(inf/k + 1, kk[i-1]) * 1ll * k);
            cum[i] = min(inf, cum[i-1]+kk[i]);
        }
        y = cc(n, k);
        ll lf = 1;
        ll res = 0;
        while(lf <= n){
            ll y = min((n + 1)/lf + 1, k);
            ll rf = min((n + 1), lf * 1ll * y);
            ll l1 = lf, r1 = rf;
            ll mid;
            while(l1 < r1){
                mid = (l1 + r1) / 2;
                if(f(mid) - mid < 0){
                    l1 = mid + 1;
                }
                else{
                    r1 = mid;
                }
            }
            ll p1 = l1;
            l1 = p1, r1 = rf;
            while(l1 < r1){
                mid = (l1 + r1) / 2;
                if(f(mid) - mid <= 0){
                    l1 = mid + 1;
                }
                else{
                    r1 = mid;
                }
            }
            ll p2 = l1;
            res += p2 - p1;
            lf = rf;
        }
        cout << res << "\n";
    }
    return 0;
}