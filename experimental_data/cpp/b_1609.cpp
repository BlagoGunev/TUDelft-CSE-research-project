#include<iostream>

#include<iomanip>

#include<algorithm>

#include<vector>

#include<utility>

#include<set>

#include<unordered_set>

#include<list>

#include<iterator>

#include<deque>

#include<queue>

#include<stack>

#include<set>

#include<bitset>

#include<random>

#include<map>

#include<unordered_map>

#include<stdio.h>

#include<complex>

#include<math.h>

#include<cstring>

#include<chrono>

#include<string>



using namespace std;



#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

#define ll long long int

#define lld long double

#define ull unsigned long long

#define mod 1000000007

#define modd 998244353

#define inf 1000000000000000005

#define key first

#define val second

#define pb push_back

#define ppb pop_back

#define nl cout<<"\n"

#define yes cout<<"YES"

#define no cout<<"NO"

#define sp " "

#define data(obj) obj.begin(),obj.end()

#define vll vector<ll>

#define vlll vector<vector<ll>>

#define pll pair<ll,ll>

#define umap unordered_map

#define uset unordered_set

#define sz(x) (ll)x.size()

#define dbg(x) cerr << #x<<" "; _print(x); cerr << endl;



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

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



template<typename T1, typename T2> // cin >> pair

istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T> // cin >> vector

istream &operator>>(istream &istream, vector<T> &v) { for (auto &it : v) { cin >> it; } return istream; }

template<typename T1, typename T2> // cout << pair

ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

template<typename T> // cout << vector

ostream &operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) { cout << it << " "; }nl; return ostream; }



void solve(){

    ll n , q;

    cin>>n>>q;

    string s;

    cin>>s;

    ll tot = 0;

    for(ll i = 0 ; i < n-2 ; i++){

        if(s[i] == 'a' and s[i+1] == 'b' and s[i+2] == 'c') tot++;

    }

    while(q--){

        ll pos;

        char c;

        cin>>pos;

        cin>>c;

        pos--;

        if(pos-1 >= 0 and pos+1 < n and s[pos-1] == 'a' and s[pos] == 'b' and s[pos+1] == 'c') tot--;

        else if(pos+2 < n and s[pos] == 'a' and s[pos+1] == 'b' and s[pos+2] == 'c') tot--;

        else if(pos-2 >= 0 and s[pos-2] == 'a' and s[pos-1] == 'b' and s[pos] == 'c') tot--;



        s[pos] = c;



        if(pos-1 >= 0 and pos+1 < n and s[pos-1] == 'a' and s[pos] == 'b' and s[pos+1] == 'c') tot++;

        else if(pos+2 < n and s[pos] == 'a' and s[pos+1] == 'b' and s[pos+2] == 'c') tot++;

        else if(pos-2 >= 0 and s[pos-2] == 'a' and s[pos-1] == 'b' and s[pos] == 'c') tot++;



        cout<<tot;nl;

    }

}



int main() {

#ifndef ONLINE_JUDGE

    freopen("inputf.txt", "r", stdin);

    freopen("outputf.txt", "w", stdout);

#endif

    fast;

    ll t = 1;

    // cin>>t;

    while(t--){

        solve();

        nl;

    }

    return 0;

}