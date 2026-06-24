//   // //    // //         //
//   // //   //  ////     ////
//   // //  //   //  // //  //
/////// /////    //   //    //
//   // //  //   //         //
//   // //   //  //         //
//   // //    // //         //

#include <bits/stdc++.h>
using namespace std;
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define iter(it,a,b) for(a::iterator it=b.begin(); it!=b.end();++it)
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits (binary me 1 kitne hai) (if longlong popcount ll)
#define ln "\n"
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it<<ln;} cerr<<endl
#define dbgstlp32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cerr<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(n) n.begin() , n.end()
#define tfi first.first
#define tse first.second
#define tth second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
typedef pair< pair<int,int> , int> tri;
typedef vector<bool> vbool;
typedef priority_queue<p32> pq32;
typedef priority_queue<p32, vector<p32>, greater<p32> > pq32l;

#pragma GCC optimize ("-O2")
const ll LIM = 2e5+5;
const ll MOD = 1e9+7;
const ll inf = 1e10;



int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t, n;
    cin>>t;
    while(t--){
        ll x, sum=2;
        cin>>n;

        while(true){
            sum = sum*2;
            if(n%(sum-1) == 0){
                x=n/(sum-1);
                break;
            }
        }
        cout<<x<<ln;
    }


}