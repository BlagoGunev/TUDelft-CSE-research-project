/*
     七転び八起き
     Asahi_
*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define repk(i,k,n)    for (i = k; i < n; ++i)
#define rev(i,k,n)     for (i = k; i >=n; --i)
#define int            long long int
#define double         long double
#define F              first
#define S              second
#define eb             emplace_back
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define br             cout<<"\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define revsort(p)     sort(p.begin(),p.end(),greater<int>());
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define pa(a)          cout<<a;br;

template<typename T> using matrix = vector<vector<T> >;
template<typename T> using rubik = vector<vector<vector<T> > >;
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out<<x.F<<" "<<x.S;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.F >> x.S;}


template<class T> void read(T& x) {cin >> x;}
template<class H, class... T> void read(H& h, T&... t) {read(h);read(t...);} 

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
const char* comma = strchr (names + 1, ',');
cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
                
inline int power(int a, int b)
{int x = 1;
while (b){if(b & 1){x *= a;}a *= a;b >>= 1;}
return x;
}

const int M=(int)1e9+7;
const int N = 200005;
int i=0,j=0,k=0;
//----------------------------------------------------------------------//
void solve() {
int n;
cin>>n;
int m;
cin>>m;

matrix<char>a(n,vector<char>(m));

rep(i,n){
    cin>>a[i];
}

rep(i,n-1){
    rep(j,m-1){
        int ans=0;
        ans+=(a[i][j]=='1');
        ans+=(a[i][j+1]=='1');
        ans+=(a[i+1][j]=='1');
        ans+=(a[i+1][j+1]=='1');
        if(ans==3){pa("NO");return;}
    }
}
pa("YES");
}
//---------------------------------------------------------------------//
int32_t main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int t = 1;
cin >> t;
while (t--) solve();
return 0;
}