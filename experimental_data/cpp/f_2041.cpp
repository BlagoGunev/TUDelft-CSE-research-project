#include <bits/stdc++.h>
using namespace std;
#define int long long
using u64 = uint64_t;
using u128 = __uint128_t;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 998244353;

int solve(int l, int r){
    set<int>st;
    vector<bool>vis(2*r-2*l+1);
    for(int i = 2; i<=(int)2e6; i++){
        int lw = (2*l+i-1)/i*i;
        for(int j = lw; j<=2*r; j+=i){
            if(j == i)continue;
            vis[j-2*l] = true;
        }
    }
    for(int i = 2*l; i<=2*r; i++){
        if(!vis[i-2*l]){
            //cout << "prime " << i << '\n';
            st.insert(i);
        }
    }
    st.insert(-5);
    st.insert(-4);
    st.insert(1e18);
    st.insert(2e18);
    vector<vector<pii>>buckets(400005);
    buckets[2*r-2*l].push_back({2*l,2*r});
    map<pii,int>hm;
    hm[{2*l,2*r}] = 1;
    for(int i = 400000; i>=1; i--){
        for(auto [l,r] : buckets[i]){
            int c = hm[{l,r}];
            //cout << l << ' ' << r << ' ' << c << '\n';
            auto it = st.lower_bound((l+r+1)/2);
            if(*it < (int)1e18 && *it < r){
                if(!hm.count({l,*it})){
                    buckets[(*it)-l].push_back({l,*it});
                }
                hm[{l,*it}] += c;  hm[{l,*it}]%=mod;
            }
            it = st.upper_bound((l+r)/2);
            it--;
            if(*it > 0 && *it > l){
                if(!hm.count({*it,r})){
                    buckets[r-(*it)].push_back({*it,r});
                }
                hm[{*it,r}] += c; hm[{*it,r}]%=mod;
                
            }
        }
    }
    int sum = 0;
    for(int i = 1; i<=400000; i++){
        if(buckets[i].size()){
            for(auto res : buckets[i]){
                sum += hm[res];
                sum%=mod;
            }
            break;
        }
    }
    return sum;
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        cout << solve(l,r) << '\n';
    }
    return 0;
}