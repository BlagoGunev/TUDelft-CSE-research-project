//clear adj and visited vector declared globally after each test case

//check for long long overflow   

//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;

//Incase of close mle change language to c++17 or c++14  

// #pragma GCC target ("avx2")  

// #pragma GCC optimization ("O3") 

// #pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>                

#include <ext/pb_ds/assoc_container.hpp>  

#define int long long   

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(dbl::max_digits10);

#define pb push_back 

#define mod 1000000007ll //998244353ll

#define lld long double

#define mii map<int, int> 

#define pii pair<int, int>

#define ll long long

#define ff first

#define ss second 

#define all(x) (x).begin(), (x).end()

#define rep(i,x,y) for(int i=x; i<y; i++)    

#define fill(a,b) memset(a, b, sizeof(a))

#define vi vector<int>

#define setbits(x) __builtin_popcountll(x)

#define print2d(dp,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}

typedef std::numeric_limits< double > dbl;

using namespace __gnu_pbds;

using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//member functions :

//1. order_of_key(k) : number of elements strictly lesser than k

//2. find_by_order(k) : k-th element in the set

const long long N=200005, INF=2000000000000000000;

lld pi=3.1415926535897932;

int lcm(int a, int b)

{

    int g=__gcd(a, b);

    return a/g*b;

}

int power(int a, int b, int p)

    {

        if(a==0)

        return 0;

        int res=1;

        a%=p;

        while(b>0)

        {

            if(b&1)

            res=(1ll*res*a)%p;

            b>>=1;

            a=(1ll*a*a)%p;

        }

        return res;

    }

    

int lis(vector<int> const& a) {

    int n = a.size();

    vector<int> d(n+1, INF);

    d[0] = -INF;



    for (int i = 0; i < n; i++) {

        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();

        if (d[j-1] <= a[i] && a[i] <= d[j])

            d[j] = a[i];

    }



    int ans = 0;

    for (int i = 0; i <= n; i++) {

        if (d[i] < INF)

            ans = i;

    }

    return ans;

}

int32_t main()

{

    IOS;

    int n, v;

    cin>>n>>v;

    int t[n], a[n];

    rep(i,0,n)

    cin>>t[i];

    rep(i,0,n)

    cin>>a[i];

    vector <pii> v1;

    rep(i,0,n)

    {

        if(t[i]*v>=abs(a[i]))

        v1.pb({(v*t[i])-a[i], (v*t[i])+a[i]});

    }

    int ans=0;

    {

	    sort(all(v1));

	    vi v2;

	    for(auto p:v1)

	    v2.pb(p.ss);

	    ans = max(lis(v2), ans);

	}

	{

	    sort(all(v1), [](pii& a, pii& b){

	    	if(a.ss!=b.ss) return a.ss<b.ss;

	    	return a.ff<b.ff;

	    });

	    vi v2;

	    for(auto p:v1)

	    v2.pb(p.ff);

	    ans = max(lis(v2), ans);

	}

	cout<<ans<<"\n";

}