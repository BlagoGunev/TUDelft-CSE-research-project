#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define all(v) v.begin(), v.end()
#define MAX 200000
#define MOD 1000000007
#define nl '\n'
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int inf = 1e9;

void takeinput(vector<int> &a, int start, int end){for(int i=start;i<=end;i++)cin>>a[i];}
void yes(){cout<<"YES"<<nl;}
void no(){cout<<"NO"<<nl;}
void testcase(int t){cout<<"Case #"<<t<<" : ";}

int exp(int ,int);
int ceildiv(int, int);
int modinv(int);


class Segtree{
    private:
    struct dat{
        int x, lazy;
    };
    dat combine(dat a, dat b){
        return {min(a.x, b.x), 0};
    }
    dat updateNode(dat a, int lazytop, int tl, int tr){
        return {a.x + lazytop, a.lazy + lazytop};
    }

    dat defval = {inf, 0};
    vector<dat> tree;
    int n; 

    void build(vector<int> &a, int v, int tl, int tr){
        if(tl == tr){
            tree[v].x = a[tl];
        }else{
            int mid = (tl + tr)/2;
            build(a, 2*v, tl, mid);
            build(a, 2*v + 1, mid + 1, tr);
            tree[v] = combine(tree[2*v], tree[2*v + 1]);
        }
    }

    void push(ll v, ll tl, ll tr){
        if(tree[v].lazy && tl < tr){
            int mid = (tl + tr)/2;
            tree[2*v] = updateNode(tree[2*v], tree[v].lazy, tl, mid);
            tree[2*v + 1] = updateNode(tree[2*v + 1], tree[v].lazy, mid, tr);
            tree[v].lazy = 0;
        }
    }

    void rangeUpdate(ll v, ll tl, ll tr, ll l, ll r, ll val){
        if(l > r || l > tr || r < tl) return;
        if(l <= tl && tr <= r){
            tree[v] = updateNode(tree[v], val, tl, tr);
        }else{
            push(v, tl, tr);
            ll mid = (tl + tr)/2;
            rangeUpdate(2*v, tl, mid, l, min(r,mid), val);
            rangeUpdate(2*v + 1, mid + 1, tr, max(l,mid + 1), r, val);
            tree[v] = combine(tree[2*v], tree[2*v + 1]);
        }
    }

    dat query(ll l, ll r, ll v, ll tl, ll tr){
        if(l> r || l > tr || r < tl) return defval;
        if(l <= tl && tr <= r){
            return tree[v];
        }
        push(v, tl, tr);
        ll mid = (tl + tr)/2;
        return combine(
            query(l, r, v*2, tl, mid), 
            query(l, r, v*2 + 1, mid + 1, tr)
        );
    }

    int getFirstNeg(int v, int tl, int tr){
        if(tl == tr){
            if(tree[v].x < 0) return tl;
            return n;
        }
        push(v, tl, tr);
        int mid = (tl + tr)/2;
        int left = tree[2*v].x, right = tree[2*v + 1].x;
        if(left < 0){
            return getFirstNeg(2*v, tl, mid);
        }
        if(right < 0){
            return getFirstNeg(2*v + 1, mid + 1, tr);
        }
        return n;
    };
    
    public : 
    Segtree(vector<int> &a, int n_){
        n = n_;
        int x = 1;
        while(x < n) x*=2;
        tree.assign(2*x + 10, defval);
        build(a, 1, 0, n-1);
    }
    Segtree(){}
    
    void rangeUpdate(ll l,ll r,ll toadd){
        rangeUpdate(1, 0, n - 1, l, r, toadd);
    }
    ll queryMn(ll l, ll r){
        return query(l, r, 1, 0, n - 1).x;
    }
    int getFirstNeg(){
        return getFirstNeg(1, 0, n - 1);
    }
    void debugtree(){
        for(int i=0;i<n;i++){
            cerr<<queryMn(i, i)<<" ";
        } cerr<<nl;
    }
};

class BracketSequence{
    public :
    Segtree pref;
    int n;
    string s;
    set<int> doubles; 

    BracketSequence(string s) : n(s.size()), s(s) {
        vector<int> prefix(n, 0);
        prefix[0] = s[0] == '(' ? 1 : -1;
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + (s[i] == '(' ? 1 : -1);
            if(s[i] == s[i - 1] && s[i] == '('){
                doubles.insert(i);
            }
        }
        pref = Segtree(prefix, n);
    }

    int getFirstDouble(){
        if(doubles.empty()) return n;
        return *doubles.begin();
    }
    int getFirstNeg(){
        return pref.getFirstNeg();
    }
    void operate(int i){
        if(s[i] == '('){
            s[i] = ')';
            pref.rangeUpdate(i, n - 1, -2);
            if(i > 0 && s[i - 1] == '('){
                doubles.erase(i);
            }
            if(i < n - 1 && s[i + 1] == '('){
                doubles.erase(i + 1);
            }
        }else{
            s[i] = '(';
            pref.rangeUpdate(i, n - 1, 2);
            if(i > 0 && s[i - 1] == '('){
                doubles.insert(i);
            }
            if(i < n - 1 && s[i + 1] == '('){
                doubles.insert(i + 1);
            }
        }
    }

    bool isOk(){
        return getFirstDouble() <= getFirstNeg();
    }

};

void solve(int t){
    int n, q; cin>>n>>q;
    string s; cin>>s;

    auto reverseSeq = [](string s)->string{
        for(auto &c : s) c = '(' ^ ')' ^ c;
        reverse(all(s));
        return s;
    };

    BracketSequence fwd(s), rev(reverseSeq(s));

    for(int i = 0; i < q; i++){
        int ind; cin>>ind; ind--; 
        if(n & 1){
            no(); continue;
        }
        fwd.operate(ind); rev.operate(n - 1 - ind);
        // debug(fwd.s);
        // debug(fwd.getFirstNeg(), fwd.getFirstDouble());
        bool ok = fwd.isOk() && rev.isOk();
        if(ok) yes();
        else no();
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    freopen("error.out","w",stderr);
    #endif
    int t = 1;
    //int t; cin>>t; 
    for(int i=1;i<=t;i++){
        solve(i);
    }
}

int exp(int a, int b){
    int res = 1;
    while(b > 0){
        if( b % 2 == 1){
            res = (res * a) % MOD;
        }
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}

int ceildiv(int a, int b){
    return (a + b - 1)/b;
}

int modinv(int a){
    return exp(a, MOD - 2);
}