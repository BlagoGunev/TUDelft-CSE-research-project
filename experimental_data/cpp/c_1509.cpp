#include <bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>

// #include<ext/pb_ds/tree_policy.hpp>



using namespace std;

//using namespace __gnu_pbds;



#define ll long long 

#define int long long

#define nline "\n"

#define pb push_back

#define ppb pop_back

#define pii pair<int,int>

#define ff first

#define ss second

#define PI 3.141592653589793238462

#define set_bits __builtin_popcountll

#define sz(x) ((int)(x).size())

#define all(x) (x).begin(), (x).end()

#define rep(i,a,n)     for(int i=a;i<n;i++)

#define jaldi      ios::sync_with_stdio(0);cin.tie(0);





typedef unsigned long long ull;

typedef long double lld;



//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

//pbds A;

//A.insert()  --To insert values into the set

//*A.find_by_order(k)  -- finding Kth element

//A.order_of_key(X)  -- number of elements less than X

//A.erase(X)  --Removes element from the set



#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#else

#define debug(x)

#endif



void _print(ll t) {cerr << t;}

// void _print(int t) {cerr << t;}

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



//SNIPPETS--

//---------*----------*-----------*------------*-----------*

//start,kickstart

//nv

//factorial,inverse,NcR

//binexp(a,b,N)

//sieve,divisors,prime_factors

//xorr

//bfs,dfs,dijkstra,bipartite graph

//dsu   

//---------*----------*-----------*------------*-----------*



void init(){

    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    freopen("error.txt", "w", stderr);

    #endif //

}



const long long N = 2e5+2;

const long long M = 1e9+7;

const long long NN = 4e4+1;

const long long INF = 1e18;



void solve(){    

    int n;

    cin >> n;



    vector <int> v(n);

    rep(i,0,n){

        cin >> v[i];

    }



    sort(all(v));



    int dp[n+1][n+1];



    for(int i=n; i>=1; i--){

        rep(j,0,n+1){

            if(i==0 || j==0){

                dp[i][j] = INF;

            }

            else if(i>j){

                dp[i][j] = INF;

            }

            else if(i==j){

                dp[i][j] = 0;

            }

            else{

                dp[i][j] = (v[j-1]-v[i-1]) + min(dp[i+1][j],dp[i][j-1]);

            }

        }

    }



    cout << dp[1][n] << "\n";

}



signed main()

{        

    jaldi     

    init();

    

    int t;

    // cin >> t;

    t=1;

    while(t--){

        solve();

    }

}