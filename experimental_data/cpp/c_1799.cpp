#include<bits/stdc++.h> 
#include<functional>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
// ordered set :two additional operations in log(n)
    // order_of_key: The number of items in a set that are strictly smaller than k
    // find_by_order: It returns an iterator to the ith largest element

const int MOD = 998244353;
const long long INF = 1e18;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define ld long double
#define vi vector<long long>
#define vc vector<char>
#define vec vector
#define pb push_back
#define mii map<long long,long long>
#define pii pair<long long ,long long>
#define ff first
#define ss second
#define fr(i,b) for(long long i=0;i<b;i++)
#define frr(i,a,b) for(long long i=a;i<b;i++)
#define frn for(long long i=0;i<n;i++)
#define pr(n) cout<<n<<'\n'
#define endl '\n'
#define ip(v,n) for(long long __i = 0;__i<n;__i++) {long long __temp; cin>>__temp;v[__i]=__temp;}
#define all(x) (x).begin(), (x).end()
#define prv(vec) for(int i=0;i<vec.size();i++) if(i!=vec.size()-1) cout<<vec[i]<<" "; else cout<<vec[i]<<endl

int binpow(int a, int b, long long m = LLONG_MAX){
    a %= m;
    int res = 1;
    while (b > 0){
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
set<int>primes;
void sieve(int n){
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int  p = 2; p * p <= n; p++)
        if (prime[p] == true) 
            for (int i = p * p; i <= n; i += p) prime[i] = false;
    for (int p = 2; p <= n; p++) if (prime[p]) primes.insert(p);
}
int lg(int a,int b){
    int ans =0;
    while(binpow(b,ans)<=a) ans++;
    return ans-1;
}
void add_prime_divs(int x, map<int, int>&divs){
    int i = 2;
    while(i * i <= x){
        while (x % i == 0){
            divs[i]++;
            x /= i;
        }
        i++;
    }
    if(x > 1) divs[x]++;
}
int digit_sum(int n) {
    int ret = 0;
    while(n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
void pre(){
    
}

void solve(){       
    string s;
    cin>>s;
    int n = s.size();
    sort(all(s));
    char ls = s[s.size()-1];
    int i = s.size()-1;
    while(s[i]==ls) i--;
    int cnt = s.size()-1-i;

    string pref="",suff="";

    frn{
        if(i==n-1){
            pref+=s[i];
            break;
        }
        if(s[i]==s[i+1]){
            pref+=s[i];
            suff+=s[i];
            i++;
        }
        else if(s[i+1]==ls){
            for(int j=0;j<(cnt+1)/2;j++) pref+=ls;
            pref+=s[i];
            for(int j=0;j<cnt/2;j++) pref+=ls;
            break;
        }
        else{
            suff+=s[i];
            for(int j=i+1;j<n;j++) pref+=s[j];
            break;
        }
    }
    reverse(all(suff));
    pref+=suff;
    pr(pref);
}       


signed main(){
    fast_io;
    pre();
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}