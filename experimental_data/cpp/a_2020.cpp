/*

              ██████████
            ██░░░░░░░░░░████
          ██░░░░░░░░░░░░░░░░██
        ██░░░░░░░░░░░░░░░░░░░░██
      ██░░░░░░██░░░░░░░░░░░░████
    ██░░░░░░░░██░░████████░░██░░██
    ██░░░░░░░░░░░░██░░░░░░██░░░░██
  ████░░░░░░░░░░░░██░░░░░░██░░░░░░██
  ██░░░░░░░░░░░░░░██░░░░░░██░░░░░░░░██
██░░░░░░░░░░░░░░░░██░░░░████░░░░░░░░██
██░░░░░░░░░░░░░░░░░░██░░██░░░░░░░░░░██
██░░░░░░░░░░░░░░░░░░██░░██░░░░░░░░░░██
  ██░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░██
    ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
    ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████
    ████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
    ██░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
    ██░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
    ████████████████████████████████████████████████


    ░░      ░░      ░░      ░░                      ░░      ░░
 */
//shiremono ga
//omae wa tsumaran na
#define _GLIBCXX_DEBUG
//#pragma GCC optimize("O3,unroll-loops")//,"inline","-ffast-math")
//#pragma GCC target("arch=icelake-server")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4")
//#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
//#pragma GCC optimize("avx,avx2,ssse3,tune-native")
//#pragma GCC optimize("-funsafe-loop-optimizations")
//#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
//#include "atcoder"
#define x first
#define fi first
#define y second
#define se second
#define int long long
//#define double long double
#define sqrt sqrtl
#define __builtin_popcount __builtin_popcountll
//#define M_PI (double)3.14159265358979323846
#define fast ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);
#define endl '\n'
#define N (int)(1e6+10)
#define mod (int)(1e9+7)
//#define mod (int)(1000003651)
//#define mod (int)(998244353)
//#define mod (int)(167772161)
using namespace std;
//using namespace atcoder;
using namespace __gnu_pbds;
vector<pair<int,int>>mo={{1,0},{-1,0},{0,1},{0,-1}};
vector<pair<int,int>>mo2={{1,1},{-1,1},{-1,-1},{1,-1}};
vector<pair<int,int>>mok={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
vector<pair<int,int>>moK={{1,1},{-1,1},{1,-1},{-1,-1},{1,0},{0,1},{-1,0},{0,-1}};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
int bp(int a,int b,int m) {
    if (b == 0) {
        return 1;
    }
    if (b & 1) {
        return (a * bp(a, b - 1,m)) % m;
    }
    int q = bp(a, b >> 1,m);
    return (q * q) % m;
}
int su(int l,int r){
    return ((r-l+1)*(r+l)/2);
}
int sum(int l,int r){
    return ((((r-l+1+mod)%mod)*(l+r)%mod)*bp(2,mod-2,mod))%mod;
}
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.y!=b.y)return a.y>b.y;
    return a.x>b.x;
}
vector<int>g[N];
void Bogdan(){
    int n,k;
    cin>>n>>k;
    int re=0;
    if(k==1){
        cout<<n<<endl;
        return;
    }
    while(n){
        re+=n%k;
        n/=k;
    }
    cout<<re<<endl;
}
int32_t main(){
    fast;
    int t=1,n,k;
//  freopen("t1.txt","r",stdin);
    //   freopen("t1.out","w",stdout);
    //init();
    cin>>t;
    //primes();
    while(t--){
        Bogdan();
    }
}