#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define nl "\n"
#define as " "
#define rep(i, l, r) for(int i=l;i<r;++i)

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define maxij(a, i, j)    ( max_element((a).begin()+i, (a).begin()+j+1) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define sz(a)      (int)((a).size())
#define rs(a, n)   ((a).resize(n))
#define ms(a, val)     ( memset((a), val, sz(a))

//debugging
#ifndef ONLINE_JUDGE
#define dg(x) cerr << #x << "\t"; _print(x); cerr << endl;
#define dg2(x, y) cerr << #x << "\t"; _print(x); cerr << "\t|\t" << #y << "\t"; _print(y); cerr << endl;
#define dg3(x, y, z) cerr << #x << "\t"; _print(x); cerr << "\t|\t" << #y << "\t"; _print(y); cerr << "\t|\t" << #z << "\t"; _print(z); cerr << endl;
#define dg4(x, y, z, w) cerr << #x << "\t"; _print(x); cerr << "\t|\t" << #y << "\t"; _print(y); cerr << "\t|\t" << #z << "\t"; _print(z); cerr << "\t|\t" << #w << "\t"; _print(w); cerr << endl;
#else
#define dg(x)
#define dg2(x, y)
#define dg3(x, y, z)
#define dg4(x, y, z, w)
#endif

void _print(int x){cerr << x;}
void _print(float x){cerr << x;}
void _print(string x){cerr << x;}
void _print(ll x){cerr << x;}
void _print(ull x){cerr << x;}
void _print(char x){cerr << x;}
void _print(bool x){cerr << x;}
template<class T,class V>void _print(pair<T,V> x){cerr << "[";_print(x.fi);cerr << " ";_print(x.se);cerr << "]";}
template<class T> void _print(set<T> x){cerr << "[ ";for(T i: x){_print(i);cerr << " ";}cerr << "]";}
template<class T> void _print(multiset<T> x){cerr << "[ ";for(T i: x){_print(i);cerr << " ";}cerr << "]";}
template<class T> void _print(priority_queue<T, vector<T>, greater<T>> x){cerr << "[ ";while(!x.empty()){_print(x.top());cerr << " ";x.pop();}cerr << "]";}
template<class T> void _print(priority_queue<T> x){cerr << "[ ";while(!x.empty()){_print(x.top());cerr << " ";x.pop();}cerr << "]";}
template<class T> void _print(deque<T> x){cerr << "[ ";for(T i: x){_print(i);cerr << " ";}cerr << "]";}
template<class T> void _print(vector<T> x){cerr << "[ ";rep(i, 1, x.size()+1){cerr << "(" << i-1 << ")";_print((T)x[i-1]);cerr << " ";}cerr << "]";}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
typedef vector<pii> vpii;
typedef vector<psi> vpsi;
typedef vector<pss> vpss;

// Vector
template<typename T>            istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>            ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
// Pair
template<typename T,typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T,typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
//Vector + Pair
template<typename T,typename U> istream& operator>>(istream& is, vector<pair<T,U>> &p){for(auto &i:p){is >> i.fi >> i.se;}return is;}
template<typename T,typename U> ostream& operator<<(ostream& os, vector<pair<T,U>> &p){for(auto &i:p){os << i.fi << " " << i.se << endl;}return os;}
template <typename T>pair<T, bool> getNthElement(set<T>& searchSet,int index){pair<T, bool> result;if (searchSet.size() > index) {result.first= *(std::next(searchSet.begin(),index));result.second = true;}else result.second = false;return result;}
//Set
template<typename T>            istream& operator>>(istream& is,  set<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>            ostream& operator<<(ostream& os,  set<T>  v){for (auto& i : v) os << i << ' '; return os;}

const ll mod = 998244353;
const int N = 1010;

// Modulus-Mathematics
template<typename T,typename U>            ll modMul(T a, U b){return ((a%mod)*1LL*(b%mod))%mod;}
template<typename T,typename U>            ll binpower(T n, U k){T res=1;  while(k){   if(k & 1){res=modMul(res, n);}  n=modMul(n, n); k >>= 1;}   return res%mod;}
template<typename T>            T moduloInverse(T a){return binpower(a, mod-2);}
template<typename T,typename U>            ll modAdd(T a, U b){return ((a%mod)+(b%mod))%mod;}
template<typename T,typename U>            ll modSub(T a, U b){return ((a%mod)-(b%mod)+mod)%mod;}
template<typename T,typename U>            ll modDiv(T a, U b){return modMul(a, moduloInverse(b));}

//vll dp(N), Sum(N);
//
//void solve(){
//    ll n; cin >> n;
//    rep(i, 0, n+1)
//        dp[i]=Sum[i]=0;
//    dp[1]=1;
//    Sum[1]=1;
//    if(n>1){
//        rep(i, 2, n+1){
//            ll tmp=i;
//            ll j=2;
//            unordered_map<int ,int> mp;
//            while(tmp>1 && j*j<=tmp){
//                if(tmp%j==0){
//                    mp[j]=1;
//                    while(tmp%j==0){
//                        mp[j]++;
//                        tmp/=j;
//                    }
//                }
//                j++;
//            }
//            if(tmp>1)
//                mp[tmp]=1;
//            ll t=1;
//            for(auto [x, y]: mp){
//                t=modMul(t, y+1);
//            }
//            t=modSub(t, 1);
//            dp[i]=modAdd(t, Sum[i-1]);
//            Sum[i]=modAdd(dp[i], Sum[i-1]);
//        }
//    }
//}

void solve(){
    string str; int k;
    cin >> str >> k;
    vi cnt(10, 0);
    int dif=0;
    for(auto i: str){
        if(cnt[i-'0']==0)
            dif++;
        cnt[i-'0']++;
    }
    if(dif<=k){
        cout << str << nl;
    }else{
        if(k==1){
            char c=str[0];
            string ans="";
            for(auto i: str){
                if(i<c){
                    break;
                }else if(i>c) {
                    c++;
                    break;
                }
            }
            while(ans.length()<str.length()){
                ans.pb(c);
            }
            cout << ans << nl;
            return;
        }else{
            char c=str[0], d;
            string ans="";
            bool ff=false;
            for(auto i: str){
                if(i==c){
                    ans.pb(i);
                    continue;
                }
                if(ff && d==i){
                    ans.pb(d);
                    continue;
                }
                if(i!=c && !ff){
                    ff=true;
                    d=i;
                    ans.pb(d);
                    continue;
                }
                if(i<min(c, d)){
                    break;
                }else if(i<max(c, d)) {
                    ans.pb(max(c, d));
                    break;
                }else{
                    char M=max(c, d);
                    auto it=ans.find(d);
//                    dg((int)it)
                    for(int ii=ans.length()-1;ii>it;--ii){
                        if(ans[ii]<M){
                            ans=ans.substr(0, ii);
                            ans.pb(M);
                            char ccc=min(c, d);
                            while(ans.length()<str.length()){
                                ans.pb(ccc);
                            }
                            cout << ans << nl;
                            return;
                        }
                    }
                    ++d;
                    ans[it]=d;
                    ans=ans.substr(0, it+1);
                    if(c==d)
                        d='0';
                    break;
                }
            }
            char ccc=min(c, d);
            while(ans.length()<str.length()){
                ans.pb(ccc);
            }
            cout << ans << nl;
            return;
        }
//        string ans="";
//        set<char> s;
//        vi flag(10, 0);
//        char last;
//        int pos;
//        for(auto i: str){
////            dg(ans)
//            if(flag[i-'0']){
//                ans.pb(i);
//            }else{
//                if(s.size()<k){
//                    s.insert(i);
//                    flag[i-'0']=1;
//                    ans.pb(i);
//                    last=i;
//                }else{
//                    auto it=--s.end();
////                    dg(*(it))
//                    while((it)!=(s.begin()) && (*(it))>i){
//                        it--;
//                    }
//                    if(*(it)<i)
//                        ++it;
////                    dg(*(it))
//                    if((*it)>i){
//                        ans.pb(*it);
//                        char cc=*s.begin();
//                        while(ans.length()<str.length()){
//                            ans.pb(cc);
//                        }
//                        cout << ans << nl;
//                        return;
//                    }else{
//                        auto f=ans.find(last);
//                        ans[f]++;
//                        ans=ans.substr(0, f+1);
//                        if(flag[ans[f]-'0']==1){
//                            while(ans.length()<str.length()){
//                                ans.pb('0');
//                            }
//                            cout << ans << nl;
//                            return;
//                        }
//                        s.insert(ans[f]);
//                        char cc=*s.begin();
//                        if(cc==last){
//                            cc=*(++s.begin());
//                        }
//                        while(ans.length()<str.length()){
//                            ans.pb(cc);
//                        }
//                        cout << ans << nl;
//                        return;
//                    }
//                }
//            }
//        }
    }
}

void initialise() {
    cout << std::fixed << std::setprecision(9);
    return;
}

int main() {
    FAST_IO;

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif

    int t=1;
    cin >> t;
    initialise();
    rep(i, 1, t+1){
//        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}