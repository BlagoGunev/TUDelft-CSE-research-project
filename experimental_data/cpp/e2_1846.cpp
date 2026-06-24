#include <bits/stdc++.h>
using namespace std;
#define all(arr) arr.begin(), arr.end()
#define forn(i, n) for (ll i = 0; i < n; i++)
#define print(arr) forn(i, arr.size()) { cout << arr[i] << ' '; }                     cout << endl;
#define scan(arr, n) forn(i, n) { long long int x; cin >> x; arr.push_back(x); }
#define ll long long 
#define pb push_back
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
double pi = 3.14159265358979323846;
template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<vector<T>> range_min;
    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }
    void build(const vector<T> &values) {
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_min.resize(levels);
        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);
        if (n > 0)
            range_min[0] = values;
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }
    void show() const {
        for (int i = 0; i < int(range_min.size()); i++) {
            for (int j = 0; j < int(range_min[0].size()); j++) {
                cout << range_min[i][j] <<endl[j + 1 == range_min[0].size()];
            }
        }
    }
    T query_value(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = highest_bit(to - from + 1);
        return better(range_min[lg][from], range_min[lg][to - (1 << lg) + 1]);
    }
};
ll int mul(ll int x,ll int y){
    return (x*1ll*y)%M;
}
ll int power(ll int x,ll int y){
   ll int ans=1;
    while(y>0){
        if(y&1) ans=mul(ans,x);
        x=mul(x,x);
        y=y>>1;
    }
    return ans;
}
ll int divide(ll int x,ll int y){
    return mul(x,power(y,M-2));
}
vector<ll int> getDivisors(ll int n)
{
    vector<ll int> ret; 
    for (ll int i=1; i<=sqrt(n); i++)
    {
       if (n%i == 0)
       {
          if (n/i == i)
              ret.pb(i);
          else {
              ret.pb(i);
              ret.pb(n/i);
          }
       }
    }
return ret;
}
int main(){
int t;
cin >> t;
set<ll int> st;
for(ll int k=2;k<=1e6;k++){
    ll int a=1+k,b=k*k,ma=1e18;
    while(true){
        a+=b;
        st.insert(a);
        if(ma/k<b) break;
        b=b*k;
    }
    // for(ll int j=3;j<=63;j++){
    //     ll int po=pow(k,j);
    //     if(po>1e18) break;
    //     po--;
    //     po=po/(k-1);
    //     if(po>1e18) break;
    //     else st.insert(po);
    // }
}

while (t--){
    ll int n;cin>>n;
    if(st.find(n)!=st.end()) cout<<"YES"<<endl;
    else if(n>=1e12){
        ll int y=4*n-3;
        ll int sq=sqrt(y);

        if(sq*sq==y){
            ll int c=(sq-1)/2;
            if(c*c+c+1==n){cout<<"YES"<<endl;}
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
}
}