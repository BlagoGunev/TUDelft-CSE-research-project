#include <bits/stdc++.h>

#define ll long long

#define in(a, b) for (ll i = (a); i <= (b); i++)                // in using i

#define inj(a, b) for (ll j = (a); j <= (b); j++)               // in using j

#define ink(a, b) for (ll k = (a); k <= (b); k++)               // in using k

#define inr(a, b) for(ll i = (a); i >= (b); i--)                // in reverse

#define inrj(a, b) for(ll j = (a); j >= (b); j--)                // in reverse

#define inrk(a, b) for(ll k = (a); k >= (b); k--)                // in reverse

#define tt ll tcs; cin>>tcs; while(tcs--)                       // include test cases

#define ina(arr,n) ll arr[(n+1)]={0}; in(1,n) cin>>arr[i]       // input arr of n elements

#define inv(vec,n) vector<ll> vec(n+1); vec[0]=0; in(1,n) cin>>vec[i]; // input vector of n elements

#define pb push_back

#define lb lower_bound

#define ub upper_bound

#define pll pair <ll,ll>

#define sll set <ll>

#define vll vector<ll>

#define mll map <ll,ll>

#define endl "\n"

using namespace std;

const ll mod=1e9+7;

const ll INF=1e18;

const ll N=4e5;









// Useful Functions





//Permutaions and Combinations-









// // function to calculate ncr%p(set N to max n in ncr and mod to p)(initiate it):

// vll fac;

// void initiate_ncr(){

// fac.assign(N+1,1);

//     for (ll i=1;i<=N;i++)

//     {

//         fac[i] = fac[i-1]*i;

//         fac[i] %= mod;

//     }

// }

// // This is also a generalised mod inverse function:

// ll modInverse(ll a, ll m)

// {

//     ll m0 = m;

//     ll y = 0, x = 1;

//     if (m == 1)

//         return 0;

//     while (a > 1) {

//         ll q = a / m;

//         ll t = m;

//         m = a % m, a = t;

//         t = y;

//         y = x - q * y;

//         x = t;

//     }

//     if (x < 0)

//         x += m0;

//     return x;

// }

// ll ncr(ll n, ll r)

// {    

//     if(r<0) return 0;

//     if(n<r) return 0;

//     ll ans = fac[n]*modInverse(fac[r],mod);

//     ans %= mod;

//     ans *= modInverse(fac[n-r],mod);

//     ans %= mod;

//     return ans;

// }













// //pushes all primes till n in a vector

// void PrimeSieve(ll n,vll &prime){

//     ll CNT=0;

//     ll a[n+1];

//     in(1,n) a[i]=i;

//     in(2,n){

//         if(a[i]!=0){

//             CNT++;

//             prime.pb(i);

//             //cout<<i<<" ";

//             // cout<<i<<endl;

//             for(ll j=i;j<=n;j+=i){

//                 a[j]=0;

//             }

//         }

//     }

//     // cout<<CNT;

// }











// // returns a to power b mod m in log b time

// ll binexp(ll a, ll b,ll m) {

//     ll res = 1;

//     while (b > 0) {

//         if (b & 1)

//             res = (res * a)%m;

//         a = (a * a)%m;

//         b >>= 1;

//     }

//     return res;

// }







// // inserts lowest prime factor of i in a[i] till i=n in O(nlogn)

// void insertlp(vll &v,ll n){

//     v.assign(n+1,1);

//     in(2,n){

//         if(v[i]==1){

//             for(ll j=i;j<=n;j+=i){

//                 if(v[j]==1) v[j]=i;

//             }

//         }

//     }

// }















// // converts integer i to binary string of 'bits' bits

// string toBinary(ll i, ll bits)

// {

//     string s = "";

//     while (i > 0)

//     {

//         if (i%2)

//         {

//             s += '1';

//         }

//         else

//             s += '0';

//         i/=2;

//     }

//     // cout<<s.length()<<' '<<bits<<'\n';

//     while (s.length() < bits)

//         s += '0';

//     reverse(s.begin(),s.end());

//     return s;

// }

// // ll __lcm(ll a, ll b){

// //     return ((a/__gcd(a,b))*b);

// // }















// // converts binary string to decimal number

// ll toDecimal(string &n)

// {

//     ll s=n.length();

//     ll dec_value = 0;

 

//     // Initializing base value to 1, i.e 2^0

//     ll base = 1;

 

//     inr(s-1,0) if(n[i]=='1') dec_value+=pow(2,s-1-i); 

//     return dec_value;

// }











// // LIS in nlogn(pushes LIS in a vector, for LNDS, put >= in s=m+1 line):

// vll LIS(vll &v){

//     ll n=v.size()-1;

//     vll parent(n+1);

//     vector<pair<ll,ll>> best(n+1,{INF,-1});

//     best[0]={-INF,-2};

//     vll lis;

//     in(1,n){

//         ll s=0;

//         ll e=n;

//         while(e>s){

//             ll m=(s+e)/2;

//             if(v[i]>best[m].first) s=m+1;

//             else e=m;

//         }

//         best[s]={v[i],i};

//         parent[i]=best[s-1].second;

//         }

//         ll li;

//         inr(n,1){

//             if(best[i].first!=INF){

//                 li=best[i].second;

//                 break;

//             }

//         }

//         while(li>0){

//             lis.pb(v[li]);

//             li=parent[li];

//         }

//         ll sz=lis.size();

//         in(0,sz/2-1) swap(lis[i],lis[sz-i-1]);

//         return lis;

// }





// //sorting by increasing values of x^3+17x

// sort(vec.begin(), vec.end(), [](int a, int b){

//     return a*a*a+17*a < b*b*b+17*b;

// });











//Trees and Graphs-









// //LCA algo (set N, number of nodes numbered from 1 to N)(initiate dfs(root,root)):

// ll L=ceil(log2(N));

// vll tin(N+1),tout(N+1);

// ll timer=0;

// vector <vll> up(N+1,vll(L+1,1));

// vector<vll> adj(N+1);



// void initiate_LCA(ll v,ll p){

//     tin[v]=++timer;

//     up[v][0]=p;

//     in(1,L){

//         up[v][i]=up[up[v][i-1]][i-1];

//     }

//     for(auto it:adj[v]){

//         if(it!=p) initiate_LCA(it,v);

//     }

//     tout[v]=++timer;

// }

// bool IsAncestorOf(ll a, ll b){

//     return (tin[a]<=tin[b]&&tout[a]>=tout[b]);

// }

// ll LCA(ll a,ll b){

//     if(IsAncestorOf(a,b)) return a;

//     if(IsAncestorOf(b,a)) return b;

//     inr(L,0){

//         if(!IsAncestorOf(up[a][i],b)) a=up[a][i];

//     }

//     return up[a][0];

// }











// //Function to push distance of all nodes from root into dist(set N, number of nodes numbered from 1 to N)

// vll dist(N+1,0);

// void setDist(ll v, ll p){

//         for(auto it: adj[v]){

//             if(it!=p) {dist[it]=dist[v]+1;

//                 setDist(it,v);

//             }

//         }

//         return;

//     }





// void dfs(vll &vis, ll a, vector <vll> &adj){

//     vis[a]=1;

//     for(auto it:adj[a]) if(vis[it]==0) dfs(vis,it,adj);

//         return;

// }









// // DSU;

// vll dsu_parent;

// vll dsu_size;

// void initiate_dsu(ll n){

//     dsu_parent.resize(n+1);

//     in(1,n) dsu_parent[i]=i;

//     dsu_size.assign(n+1,1);

// }

// ll find_set(ll v) {

//     if (v == dsu_parent[v])

//         return v;

//     return dsu_parent[v] = find_set(dsu_parent[v]);

// }

// void make_set(ll v) {

//     dsu_parent[v] = v;

//     dsu_size[v] = 1;

// }



// void union_sets(ll a, ll b) {

//     a = find_set(a);

//     b = find_set(b);

//     if (a != b) {

//         if (dsu_size[a] < dsu_size[b])

//             swap(a, b);

//         dsu_parent[b] = a;

//         dsu_size[a] += dsu_size[b];

//     }

// }















int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    cout<<setprecision(30);



    















    tt{

        ll n;

        cin>>n;

        inv(a,n);

        //vll b=a;

        vll u(n+1,0);

        ll our=0;

        while(1){

            ll mx=0;

            ll mxi;

            in(1,n){

                if(((a[i])&(~our))>=mx){

                    mx=a[i]&(~our);

                    mxi=i;

                }

            }

            if(mx==0) break;

            u[mxi]=1;

            cout<<a[mxi]<<" ";

            our=our|mx;

        }

        in(1,n) if(u[i]==0) cout<<a[i]<<" ";

        cout<<endl;

    }

    





















    

    return 0;

}

// divide me zero check kar lena pls :)

// non-existent element ko access bhi mat karna, pagal h kya.

// interactive problem me endl ka define dekh lena ek baar

// functions me har baar pass by reference kara kar to save time

// a.size() ya a.length() is unsigned int, 0 nahi ho payega, neg bhi nahi

// log2l and sqrtl use karna

// ***(typo) '==' and '=' dekh lena