#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

#define F first

#define S second

#define endl "\n"

#define Endl "\n"

#define fbo find_by_order

#define ook order_of_key

#define ll long long

#define ld long double

#define vl vector<long long>

#define pll pair<long long,long long>

#define sl set<long long>

#define uset unordered_set

#define umap unordered_map

#define prq priority_queue

#define pqll priority_queue<ll> 

#define pb push_back

#define ppb pop_back

#define mp make_pair

#define bpc(x) __builtin_popcount(x)

#define sz(v) (int)(v.size())

#define all(v) (v).begin(),(v).end() 

#define mem(a, val) memset(a, val, sizeof(a))

#define mem0(a) memset(a,0,sizeof(a))

#define mem1(a) memset(a,-1,sizeof(a))

#define N 100000

#define N2 200000

 

const long double EPS = 0.0001;

const long double PI = 3.141592653589793238;

const long long hell = 1000000007;

const long long mod = 998244353;

const long long INF = 1e16;

using namespace std;

using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

mt19937 rng ((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

 

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }

template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

ll power(ll x, ll y, ll p=mod) 

{ 

    ll res = 1;  

    x = x % p;  

    while (y > 0) 

    { 

        if (y & 1) 

            res = (res*x) % p; 

        y = y>>1; // y = y/2 

        x = (x*x) % p; 

    } 

    return res; 

} 

  

// Returns n^(-1) mod p 

ll modInverse(ll n, ll p=mod) 

{ 

    return power(n, p-2, p); 

} 

  

// Returns nCr % p using Fermat's little theorem. 

ll fac[N+1]; 

void pre(ll p=mod){

    fac[0] = 1; 

    for (ll i=1 ; i<=N; i++) 

        fac[i] = (fac[i-1]*i)%p; 

}

ll nCrModPFermat(ll n, ll r, ll p=mod) 

{ 

   if (r==0) 

      return 1; 

    if(r>n)

      return 0;

    return (fac[n]* modInverse(fac[r], p) % p * modInverse(fac[n-r], p) % p) % p; 

}

int main(){

   

    ios_base::sync_with_stdio(0);

    cin.tie(NULL);

    cout.tie(NULL);

    #ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin);

        freopen("error.txt", "w", stdout);

    #endif

   

    ll t,n,m,i,j;

    t=1;

    cin>>t;

    while(t--){

        string s;

        cin>>n>>m>>s;

        ll cnt[m];

        mem0(cnt);

        ll last=-1;

        ll ans[n*m];

        ll c=0;

        for(i=0;i<m;i++){

            if(s[i]=='1'){

                cnt[i]++;

                c++;

                last=i;

            }

            ans[i]=(c!=0);

            cout<<ans[i]+c<<" ";

        }



        for(i=m;i<n*m;i++){

            if(s[i]=='1'){

                if(cnt[i%m]==0){

                    cnt[i%m]++;

                    c++;     

                }

                last=i;

                if(i-m<last){

                   ans[i]=1+ans[i-m];

                }

                else ans[i]=ans[i-m];

            }

            else{

                if(i-m<last){

                   ans[i]=1+ans[i-m];

                }

                else ans[i]=ans[i-m];

            }

            // cout<<ans[i]<<" "<<c<<endl;

            cout<<ans[i]+c<<" ";

        }

        cout<<endl;

    }

}