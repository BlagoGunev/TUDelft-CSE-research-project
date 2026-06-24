#include <bits/stdc++.h>

using namespace std;



#define ll long long

#define ld long double

#define fr(i,a,b) for(ll i=a;i<b;i++)

#define frd(i,a,b) for(ll i=b-1;i>=a;i--)

#define pb push_back

#define ppb pop_back

#define ff first

#define ss second

#define pll pair<ll,ll>

#define mp make_pair

#define m1 1000000007

#define m2 998244353



#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#else

#define debug(x)

#endif



void _print(ll t) {cerr << t;}

void _print(int t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(double t) {cerr << t;}



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



void init_code(){

    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE

}

 

void solve() {

    int n;

    cin>>n;

    int mnn=INT_MAX;

    vector<int> v(n);

    vector<int> v1;

    fr(i,0,n){

        cin>>v[i];

        if(v[i]<mnn) mnn=v[i];

    }

    for(int i=0;i<n;i++){

        if(v[i]>=2*mnn) v1.pb(v[i]);

    }

    int cnt=0;

    for(int i=0;i<v1.size();i++){

        int div=v1[i]/(2*mnn-1);



        if(v1[i]%(2*mnn-1)==0){

            cnt+=(div-1);

        }

        else{

            cnt+=(div);

        }

    }

    cout<<cnt<<endl;

    





 

 

 

}

 

int main() {

 

#ifndef ONLINE_JUDGE

  freopen("Error.txt","w",stderr);

#endif

 

init_code();

ios_base::sync_with_stdio(false);

cin.tie(0);cout.tie(0);

    ll tc;

    tc=1;

    cin>>tc;

    while(tc--){

        solve();

    }

return 0;

}