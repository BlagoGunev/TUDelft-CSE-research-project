#include <bits/stdc++.h>
#define ll long long
#define vi vector<long long>
#define fl(i,s,e) for(ll i = s; i < e; i++)
#define ip(v) for(ll i = 0; i < v.size(); i++) cin>>v[i];
#define si set<long long>
#define srt(v) sort(v.begin(), v.end())
#define um unordered_map<long long, long long>
#define pb push_back
#define lcm(a,b) (a*b)/__gcd(a,b)
int MOD = 1e9 + 7;
using namespace std;
//char b = B|' ' , char B = (b&'_')

int countDivisors(int n) {
    int count = 1; 
    for (int i = 2; i * i * i <= n; ++i) {
        if (n % i == 0) {
            int power = 0;
            while (n % i == 0) {
                n /= i;
                ++power;
            }
            count *= (power + 1);
        }
    }
    if (n > 1) count *= 2;
    return count;
}

void solve(){
    ll n;
    cin>>n;
    vector<long double> v(n);
    ip(v);
    ll res = 0;
    ll prev = 0;
    fl(i,1,n){
        long double tt = v[i-1]/v[i];
        long double tt2 = log2(tt);
        ll tt3 = tt2;
        if(tt2 != tt3)
        {
            if(tt2 > 0) tt3++;
        }
        tt3+=prev;
        if(tt3<0){
            prev = 0;
            continue;
        }
        res+=tt3;
        prev = tt3;
    }
    cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}