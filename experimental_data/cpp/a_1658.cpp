#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long int ll;

typedef __int128 lll;

typedef long double ld;

#define nl cout << "\n"

#define vc vector

#define mapll map<ll,ll>

#define setll set<ll>

#define ff first

#define ss second

#define pb push_back

#define mp make_pair

#define loopf(i,a,b) for(int i=a;i<b;i++)

#define loopb(i,b,a) for(int i=a-1;i>=b;i--)

#define rep(i,a,b,x) for(int i=a;i<b;i+=x)

typedef vector<ll> vll;

typedef vector<int> vi;

typedef vector<bool> vb;

typedef vector<int> vi;

typedef pair<ll,ll> pl;

typedef pair<int,int> pi;

typedef vector<pair<ll,ll>> vpl;

#define read(v) for(int i=0;i<(int)v.size();++i) cin>>v[i]

#define read1(v) for(int i=1;i<(int)v.size();++i) cin>>v[i]

#define print(v) {for(int i=0;i<(int)v.size();++i)cout<<v[i]<<" ";nl;}

#define print1(v) {for(int i=1;i<(int)v.size();++i)cout<<v[i]<<" ";nl;}

#define all(v) v.begin(),v.end()

#define allr(v) v.rbegin(),v.rend()

#define YES cout<<"YES"<<"\n"

#define NO cout<<"NO"<<"\n"

#define ANS cout<<ans<<"\n"

#define ub upper_bound

#define lb lower_bound

#define max_heap priority_queue<ll>

#define min_heap priority_queue<ll, vector<ll>, greater<ll>>

#define max_heap_pl priority_queue<pl>

#define min_heap_pl priority_queue<pl, vector<pl>, greater<pl>>

#define Unique(v) v.erase(unique(all(v)), v.end())

#define inf32 0x3f3f3f3f

#define inf64 0x3f3f3f3f3f3f3f3f

struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);

    }

 

    size_t operator()(uint64_t x) const {

        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + FIXED_RANDOM);

    }

};

#define umapll unordered_map<ll,ll,custom_hash>

//ll M= 1e9 + 7;

 

 

void solve();

int main() {

cin.tie(NULL);

cout.tie(NULL);

ios_base::sync_with_stdio(false);

 

 

int t=1;

cin>>t;

 

 

while(t--){

    solve();

}

return 0;

}

 

void solve(){

    ll n; cin>>n; 

    string s; cin>>s;

    ll ans = 0;

    vll v;

    loopf(i,0,n)if(s[i]=='0')v.pb(i);

    if(v.size())loopf(i,0,v.size()-1){

        if(v[i+1]-v[i]==1)ans+=2;

        else if(v[i+1]-v[i]==2)ans++;

    }

    ANS;

}