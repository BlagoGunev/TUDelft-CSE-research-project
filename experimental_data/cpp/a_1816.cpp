#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define int long long int
#define loop(i, b, e) for (__typeof(e) i = (b) - ((b) > (e)); i != (e) - ((b) > (e)); i += 1 - 2 * ((b) > (e)))
#define vi vector<int>
#define pi vector<pair<int,int>>
#define vec(a,n) vi a(n);loop(i,0,n) cin>>a[i];
#define endl "\n"
#define pb push_back
#define sort_(a) sort(a.begin(),a.end());
#define sort__(a) sort(a.begin(),a.end());reverse(a.begin(),a.end());
#define all(a) a.begin(),a.end()
const int mod = 1e9 + 7;
#define take(n) int n; cin >> n;
#define NO {cout<<"NO"<<endl;return;}
#define YES {cout<<"YES"<<endl;return;}
#define trackvec(vec) cerr<<#vec<<"- ";for(auto x:vec)cerr<<x<<" ";cerr<<endl;
#define sp " "
#define google(y) cout<<"Case #"<<y++<<": ";
#define finish(i){cout<<i<<endl;return;}
// #define cerr if(false)cerr

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

#define track(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " | ";
    err(++it, args...);
    cerr<<endl;
}
template<typename ...Args>
void Read(Args&... args) {
    (cin >> ... >> args);
}
#define read_ints(...) int __VA_ARGS__; Read(__VA_ARGS__);
// FAST MULTIPLICATION
int Mul(int a, int b, int M)
{
    int res = 0;
    const int k = 14;// floor(64 - log2(MAX_VALUE))
    while (a > 0) {
        int intA = a & ((1 << k) - 1);
        res = (res + b * intA) % M;
        a >>= k;
        b = (b << k) % M;
    }
    return res;
}

void solve()
{
    read_ints(a,b)
    if(__gcd(a,b)==1){
        cout<<1<<endl;
        cout<<a<<" "<<b<<endl;
        return;
    }
    cout<<2<<endl;
    cout<<a-1<<" "<<1<<endl;
    cout<<a<<" "<<b<<endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    // NAIVE SOLUTION CHECKER
    // freopen("testin.txt","r",stdin);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int test_cases=1;
    cin >> test_cases;
    int i=test_cases;
    while (test_cases--)
    {
        track(i-test_cases);
        solve();
    }
 
    return 0;
}