#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define sz(x) (int)(x.size())

using ll = long long;

int recur_depth = 0;
#ifdef DEBUG
#define db(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define db(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}


constexpr ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());

        ll ans = 0;
        for (int i = n - 1; i > 0; --i) {
            a[i] -= a[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] * (n - i) >= k) {
                ans += k;
                break;
            }
            else {
                ans += a[i] * (n - i);
                k -= a[i] * (n - i);
                ++ans;
            }
        }
        cout << ans << endl;
    }
    

}