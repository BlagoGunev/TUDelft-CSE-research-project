#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
 os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";}
// #define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){ cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);}
#else
#define trace(...) 1
#endif

// -------------------------------------------------------------

#define ll long long
#define ld long double
#define F first
#define S second
#define pll pair<ll,ll>
#define umll unordered_map<ll,ll>
#define pb push_back
#define vll vector<ll>
#define endl '\n'
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }

ll pow(ll a,ll b){
    ll c = 1; while(b>0){ if(b%2) c*=a; b/=2; a*=a; } return c;
}

const ll Mod = 1e9 + 7;
const ll N = 1e5+10;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout<<setprecision(25);
    ll t,x,y,k,n,a,b;
    cin>>n;
    string str;
    while(n--){
        cin>>a;
        cin>>str;
        if(a==2 && str[0]>=str[1]) {cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;
        cout<<2<<endl;
        cout<<str[0]<<" "<<str.substr(1,a-1)<<endl;
    }
    
       
}