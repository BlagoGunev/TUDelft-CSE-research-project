#pragma GCC optimize(3,"Ofast","inline")

#include <set>

#include <map>

#include <list>

#include <queue>

#include <cmath>

#include <ctime>

#include <string>

#include <cstdio>

#include <random>

#include <vector>

#include <memory>

#include <cstdlib>

#include <cstring>

#include <numeric>

#include <sstream>

#include <cxxabi.h>

#include <assert.h>

#include <iostream>

#include <algorithm>

#include <bits/stdc++.h>

#include <tr1/unordered_map>

#include <tr1/unordered_set>

//#include <ext/pb_ds/trie_policy.hpp>

//#include <ext/pb_ds/assoc_container.hpp>

//#define ll int

#define ft first

#define sd second

//#define endl '\n'

#define pb push_back

#define ll long long

#define ld long double

#define pll pair<ll,ll>

#define no cout<<"NO"<<endl

#define _no cout<<"no"<<endl

#define lowbit(a) ((a)&-(a))

#define yes cout<<"YES"<<endl

#define _yes cout<<"yes"<<endl

#define ull unsigned long long

#define all(x) x.begin(),x.end()

#define nps fixed<<setprecision(10)<<

#define mem(a,k) memset(a,k,sizeof(a))

#define debug(x) cerr<<#x<<"="<<x<<endl

#define rep(i,a,b) for(ll i=(a);i<=(b);i++)

#define per(i,a,b) for(ll i=(a);i>=(b);i--)

#define DEBUG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

#define testmode freopen("C:\\Users\\pc\\Desktop\\test.in","r",stdin)

#define RBT tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

const ll N=1e6+5;

const ll mod1=1e9+7;

const ll mod2=998244353;

const ll base1=1610612741;

const ll INF=0x3f3f3f3f3f;

const ll inf=9223372036854775807;

const ld lne=2.71828182845904523536028747;

const double T0=1e5;

const double D=1-3e-3;

const double eps=1e-9;

const double T_end=1e-4;

const double PI=3.1415926535897932384626;

const double Wythoff=(1.0+sqrt(5.0))/2.0;

const ll Z=mod1;

const ll mod=Z;

using namespace std;

//using namespace __gnu_pbds;

int ddir[2][2]={{0,1},{1,0}};

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int dir3[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};

int dii[8][2]={{1,2},{-1,2},{2,1},{-2,1},{-1,-2},{1,-2},{-2,-1},{2,-1}};

struct mint

{

    ll x;

    mint(ll y = 0){if(y < 0 || y >= mod) y = (y%mod+mod)%mod; x = y;}

    mint(const mint &ope) {x = ope.x;}

    mint operator-(){return mint(-x);}

    mint operator+(const mint &ope){return mint(x) += ope;}

    mint operator-(const mint &ope){return mint(x) -= ope;}

    mint operator*(const mint &ope){return mint(x) *= ope;}

    mint operator/(const mint &ope){return mint(x) /= ope;}

    mint& operator+=(const mint &ope){x += ope.x; if(x >= mod) x -= mod; return *this;}

    mint& operator-=(const mint &ope){x += mod - ope.x; if(x >= mod) x -= mod; return *this;}

    mint& operator*=(const mint &ope){ll tmp = x; tmp *= ope.x, tmp %= mod; x = tmp; return *this;}

    mint& operator/=(const mint &ope){ll n = mod-2; mint mul = ope;while(n){if(n & 1) *this *= mul; mul *= mul; n >>= 1;}return *this;}

    mint inverse(){return mint(1) / *this;}

    bool operator ==(const mint &ope){return x == ope.x;}

    bool operator !=(const mint &ope){return x != ope.x;}

    bool operator <(const mint &ope)const{return x < ope.x;}

};

//mt19937_64 rng(random_device{}());

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll gcd(ll a,ll b){return __gcd(a,b);}

ll lcm(ll a,ll b){return a*b/__gcd(a,b);}

bool BashGame(ll n,ll k){if(n%(k+1)==0)return false;else return true;}

ll rnd(ll l,ll r){ll ans=uniform_int_distribution<ll>(l,r)(rng);return ans;}

ll qpow(ll a,ll b){ll res=1;while(b>0){if(b&1)res=res*a;a=a*a;b>>=1;}return res;}

//void printname(auto x){cout<<abi::__cxa_demangle(typeid(x).name(),NULL,NULL,NULL)<<endl;}

double rndb(double l,double r){double ans=uniform_real_distribution<double>(l,r)(rng);return ans;}

bool WythoffGame(ll n,ll m){double c=(double)(abs(m-n));ll p=(ll)(c*Wythoff);return (p!=min(m,n));}

ll qpow(ll a,ll b,ll m){a%=m;ll res=1;while(b>0){if(b&1)res=res*a%m;a=a*a%m;b>>=1;}return res;}

double psqrt(double x,double y,double xx,double yy){double res=((x-xx)*(x-xx)+(y-yy)*(y-yy));return res;}

double ssqrt(double x,double y,double xx,double yy){double res=sqrt(psqrt(x,y,xx,yy));return res;}

ll inv(ll x){return qpow(x,Z-2,Z);}

namespace fastio{

bool isdecimal(char c){return (c >= 48 && c <= 57) || (c == 46);}

bool isdigit(char c){return c >= 48 && c <= 57;}

const int maxsz=10000000;

class fast_iostream{public:

  bool endf = 1,flag;

  char ch = get_char();

  char get_char(){

    static char buffer[maxsz], *a = buffer, *b = buffer;

    return a == b && (b = (a = buffer) + fread(buffer, 1, maxsz, stdin), b == a) ? EOF : *a++;

  }

  template <typename type> bool get_signed(type& tmp){

    flag = 0;tmp = 0;

    while (!isdigit(ch) && ch != EOF){flag = ch == '-';ch = get_char();};

    if (ch == EOF) return endf = 0;

    do{tmp = tmp*10 + ch - 48;} while (isdigit(ch = get_char()));

    if (flag) tmp = -tmp;

    return 1;

  }

  template <typename type>bool get_unsigned(type& tmp){

    tmp = 0;

    while (!isdigit(ch) && ch != EOF) ch = get_char();

    if (ch == EOF) return endf = 0;

    do{tmp = tmp*10 + ch - 48;} while (isdigit(ch = get_char()));

    return 1;

  }

  int get_str(char* str){

    char* tmp = str;

    while (ch == '\n' || ch == '\r' || ch == ' ') ch = get_char();

    if (ch == EOF) return (endf = 0), *tmp = 0;

    do{*(tmp++) = ch;ch = get_char();} while (ch != '\n' && ch != '\r' && ch != ' ' && ch != EOF);

    *(tmp++) = '\0';

    return static_cast<int>(tmp - str - 1);

  }

  typedef char* charptr;

  fast_iostream& operator>>(char* tmp){get_str(tmp);return *this;}

  template <typename type>fast_iostream& operator>>(type& tmp){get_signed(tmp);return *this;}

  operator bool() const {return endf;}

};

template <typename type>void put(type tmp){

  if (tmp == 0){putchar(48);return;}

  static int top,stk[21];

  if (tmp < 0){tmp = -tmp;putchar('-');}

  while (tmp) stk[++top] = tmp % 10, tmp /= 10;

  while (top) putchar(stk[top--] + 48);

}

}

//fastio::fast_iostream io;

//#define cin io

ll n,m,k,tt,tp,ans,res,sum,cnt;

ll a[N],b[N];

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    //IO

    int T;

    cin>>T;

    while(T--)

    {

        cin>>n;

        {

            ll now=1,k=n;

            while(n%2==0)

            {

                n>>=1;

                now<<=1;

            }

            if(now<=1e9&&now*(now*2+1)<=k)cout<<now*2<<"\n";

            else if(n<=2e9&&n!=1&&n*(n+1)/2<=k)cout<<n<<"\n";

            else cout<<-1<<"\n";

        }

    }

}

/*

3+3k=3k

6+4k=2+4k

10+5k=5k

15+6k=3+6k

21+7k=7k





2 4 6 8 10 12

4 -1 3 -1 4







跳ねた言葉を踏み締めた音に乗って

*/