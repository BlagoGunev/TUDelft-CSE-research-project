#include<bits/stdc++.h>

using namespace std;

//~~~~ AAYUSH DHANKECHA ~~~~//

#define lli long long int

#define ll long long

#define MOD 1000000007

#define ld long double

#define f(i,x,n) for(ll i = x; i < n; i++)

#define rf(i,x,n) for(ll i = x; i >= n; i--)

#define fr(i,m) for(auto &i:m)

#define vl vector<long long>

#define vpl vector<pair<long long,long long>>

#define pb push_back

#define all(v) (v).begin(),(v).end()

#define rall(a) (a).rbegin(), (a).rend()

#define rll(v) (v).begin(), (v).end(),greater<ll>()

#define sl set<long long>

#define mll map<long long,long long>

#define pl pair<long long,long long>

#define PI 3.141592653589793238462

#define set_bits __builtin_popcountll

#define sz size()

#define bg begin()

#define ed end()

#define fi first

#define se second

#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))

#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))

#define gl(s) getline(cin,s)

#define le(s) s.length()

#define gcd(a,b) __gcd(a,b)

#define lcm(a,b) ((a*b)/(__gcd(a,b)))

 

#define Gili_gili_chhu ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

ld fast_pow(ld a, int p) {ld ret = 1.;for (; p; p/=2, a*=a) if (p&1) ret *= a;return ret;}

bool isprime(ll number){if (number <= 1)return false;if (number == 2)return true;if (number % 2 == 0) return false;int boundary = (int)floor(sqrt(number));for (int i = 3; i <= boundary; i += 2)if (number % i == 0)return false;return true;}

ll power (ll a, ll b){ll ans=1;while(b) {if(b&1)ans=(ans*a)%MOD;a=(a*a)%MOD;b=b/2;}return ans;}



void solve()

{

    ll n; cin>>n;

    vl v(n), v1(n);

    mll m;

    f(i,0,n) cin>>v[i], v1[i]=v[i];

    sort(all(v1));

    ll mn=v1[0], ans=v1[0];

    f(i,0,n){

        if(v[i]==v1[i]) continue;

        ans=gcd(ans, v[i]);

    }

    ans==mn ? cout<<"YES\n" : cout<<"NO\n";

}



int main()

{

    Gili_gili_chhu;

    int t=1;

    cin >> t;

    while(t--)

        solve();

    

    return 0;

}