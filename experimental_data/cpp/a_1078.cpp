#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#ifdef OFFLINE
    #define DEBUG 1
#else
    #define DEBUG 0
#endif
#define debug(a) if(DEBUG) cout<<#a<<" = "<<a<<endl
#define x first
#define y second
template<typename T>ostream&operator<<(ostream&os,vector<T>a){os<<"( ";for(T &x:a)os<<x<<" ";os<<")\n";return os;}
template<typename T>ostream&operator<<(ostream&os,set<T>a){os<<"( ";for(T x:a)os<<x<<" ";os<<")\n";return os;}
template<typename X,typename Y>ostream&operator<<(ostream&os,pair<X,Y>a){os<<"("<<a.first<<" "<<a.second<<") ";return os;}
template<typename T>ostream&operator<<(ostream&os,complex<T>a){os<<"(r="<<a.real()<<" i="<<a.imag()<<") ";return os;}
template<typename X,typename Y>pair<X,Y>&operator-=(pair<X,Y>&A,pair<X,Y>B){A.x-=B.x;A.y-=B.y;return A;}
template<typename X,typename Y>pair<X,Y>&operator+=(pair<X,Y>&A,pair<X,Y>B){A.x+=B.x;A.y+=B.y;return A;}
template<typename X,typename Y,typename Z>pair<X,Y>&operator*=(pair<X,Y>&A,Z n){A.x*=n;A.y*=n;return A;}
template<typename X,typename Y>Y operator*(pair<X,Y>A,pair<X,Y>B){return A.x*B.x+A.y*B.y;}
template<typename X,typename Y>Y operator^(pair<X,Y>A,pair<X,Y>B){return A.x*B.y-A.y*B.x;}
template<typename X,typename Y>X operator^(X a,Y b){return a^=b;}
template<typename X,typename Y>X operator+(X a,Y b){return a+=b;}template<typename X,typename Y>X operator-(X a,Y b){return a-=b;}
template<typename X,typename Y>X operator*(X a,Y b){return a*=b;}template<typename X,typename Y>X operator/(X a,Y b){return a/=b;}
typedef long long ll;typedef long double dd;typedef pair<dd,dd>pii;typedef vector<int>vi;typedef vector<pii>vii;typedef vector<vi>vvi;
const int base=1000000007;
ll power(ll a,ll n,ll mod=base){a=a<0?(mod-(-a)%mod):(a%mod);ll r=1;while(n){if(n&1)r=r*a%mod;a=a*a%mod;n>>=1;}return r;}
//================================================================Head=========================================================================//
const dd eps = 1e-11;

int main(int argc,char** argv){
    if (argc>2){
        freopen(argv[1],"r",stdin);
        freopen(argv[2],"w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    dd a,b,c;
    pii A,B;
    cin>>a>>b>>c>>A.x>>A.y>>B.x>>B.y;
    if (abs(a)<eps || abs(b)<eps){
        cout<<fixed<<setprecision(9)<<abs(A.x-B.x)+abs(A.y-B.y);
        return 0;
    }
    vii C, D;
    for(int t=2;t--;){
        swap(C,D);
        swap(A,B);
        dd x = A.x, y = (-c-a*x)/b;
        C.push_back({x,y});
        y = A.y, x = (-c-b*y)/a;
        C.push_back({x,y});
    }
    dd ans = abs(A.x-B.x)+abs(A.y-B.y);
    for(auto X:C) for (auto Y:D){
        dd l = sqrtl((X-Y)*(X-Y));
        l += sqrtl((A-X)*(A-X));
        l += sqrtl((B-Y)*(B-Y));
        ans = min(ans,l);
    }
    cout<<fixed<<setprecision(9)<<ans;
}