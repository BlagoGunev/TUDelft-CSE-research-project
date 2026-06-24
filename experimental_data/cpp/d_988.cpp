//By Tushar Gautam
#include <bits/stdc++.h>
using namespace std;
#define printint(v) copy(begin(v), end(v), ostream_iterator<int>(cout," "))
#define printintv(s,e) copy(s,e, ostream_iterator<int>(cout," "))
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits (for ints only diff for ll)
//https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html for other in built
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> p32; 
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
#pragma GCC optimize ("-O2")
const int LIM = 2e5+10, MOD = 1e9+7;
ll t,n,y;
ll a[LIM];
int x,z,curr,aa;
p32 ans;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n;
    forn(i,n) cin>>a[i];
    sort(a,a+n);
    x=0;
    bool b=1;
    forn(i,32){
        if(x==3) break;
        t= (1LL<<i); // cout<<t<<ln;
        forn(j,n){
            y=a[j];
            curr=1;
            z=lower_bound(a+j,a+n,y+t)-a; //dbg(z);
            while(z!=n){
                if(a[z]!=y+t) break;
                curr++;y+=t;
                z=lower_bound(a+z,a+n,y+t)-a;
                if(curr==3) break;
            }
          //  dbg(i);dbg(j);dbg(curr);
            x=max(x,curr);
            if(x==curr){
                ans=mp(i,j); //cout<<i<<" "<<j<<ln;
            }
            if(x==3) break;
        }
    }
    cout<<x<<ln;
    t=(1LL<<ans.fi);
    z=ans.se;y=a[z];
    aa=0;
    while(z!=n){
        if(aa==x) break;
       // dbg(z);
        if(a[z]!=y) break;
        cout<<y<<" ";
        y+=t;
        z=lower_bound(a,a+n,y)-a;
        aa++;
    }
    return 0;
}