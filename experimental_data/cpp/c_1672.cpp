#include<bits/stdc++.h>

using namespace std;

typedef long long int LL;

typedef unsigned long long int ULL;

#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#else

#define debug(x)

#endif

void _print(LL t) {cerr << t;}

void _print(int t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(long double t) {cerr << t;}

void _print(double t) {cerr << t;}

void _print(unsigned long long t) {cerr << t;}

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

void answer(){

    LL n,s=-1,e=-1;

    cin>>n;

    vector<LL> v(n);

    for(LL i=0;i<n;++i) cin>>v[i];

    for(LL i=0;i<n-1;++i){

      if(v[i]==v[i+1]){

        if(s==-1){

            s=i;

        }

        e=i;

      }

    }

    if(s==e){

        cout<<"0\n";

        return;

    }

    LL l=1;

    cout<<max(l,e-s-1)<<"\n";

}

int main()

{

    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("error.txt", "w", stderr);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);

    cin.tie(NULL),cout.tie(NULL);

    LL ARITRASEN=1;

    cin>>ARITRASEN;

    while(ARITRASEN--)

    {

    answer();

    /*if(answer()) cout<<"YES\n";

    else cout<<"NO\n";*/

    }

    return 0;

}