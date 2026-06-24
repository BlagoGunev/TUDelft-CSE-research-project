#include<bits/stdc++.h>

#define ll long long

#define flot(n) cout << setprecision(n) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)

#define all(a) (a).begin() , (a).end()

#define pb push_back

#define mp make_pair

#define pii pair<int,int>

#define pll pair<ll,ll>

#define piii pair<pii,int>

#define plll pair<pll,ll>

#define R return

#define B break

#define C continue

#define SET(n , i) memset(n , i , sizeof(n))

#define SD ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define rep(i , n) for(int i = 0 ; i < n ; i++)

#define repn(i , j , n) for(int i = j ; i < n ; i++)

#define repr(i,n,j) for(int i=n;i>=j;i--)

#define positive(x) ((x%mod+mod)%mod)

#define YES(f)cout<<((f)?"YES":"NO")<<endl

#define F first

#define S second

#define endl '\n'

#define vi vector<int>

//#define int ll

using namespace std;

void readFromFile(string input = "input.txt",string output="output.txt") {

    #ifndef ONLINE_JUDGE

        freopen(input.c_str(),"r",stdin);

        freopen(output.c_str(),"w",stdout);

    #endif

}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd(ll x, ll y) {

    return uniform_int_distribution<ll>(x, y)(rng);

}

template <typename T> void Max(T& x,T y){x=max(x,y);}

template <typename T> void Min(T& x,T y){x=min(x,y);}

const int INF = 0x3f3f3f3f;

const ll INFLL = 0x3f3f3f3f3f3f3f3f;

const long double EPS = 1e-3;

const long double pi =  acos(-1.0);

const int mod = 1e9+9;

const int N =2e5+3;

ll Mul(ll x,ll y,ll mod=mod){R((x%mod)*(y%mod))%mod;}

ll Add(ll x,ll y,ll mod=mod){R((x%mod)+(y%mod)+2ll*mod)%mod;}

int n,m,a[N],c[N];

bool can(ll mid) {

    ll k=m,tk=0;

    repr(i,m,1) {

        while(k > 0 && a[k]==0)k--;

        if(k <= 0) R 1;

        if(i > k) C;

        ll rem = 1ll*c[i]*mid-tk;

        assert(rem >= 0);

        if(a[k] <= rem) tk += a[k],k--;

        else R 0;

    }

    R k <=0;

}

void calc(vector<vector<int>> &v,int mid) {

    ll k=m,tk=0;

    v.resize(mid);

    int z=0;

    repr(i,m,1) {

        while(k > 0 && a[k]==0)k--;

        if(k <= 0) B;

        if(i > k) C;

        ll rem = 1ll*c[i]*mid-tk;

        tk += a[k];

        while(a[k]--) {

            v[z].pb(k);

            z = (z+1)%mid;

        }

        k--;

    }

}

void solve() {

    cin >> n >> m;

    rep(i,n) {

        int x;cin>>x;

        a[x]++;

    }

    rep(i,m)cin >> c[i+1];

    int l=1,r=n,mid,ans=-1;

    while(l <= r) {

        mid = (l+r)/2;

        if(can(mid)) {

            ans = mid;

            r = mid-1;

        }else l = mid+1;

    }

    vector<vector<int>> v;calc(v,ans);

    cout << v.size() << endl;

    for(auto &it:v) {

        cout << it.size() << ' ';

        for(auto &e:it)cout<<e << ' ';cout<<endl;

    }

}

int32_t main() {

    readFromFile();

    SD;

    int t = 1;

//    cin >> t;

//    scanf("%d",&t);

    rep(i,t) {

        solve();

    }

}