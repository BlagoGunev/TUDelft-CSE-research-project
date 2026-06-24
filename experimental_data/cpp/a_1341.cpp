//This is coded by VIDYARTH GS

#include <iostream> 

#include <complex>

#include <queue>

#include <set>

#include <limits.h>

#include <unordered_set>

#include <list>

#include <chrono>

#include <random>

#include <iostream>

#include <algorithm>

#include <cmath>

#include <string>

#include <vector>

#include <map>

#include <unordered_map>

#include <stack>

#include <iomanip>

#include <fstream>

#ifndef ONLINE_JUDGE

#define debug(x) cerr<<#x<<" "<<x<<"\n";

#else

#define debug(x)

#endif



using namespace std;

 

typedef long long ll;

typedef long double ld;

typedef pair<int,int> p32;

typedef pair<ll,ll> p64;

typedef pair<double,double> pdd;

typedef vector<ll> v64;

typedef vector<int> v32;

typedef vector<vector<int> > vv32;

typedef vector<vector<ll> > vv64;

typedef vector<vector<p64> > vvp64;

typedef vector<p64> vp64;

typedef vector<p32> vp32;

typedef map<int,int> mii;

typedef map<int,v32> miv;

ll MOD = 998244353;

int INF = INT32_MAX;

ll INF64 = INT64_MAX;

double eps = 1e-12;

#define rep(i,e) for(ll i = 0; i < e; i++)

#define repFR(i,s,e) for(ll i = s; i < e; i++)

#define repR(i,s) for(ll i = s; i >= 0; i--)

#define repRR(i,s,e) for(ll i = s; i >= e; i--)

#define ln "\n"

#define dbg(x) cout<<#x<<" = "<<x<<ln

#define mp make_pair

#define pb push_back

#define ff first

#define ss second

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define all(x) (x).begin(), (x).end()

#define sz(x) ((ll)(x).size())

 



void solve(){

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

    int n,a,b,c,d;

    cin>>n>>a>>b>>c>>d;

    int aa = n*(a-b);

    if(aa <= c-d){

        int k = ceil((c-d-aa)/float(n));

        if((a-b+k) <= (a+b)){

            cout<<"Yes\n";

            return;

        }

        else{

            cout<<"No\n";

            return;

        }

    }

    if(aa>=c-d && aa<=c+d){

        cout<<"Yes\n";

        return;

    }

    else{

        cout<<"No\n";

        return;

    }



    

}

int main()

{

#ifndef ONLINE_JUDGE

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

#endif

#ifndef ONLINE_JUDGE

    freopen("Error.txt","w",stderr);

#endif

    fast_cin();

    ll t;

    cin >> t;

    for(int it=1;it<=t;it++) {

        //cout << "Case #" << it+1 << ": ";

        solve();

    }

    return 0;

}