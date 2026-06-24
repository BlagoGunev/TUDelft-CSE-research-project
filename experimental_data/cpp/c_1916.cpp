/**
* @Author:your.nemesis
**/
 
#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <climits>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <sstream>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
//using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
 
#define mod 1000000007
#define inf 1e9
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"
#define all(arr) arr.begin(),arr.end()
 
 
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//options: less,greater_equal,less_equal,greater
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
 
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
const int N=3e5+5;
const long long infll = 0x3f3f3f3f3f3f3f3fLL;
int p[N];
 
ll modulo(ll a, ll b, ll n){
    ll x=1, y=a;
    while (b > 0) {
        if (b%2 == 1) {
            x = ((x%n) * (y%n)) % n; // multiplying with base
           
        }
        y = ((y%n) * (y%n)) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}
 
ll modmod(ll a,ll b,ll c){
    // Fermats Little Theorem
    // A^(M-1) = 1 (mod M) if M is a prime.
    // So write B^C as x*(M-1) + y
   
    ll y = modulo(b,c,mod-1);
 
    return modulo(a,y,mod);
}
 
ll value[1000001];
void fillNumberOfDivisorsArray(){
    for(ll i=1;i<=1000000;i++){
        for(ll j=1;i*j<=1000000;j++){
            value[i*j]++;
        }
    }
}
 
vector<ll> prime;
bool is_composite[N];
 
void sieve(ll n) {
 
    fill(is_composite,is_composite + n,false);
 
    for (ll i=2;i<n;i++){
 
        if(!is_composite[i]){
            prime.push_back(i);
        }
 
        for (int j=2;i*j < n;j++){
            is_composite[i * j] = true;
        }
    }
}
 
void addEdge(vector<ll> adj[],ll u,ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}
 
ll __lcm(ll a,ll b){
    return a*b/(__gcd(a,b));
}
 
vector<ll> fact;
void factorialFill(){
    fact.pb(1);
    fact.pb(1);
    for(ll i=2;i<=1000000;i++){
        fact.pb((i%mod * fact.back()%mod)%mod);
    }
}
ll getfact(ll num){
    return fact[num]%mod;
}
 
ll getBits(ll num){
    return log2(num) + 1;
}
 
 
struct cmp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.first < b.first;
    }
};
vector<int> topoSort(int N, vector<int> adj[]){ // topological sort  // N = number of vertices in graph // adj = adjacency list
    queue<int> q; //  queue of vertices with no incoming edges
    vector<int> inDegree(N,0); // inDegree[i] = number of incoming edges to vertex i
    for(int i=0;i<N;i++){
        for(auto it:adj[i]){ // for each edge (i,j) in graph // it = j in this case
            inDegree[it]++; // inDegree[i] = # of edges that point to i
        }
    }
    for(int i=0;i<N;i++){
        if(inDegree[i]==0){ // if there is no edge pointing to i
            q.push(i);
        }
    }
    vector<int> topo; 
    while(!q.empty()){ // while there is still a node with no incoming edges
        int curr = q.front(); 
        q.pop(); // remove the node from the queue
        topo.push_back(curr); // add the node to the topo vector
        for(auto it:adj[curr]){ // for each node that points to curr
            inDegree[it]--; // decrement the inDegree of that node
            if(inDegree[it]==0){ // if the inDegree of that node is 0
                q.push(it); // add it to the queue
            }
        }
    }
    return topo; // return the topo vector
}
int s(int num , int target){
  int n = target/num;
  
  return num*(n*(n+1))/2;
}
vector<ll>v;
 
void solve(ll tc){
ll n ;
cin>>n;
vector<ll>v(n);
for(int i =0;i<n;i++){
          
          cin>>v[i];
        
}

ll sum=0,odd=0,even;
for(int i =0;i<n;i++){
          
          sum+=v[i];
          if(v[i]%2){
              odd++;
          }
          else even++;
          
          if(i==0)cout<<sum<<" ";
          else if(i==1)cout<<((sum/2)*2)<<" ";
          
          else {
              if(odd){
                  ll m= odd/3;
                  
                  if(odd%3==1)m++;
                  ll out=sum-m;
                  
                  
                  cout<<out<<" ";
                  
              }
              
              else cout<<((sum/2)*2)<<" ";
              
          }
          
        
}
cout<<endl;


}
 
int main() {
 
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
 
    ll tt;
    cin>>tt;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }
 
    return 0;
}