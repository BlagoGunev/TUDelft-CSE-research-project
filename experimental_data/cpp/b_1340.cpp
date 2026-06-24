#include<bits/stdc++.h>

#include<chrono>

#include<random>

#include<assert.h>

#include<stdexcept>

#include<iostream>

#include<cmath>

#include<algorithm>

#include<bitset>

#include<iomanip>

#include<map>

#include<vector>

#define num1bit(x) __builtin_popcount(x)

#define bol __int8

#define C continue

#define B break

#define R return

#define ll long long int

#define ld long double

#define ull unsigned long long

#define nd second

#define st first

#define bn begin()

#define ed end()

#define wte long Tests ; cin >> Tests ; while(Tests--)

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define b(myint,z) bitset<64>z(myint) ; cout<<z<<endl ;

#define endl '\n'

#define pb push_back

#define SPR(a) cout<<fixed<<setprecision(a) 

using namespace std;

const int oo=(int)1e9+7;

const ld eps=1e-8 ;

const ld PI=3.14159265359 ;

const ll lloo=(ll)1e18;

ll Pow(ll a,ll b,ll mod=oo){

    ll res=1;if(b<0||b>=mod)b=(b%(mod-1)+mod-1)%(mod-1);

    for(;b;b>>=1,a=1ll*a*a%mod)

        if(b&1)res=1ll*res*a%mod;

    return res;

}

ld ldPow(ld a,ll b){

    ld res=1;

    for(;b;b>>=1,a=1.0*a*a)

        if(b&1)res=1.0*res*a;

    return res;

}

ll inverseMod(ll A,ll bB,ll mod=oo){

    ll ans=Pow(bB,mod-2,mod);

    ans%=mod;

    ans*=A;

    ans%=mod;

    return ans;

}

ll segma(ll x,ll y,ll mod=oo){

    ll res=x+y;

    res*=(max(x,y)-min(y,x)+1);

    R res/2;

}

ll mid(ll l,ll r){

    R (r-l)/2 +l;

}

const int mod=998244353  ;

ll fac(ll a,ll mod){

    if(a==0) R 1 ;

    R (a*(fac(a-1,mod)%mod))%mod ;

}

ll LCM(ll x,ll y){

    R (x*y)/(ll)__gcd(x,y);

}

template<typename t>

t intlog2(t x){

    t res=0 ;

    while(x>0){

        res++ ;

        x/=2;

    }

    R res;

}

bool sec(pair<ll,ll> a,pair<ll,ll> b){

    R a.st-a.nd>b.st-b.nd;

}

struct point {

    ld x{}, y{};

    point() = default;

    point(ld _x, ld _y) : x(_x), y(_y) {}

    point operator+(const point &p) const { return point(x + p.x, y + p.y); }

    point operator-(const point &p) const { return point(x - p.x, y - p.y); }

    ld cross(const point &p) const { return x * p.y - y * p.x; }

    ld dot(const point &p) const { return x * p.x + y * p.y; }

    ld cross(const point &a, const point &b) const { return (a - *this).cross(b - *this); }

    ld dot(const point &a, const point &b) const { return (a - *this).dot(b - *this); }

    ld sqrLen() const { return this->dot(*this); }

    void In(){

        cin>>x>>y;

    }

    void Out() const{

        cout<<fixed<<setprecision(7)<<x<<" "<<y<<endl;

    }

};

ld L(point a,point b){

    R (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ;

}

ll ccw(point a,point b,point c){

    R (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x) ;

} 

//#define MPF

#ifdef MPF

const int N=300300,M=5050,NN=10001005;

int MinPrime[NN];

int Mprime[NN];

vector<int> Prime;

void init(){

    MinPrime[1]=1;

    for(int i=2;i<NN;i++){

        if(MinPrime[i])C;

        Prime.pb(i);

        for(int j=i;j<NN;j+=i){

            if(MinPrime[j])C;

            MinPrime[j]=i;

        }

    }

}

#endif

// int n,m,k,c ;

// int cnt[3] ;

// vector<int> v1,v2 ;

// int pre[200000][3] ,suf[200000][3];

// int main(){

//     wte{

//         cin >>n ;

//         cnt[1]=cnt[2]=0;

//         for(int i=1;i<=n;i++) {

//             cin >>v1[i] ;

//             cnt[v1[i]]++;

//         }

//         for(int i=1;i<=n;i++) {

//             cin >>v2[i] ;

//             cnt[v2[i]]++;

//         }

//         reverse(v1.bn,v1.ed) ;

//         for(int i=1;i<=n;i++){

//             pre[i][1]=pre[i][1]+v1[i]==1 ;

//             pre[i][2]=pre[i][2]+v1[i]==2 ;

//             suf[i][1]=suf[i][1]+v2[i]==1 ;

//             suf[i][2]=suf[i][2]+v2[i]==2 ;

//         }

        

//         cout<<ans<<endl ;

//     }

//     R 0;

// }

vector<string> b={ "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"} ;

int n,k ;

string s[2222] ;

int df(int n,string s){

    int re=0;

    for(int i=0;i<7;i++){

        if(s[i]-b[n][i]==1) R oo;

        re+=b[n][i]-s[i];

    }

    R re ;

}

int dp[2222][2222] ;

int co[2222][10] ;

int main(){

    cin >>n>>k ;

    for(int i=1;i<=n;i++) cin >>s[i] ;

    for(int i=1;i<=n;i++){

        for(int j=0;j<=9;j++){

            co[i][j]=df(j,s[i]) ;

            //cout<<i<<' '<<co[i][j]<<endl;

        }

    }

    dp[n+1][0]=1;

    //for(int i=0;i<=9;i++) dp[n][i]=(co[n][i]<oo) ;

    for(int i=n+1;i>0;i--){

        for(int j=0;j<=k;j++){

            if(dp[i][j]){

                for(int l=0;l<=9;l++){

                    if(co[i-1][l]>=oo) C ;

                    if(j+co[i-1][l]<=k) dp[i-1][j+co[i-1][l]]=1;

                }

            }

        }

    }

    //

    if(dp[1][k]==0) {

        cout<<-1;

        R 0;

    }

    for(int i=1;i<=n;i++){

        for(int l=9;l>=0;l--){

            if(co[i][l]>=oo) C ;

            if(k>=co[i][l] && dp[i+1][k-co[i][l]]){

                cout<<l;

                k-=co[i][l];

                B;

            }

        }

    }

    R 0;

}