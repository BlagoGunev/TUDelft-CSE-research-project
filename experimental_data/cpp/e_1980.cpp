// ░░░░░██╗░█████╗░██╗  ░██████╗██╗░░██╗██████╗░███████╗███████╗  ██████╗░░█████╗░███╗░░░███╗
// ░░░░░██║██╔══██╗██║  ██╔════╝██║░░██║██╔══██╗██╔════╝██╔════╝  ██╔══██╗██╔══██╗████╗░████║
// ░░░░░██║███████║██║  ╚█████╗░███████║██████╔╝█████╗░░█████╗░░  ██████╔╝███████║██╔████╔██║
// ██╗░░██║██╔══██║██║  ░╚═══██╗██╔══██║██╔══██╗██╔══╝░░██╔══╝░░  ██╔══██╗██╔══██║██║╚██╔╝██║
// ╚█████╔╝██║░░██║██║  ██████╔╝██║░░██║██║░░██║███████╗███████╗  ██║░░██║██║░░██║██║░╚═╝░██║
// ░╚════╝░╚═╝░░╚═╝╚═╝  ╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚══════╝  ╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░░░░╚═╝
#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define fo(i, n) for (long long i = 0; i < n; i++)
#define fr(i, n) for (ll i = n - 1; i >= 0;i--)
#define Fo(i, k, n) for (long long i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define arr(a); int n; cin>>n; cin(a);
#define cin(a); int a[n]; fo(i,n) cin>>a[i];
#define INF 1000000000000000003
#define ff first
#define ss second
#define pb push_back
#define pob pop_back
#define print(a) fo(i, a.size()) cout << a[i]<<" ";
#define printv(v) for(auto x:v)cout<<x<<" ";
#define el "\n";
#define yes cout<<"YES"<<el;
#define no cout<<"NO"<<el;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "["; for (T i : v) {_print(i); cerr << " ";} cerr << "] ";}
template <class T> void _print(set <T> v) {cerr << "["; for (T i : v) {_print(i); cerr << " ";} cerr << "] ";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "] ";}
//priority_queue <int, vector<int>, greater<int> > pq;
//priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
ll binpow(ll a, ll b, ll m){a %= m;ll res = 1;while (b > 0) {if (b & 1){res = res * a % m;}a = a * a % m;b >>= 1;}return res;}
/*vector<ll> par(1001), siz(1001);
ll Upar(ll a){if (a == par[a]){return a;}return par[a] = Upar(par[a]);}
void un(ll a, ll b){a = Upar(a);b = Upar(b);if (siz[a] > siz[b]){par[b] = a;siz[a] += siz[b];}else{par[a] = b;siz[b] += siz[a];}}*/
ll mod =1e9 + 7;
void hehe(){
    int n, m;
    cin >> n >> m;
    set<vector<int>> a1, a2, b1, b2;
    int a[n][m];
    int b[n][m];
    fo(i,n)
    {
       fo(j,m)
        {
            cin >> a[i][j];
        }
    }
    fo(i,n)
    {
        fo(j,m)
        {
            cin >> b[i][j];
        }
    }
    fo(i,n)
    {
        vector<int> temp;
        fo(j,m)
        {
            temp.push_back(b[i][j]);
        }
        sort(all(temp));
        b1.insert(temp);
    }
    // for(auto x:b1){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    fo(i,m)
    {
        vector<int> temp;
        fo(j,n)
        {
            temp.push_back(b[j][i]);
        }
        sort(all(temp));
        b2.insert(temp);
    }
    // for(auto x:b2){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    fo(i,n)
    {
        vector<int> temp;
        fo(j,m)
        {
            temp.push_back(a[i][j]);
        }
        sort(all(temp));
        a1.insert(temp);
    }
    fo(i,m)
    {
        vector<int> temp;
        fo(j,n)
        {
            temp.push_back(a[j][i]);
        }
        sort(all(temp));
        a2.insert(temp);
    }
    // for (auto x : b1)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    auto it1 = a2.begin();
    auto it2 = b2.begin();
    while (it1 != a2.end() && it2 != b2.end())
    {
        if (*it1 != *it2)
        {
            no;
            return;
        }
        it1++;
        it2++;
    }
    auto it3 = a1.begin();
    auto it4 = b1.begin();
    while (it3 != a1.end() && it4 != b1.end())
    {
        if (*it3 != *it4)
        {
            no;
            return;
        }
        it3++;
        it4++;
    }
    yes;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
freopen("error.txt", "w", stderr);
#endif
ios::sync_with_stdio(0);
cin.tie(0);
//fo(i,1001){par[i]=i;siz[i]=1;}
int T;
cin >> T;
while (T--) {
hehe();
}
return 0;
}