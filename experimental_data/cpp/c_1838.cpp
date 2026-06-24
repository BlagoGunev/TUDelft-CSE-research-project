#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize ("Ofast,unroll-loops")
// #pragma GCC target ("avx2")
#define rep(i,l,r) for(int i = (l); i < (r); i++)
#define per(i,r,l) for(int i = (r); i >= (l); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)size(x)
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pp;

void dbg(){
     cerr << endl;
}
template<typename H, typename... T> void dbg(H h, T... t){
     cerr << h << ", ";
     dbg(t...);
}

void IOS(){
     cin.tie(0) -> sync_with_stdio(0);
     #ifndef ONLINE_JUDGE
          freopen("inp.txt", "r", stdin);
          freopen("out.txt", "w", stdout);
          #define er(...) cerr << __LINE__ << " <" << #__VA_ARGS__ << ">: ", dbg(__VA_ARGS__)
     #else
          #define er(...) 0
     #endif
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = 1e9 + 7, maxn = 5e5 + 5, lg = 19, inf = ll(1e9) + 5;

void slv(){
     int n, m; cin >> n >> m;
     if(n == 4){
          rep(i,0,n){
               rep(j,0,m){
                    cout << j*4 + i + 1 << ' ';
               }
               cout << '\n';
          }
     }else{
          for(int i = 1; i <= n; i += 2){
               rep(j,0,m){
                    cout << i*m - m + j + 1 << ' ';
               }
               cout << '\n';
          }
          for(int i = 2; i <= n; i += 2){
               rep(j,0,m){
                    cout << i*m - m + j + 1 << ' ';
               }
               cout << '\n';
          }
     }
}

int main(){ IOS();
     int t = 1;
     cin >> t;
     while(t--) slv();
     return 0;
}