#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define vvi(a,n,m)     vector <vector<int> > a(n, vector<int> (m,0))
#define vvl            vector <vi>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define __builtin__popcount __builtin__popcountll
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define take(x) for(int i=0;i<x.size();i++)cin>>x[i];

int mod=1000000007;

int norm (int x) {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        return x;
}
template<class T>
T power(T a, int b) {
        T res = 1;
        for (; b; b /= 2, a *= a) {
                if (b & 1) res *= a;
        }
        return res;
}
struct Z {
        int x;
        Z(int x = 0) : x(norm(x)) {}
        int val() const {
                return x;
        }
        Z operator-() const {
                return Z(norm(mod - x));
        }
        Z inv() const {
                return power(*this, mod - 2);
        }
        Z &operator*=(const Z &rhs) {
                x = x * rhs.x % mod;
                return *this;
        }
        Z &operator+=(const Z &rhs) {
                x = norm(x + rhs.x);
                return *this;
        }
        Z &operator-=(const Z &rhs) {
                x = norm(x - rhs.x);
                return *this;
        }
        Z &operator/=(const Z &rhs) {
                return *this *= rhs.inv();
        }
        friend Z operator*(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res *= rhs;
                return res;
        }
        friend Z operator+(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res += rhs;
                return res;
        }
        friend Z operator-(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res -= rhs;
                return res;
        }
        friend Z operator/(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res /= rhs;
                return res;
        }
        friend std::istream &operator>>(std::istream &is, Z &a) {
                int v;
                is >> v;
                a = Z(v);
                return is;
        }
        friend std::ostream &operator<<(std::ostream &os, const Z &a) {
                return os << a.val();
        }
};


template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

bool compare(pair<int,int>& a, pair<int,int>& b){
    return a.F<b.F;
}

void solve() {
    int l,r,k;
    cin>>l>>r>>k;
    if(k>=10) cout<<0<<endl;
    else{
    	int opt=9/k;
    	Z ans=1;
    	ans=ans*power(Z(opt+1),r);
    	ans=ans-power(Z(opt+1),l);
   		cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}