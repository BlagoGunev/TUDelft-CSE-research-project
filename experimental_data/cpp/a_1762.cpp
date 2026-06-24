#line 1 "f.cpp"
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define repp(i,n,m) for (int i = m; i < int(n); ++i)
#define reb(i,n) for (int i = int(n)-1; i >= 0; --i)
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
using PL = pair<ll,ll>;

template<class T>istream &operator>>(istream &is,vector<T> &v){for(auto &e:v)is>>e;return is;}

template<typename T1, typename T2>void print(pair<T1,T2> a);
template<typename T>void print(vector<T> v);
template<typename T>void print(vector<vector<T>> v);
void print(){ putchar(' '); }
void print(bool a){ printf("%d", a); }
void print(int a){ printf("%d", a); }
void print(long a){ printf("%ld", a); }
void print(long long a){ printf("%lld", a); }
void print(char a){ printf("%c", a); }
void print(char a[]){ printf("%s", a); }
void print(const char a[]){ printf("%s", a); }
void print(long double a){ printf("%.15Lf", a); }
void print(const string& a){ for(auto&& i : a) print(i); }
void print(unsigned int a){ printf("%u", a); }
template<class T> void print(const T& a){ cout << a;}
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
template<typename T1,typename T2>void print(pair<T1,T2> a){print(a.first);print(),print(a.second);}
template<typename T>void print(vector<T> v){for(auto ite=v.begin();ite!=v.end();){print(*ite);if(++ite!=v.end())print();}}
template<typename T>void print(vector<vector<T>> v){for(auto ite=v.begin();ite!=v.end();){print(*ite);if(++ite!=v.end())out();}}

template<typename T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
template<typename T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}

void fast_io(){cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);}

namespace noya2{

const int INF = 1001001007;
const long long mod1 = 998244353;
const long long mod2 = 1000000007;
const long long inf = 2e18;
const long double pi = 3.14159265358979323;
const long double eps = 1e-7;
vector<int> dx = {0,1,0,-1,1,1,-1,-1};
vector<int> dy = {1,0,-1,0,1,-1,-1,1};
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string NUM = "0123456789";
void o(){out("!?");}
void yn(bool f){out(f ? "Yes" : "No");}
void YN(bool F){out(F ? "YES" : "NO");}
template<typename T>bool range(T a,T b,T x){return (a<=x&&x<b);}
template<typename T>bool rrange(T a,T b,T c,T d,T x,T y){return (range(a,c,x)&&range(b,d,y));}

} // namespace noya2
using namespace noya2;


void solve(){
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    int sum = 0;
    int cnt = INF;
    rep(i,n){
        sum += a[i];
        int p = a[i] % 2;
        int c = 0;
        while (a[i] % 2 == p) a[i] /= 2, c++;
        chmin(cnt,c);
    }
    if (sum % 2 == 0) out(0);
    else out(cnt);
}

int main(){
    fast_io();
    int t = 1; cin >> t;
    while(t--) solve();
}