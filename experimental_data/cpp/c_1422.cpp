#include <bits/stdc++.h>

//#include <sys/resource.h>

#define ll long long

using namespace std;



// #pragma GCC optimize("O3,unroll-loops")

// #pragma GCC target("avx2")

const ll mod=1000000007;



#ifndef ONLINE_JUDGE

    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#else

    #define debug(x)

#endif



void _print(int t) {cerr << t;}

void _print(ll t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(long double t) {cerr << t;}

void _print(unsigned long long t) {cerr << t;}



template <class T, class V> void _print(pair <T, V> p);

template <class T> void _print(vector <T> v);

template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);

template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



ll power(ll base,ll expo)

{

    ll ans=1;

    while(expo>0)

    {

        if(expo%2==1)

        {

            ans*=base;

            ans=(ans)%mod;

            expo--;

        }

        else

        {

            base*=base;

            base=(base)%mod;

            expo/=2;

        }

    }

    return ans;

}

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    // rlimit R;

    // getrlimit(RLIMIT_STACK, &R);

    // R.rlim_cur = R.rlim_max;

    // setrlimit(RLIMIT_STACK, &R);

    // freopen("i_d.txt", "r", stdin);

    // freopen("o_d.txt", "w", stdout);

    #ifndef ONLINE_JUDGE

        freopen("Debug_outputs.txt", "w", stderr);

    #endif

    ll t,n,num,m,k;

    t=1;

    // cin>>t;

    while(t--)

    {

        string s;

        cin>>s;

        n=s.size();

        vector<ll> p(n+1,0);

        for(ll i=0;i<n;i++)

        {

            p[i+1]=p[i]+(s[i]-'0');

        }

        ll ans=0ll,carry=0ll;

        ll mm[n+1];

        for(ll i=n-1;i>=1;i--)

        {

            mm[i]=((n-i) * p[i]) + (((((i)*(i-1))/2ll)+i) * (s[i]-'0') );

            if(mm[i]>=mod) mm[i]%=mod;

            // cout<<mm[i]<<" ";

        }

        for(ll i=1;i<n;i++)

        {

            ans+=(power(10ll,n-i-1)*mm[i]%mod);

            if(ans>=mod) ans%=mod;

        }

        cout<<ans<<'\n';



    }

    return 0;   

}



// 12345 -> 1345 + 145 + 15 + 1245 + 125 + 1235 + 5 + 2345 + 345 + 45 = 10

// 12345 -> 2345 = 1