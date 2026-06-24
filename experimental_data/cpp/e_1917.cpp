/*input
5
4 0
18 162
6 5
2 2
6 36

*/
 
 
#include <bits/stdc++.h>
#define ll long long int
#define vi vector< ll >
#define pi pair< ll, ll > 
#define mset(A,v,n) memset((A),(v),(n)*sizeof((A)[0]) ) 
#define FORi(n) for(ll i=0;i<(n);i++)
#define FORj(n) for(ll j=0;j<(n);j++)
#define FORk(n) for(ll k=0;k<(n);k++)
#define pb push_back
#define inp(A) FORi( (A).size() )cin>>((A)[i]);
#define inp2(n,m) scanf("%⁄lld%lld",&(n),&(m));
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define mp(a,b) make_pair((a),(b))
#define INT_SIZE 60
 
 
#define MAXN  100010
#define mod 1000000007    
#define level  22
using namespace std;
 
#define n_l '\n'
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); }  template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); } 
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
 
void print(vi v){FORi(v.size())cout<<v[i]<<" ";cout<<endl;}
void print(deque<int> v){FORi(v.size())cout<<v[i]<<" ";cout<<endl;}
void print(vi v,int n){FORi(n)cout<<v[i]<<" ";cout<<endl;}
ll pm(ll x,ll y){ll res = 1;while(y>0){if(y&1) res = (res*x)%mod;x= (x*x)%mod;y/=2;}return res;}
ll gcd(ll a, ll b){if(b==0)return a;if(a==0) return b; return gcd(b,a%b);}
 



 
void solve(){
    
    ll n,d,k;
    cin>>n>>k;

    ll M[n][n];

    if(n == 2 && k == 2){
        cout<<"Yes\n1 0\n0 1\n";
        return;
    }
    
    FORi(n)FORj(n)M[i][j] = 0;

    ll inv = 0;
    if(k > n*n/2){
        inv = 1;
        k = n*n - k;
    }

    if(k&1){
        cout<<"No\n";
        return;
    }

    if(k%4 == 2){

        if(k == 2 || n < 3){
            cout<<"No\n";
            return;
        }

        M[n-1][n-3] = 1;
        M[n-1][n-2] = 1;
        M[n-2][n-3] = 1;
        M[n-2][n-1] = 1;
        M[n-3][n-1] = 1;
        M[n-3][n-2] = 1;

        k -= 6;
    }


    for(int j = 0;j<n-2;j+=2){
        if(k == 0)break;
        for(int i = 0;i<n;i+=2){
            if(k == 0 )break;

            M[i][j] = 1;
            M[i+1][j] = 1;
            M[i][j+1] = 1;
            M[i+1][j+1] = 1;

            k -= 4;
        }
    }

    cout<<"Yes\n";
    FORi(n){
        FORj(n){
            cout<< (M[i][j]^inv )<<" ";
        }
        cout<<"\n";
    }

 
    
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // pre();
 
    int t;cin>>t;FORi(t)
        solve();
    return 0;
 
}