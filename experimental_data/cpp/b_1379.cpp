//I'm practice

#include <bits/stdc++.h>

/*#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#define odrse tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define odrmse tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace __gnu_pbds;*/

using namespace std;



#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



typedef long long ll;

typedef unsigned long long ull;

typedef double db;

typedef long double ldb;

typedef pair<long long,long long> pll;

typedef pair<long long, int> pli;

typedef pair<int, long long> pil;

typedef vector<ll> vl;

typedef vector<vector<ll>> vvl;

typedef vector<vector<vector<ll>>> vvvl;

typedef vector<int> vi;

typedef vector<pair<long long, long long>> vll;

typedef vector<pli> vli;

typedef vector<pil> vil;

typedef vector<string> vs;

#define prqu priority_queue

typedef priority_queue<ll> pql;

typedef priority_queue<int> pqi;

typedef priority_queue<pll> pqll;

typedef priority_queue<pli> pqli;

typedef priority_queue<pil> pqil;

typedef map<ll,int> mli;

typedef map<ll,ll> mll;

typedef map<int,int> mii;

typedef map<int,ll> mil;

typedef map<pll,ll> mlll;



#define V vector

#define ff(i,a,b) for(ll i=a;i<=b;i++)

#define rep(i,a,b) for(ll i=a;i>=b;i--)

#define ffd(i,a,b,x) for(ll i=a;i<=b;i+=x)

#define repd(i,a,b,x) for(ll i=a;i>=b;i-=x)

#define fff(i,v) for(auto i : v)

#define ffi(i,v) for(ll i = 0; i <= v.sz-1; i++)

#define repi(i,v) for(ll i = v.sz-1; i >= 0; i--)

#define ffp(x1,x2,v) for(auto [x1,x2] : v)

#define ffit(it,v) for(auto it = v.begin() ; it != v.end(); it++)

#define all(x) x.begin(),x.end()

#define en cout<<endl;

#define eren cerr<<endl;

#define pb push_back

#define pf push_front

#define ppf pop_front

#define eb emplace_back

#define ft front()

#define bk back()

#define clr clear()

#define ppb pop_back

#define sqr(x) (x)*(x)

#define gcd(a,b) __gcd(a,b)

#define sz size()

#define rsz resize

#define reset(x,val) memset((x),(val),sizeof(x))

#define mtset multiset

#define cid(x) x = " "+x;

#define sstr substr

#define ins insert

#define ers erase

#define emp empty()

#define maxelm max_element

#define minelm min_element

#define ctn continue

#define rtn return

#define yes cout<<"YES\n"

#define no cout<<"NO\n"

#define yesno(c) (c? "YES":"NO")

#define outyesno(c) { cout<<yesno(c)<<endl; rtn; }

#define nortn {cout<<"NO"<<endl; rtn; }

#define yesrtn { cout<<"YES"<<endl; rtn; }

#define valrtn(x) { cout<<x<<endl; rtn; }

#define x first

#define y second



#define ffmask(mask,n) for(ll mask = 1; mask <= (1<<n)-1; mask++)

//#define ffbit1(x,mask) for(x = mask;x > 0; x -= x & (-x))

#define lastbit1(x) x & (-x)

#define getbit(n,x) (1<<x)&n

#define cntbit1(x) __builtin_popcountll(x)

#define cntbit0(x) __builtin_clzll(x)



#define lwb lower_bound

#define upb upper_bound



#define tcT template <class T

#define tcTU tcT, class U

template<typename T1, typename T2> bool maxi(T1& a, T2 b) {if (a < b) {a = b; return 1;} else return 0;}

template<typename T1, typename T2> bool mini(T1& a, T2 b) {if (a > b) {a = b; return 1;} else return 0;}

template<typename T1, typename T2> bool minswap(T1& a, T2 b) {if (a > b) {swap(a,b); return 1;} else return 0;}

template<typename T1, typename T2> bool maxswap(T1& a, T2 b) {if (a < b) {swap(a,b); return 1;} else return 0;}

template <class T> using mprqu = priority_queue<T, vector<T>, greater<T>>;



#define debug(X) {auto _X=(X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl;}

#define err(x) cerr << #x << " = " << (x) << '\n'

#define arrerr(it1, it2) for(auto it = it1; it != it2; it++) cerr << *it << " "; eren;

#define dot cerr<<".";



inline void inp(){} template<typename F, typename... R> inline void inp(F &f,R&... r){cin>>f;inp(r...);}

inline void out(){} template<typename F, typename... R> inline void out(F f,R... r){cout<<f;out(r...);}



const ll cr = 2e5 + 7;

const ll mod = 1e9 + 7;

const ll MOD = 998244353;

const ll inf = 1e18 + 7;

const ll base = 311;

const ldb pi = (ldb)3.1415926535897932384626433832795;

const string Yes = "Yes";

const string No = "No";

const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

const int dx[] = {-1, 1, 0, 0};

const int dy[] = {0, 0, -1, 1};

bool mem2;



#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define FILE(s) freopen(s".INP","r",stdin);freopen(s".OUT","w",stdout);

#define GetExpert int32_t main()

#define y1 tlapluvnth

#define y2 zz16102007

#define left nthnevaluvtlap

#define right tlapstillluvnt



ll rdr(ll l, ll r) {

    return l + rand() % (r - l + 1);

}



ll rdd(ll ss) {

    vector<ll> digit;

    ff(i, 1, ss) {

        ll k = rand() % 10;

        //cerr << k << endl;

        digit.push_back(k);

    }

    ll ans = 0, power = 1;

    for(ll x : digit) {

        ans += x * power;

        power *= 10;

    }

    return ans;

}



//MAIN PROGRAM----

//----------------

ll m, l, r;

void resetsolve(){



}



void init(){

    cin >> l >> r >> m;

}



bool ishave(ll k, ll& b, ll& c) {

    if (abs(k) > abs(l - r)) return 0;

    if (k < 0) {

        b = l;

        c = l - k;

        return 1;

    }

    b = r;

    c = r - k;

    return 1;

}



void solveinsolve(){

    ff(a, l, r) {

        ll x1 = (m / a) * a; // x1 <= m;

        ll x2 = (m / a) * a + a;  // x2 >= m;



        ll b, c;

        if (ishave(m - x1, b, c)) {

            //cerr << a << " " << x1 << endl;

            if ((m - b + c) / a == 0) goto G1;

            cout << a << " " << b << " " << c << endl;

            assert((m - (b - c)) % a == 0);

            return;

        }



        G1:

        if (ishave(m - x2, b, c)) {

            //cerr << a << " " << x2 << endl;

            if ((m - b + c) / a == 0) continue;

            cout << a << " " << b << " " << c << endl;

            assert((m - (b - c)) % a == 0);

            return;

        }



    }

}



void print(){



}



void solve(){

    //remember reset and init

    resetsolve();

    init();

    solveinsolve();

    print();

}



void generation() {

        fclose(stdin);

        ofstream g;

        g.open("FILE.INP");

        g << rdr(1, 100) << " " << rdr(1, 100);

        g.close();

        freopen("FILE.INP","r",stdin);

}



void pre_process(){



}



bool mem1;



GetExpert{

    pre_process();

    fastIO;

    srand(time(NULL));

    #ifndef ONLINE_JUDGE

        FILE("FILE");

    #endif

    ll t = 1; cin>>t; ff(____,1,t) {

        //cout<<"Case "<<____<<":"<<endl;

        //cerr<<"Case "<<____<<endl;

        solve();

        //generation();

        //eren;

    }

    //------------

    //eren;

    //cerr << "Memory Cost: " << abs(&mem1-&mem2)/1024./1024. << " MB" << endl;

    //cerr << "Time Cost: " << clock()*1000./CLOCKS_PER_SEC << " MS" << endl;

}