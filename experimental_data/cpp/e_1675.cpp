/*

    Author - hArSh gOyAl

    Codeforces ID - harshgoyal178

    Codechef Id - harshgoyal178

*/

#include <bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>

// #include<ext/pb_ds/tree_policy.hpp>

 

#pragma GCC target ("avx2")

#pragma GCC optimize ("O3")

#pragma GCC optimize("Ofast")

// #pragma GCC optimize ("unroll-loops")

// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

// #pragma GCC target("avx,avx2,avx512,fma") 



// Macros

#define F first

#define S second

#define rep(i,n) for(int i=0; i<n; ++i)

#define sortv(v) sort(v.begin(), v.end())

#define rev(v) reverse(v.begin(), v.end())

#define pb push_back

#define mp make_pair

#define mod 1e9 + 7

#define MOD  998244353

#define mod2 1e8

#define sc(n) scanf("%d",&n)

#define sza(x) ((int)x.size())

#define scl(n) scanf("%lld",&n)

#define max(a,b) std::max(a,b)

#define min(a,b) std::min(a,b)





using namespace std;

// using namespace __gnu_pbds;

// using namespace std::chrono;



typedef vector<int> veci;

typedef vector<long long int> vecll;





// Aliases

using ll = long long;

using ull = unsigned long long;

using ld = long double;



// Constants

const ll INF = 2e18;

const double PI = 3.14159265358979;



// Functions



vector<int> sieve(ll n)

{

    vector<int> prime(n+1,1);

    for (int p = 2; p * p <= n; p++) {

        if (prime[p] == 1) {

            for (int i = p * p; i <= n; i += p)

                prime[i] = 0;

        }

    }

    return prime;

}



ll gcd(ll a, ll b) { 

    if (b == 0) { return a;} return gcd(b, a % b);

}



ll lcm(ll a, ll b) {

    return (a*b)/gcd(a,b);

}



bool check_prime(ll n) {

    if (n <= 1)

        return false;

    if (n <= 3)

        return true;

    if (n % 2 == 0 || n % 3 == 0)

        return false;

    for (int i = 5; i * i <= n; i = i + 6)

        if (n % i == 0 || n % (i + 2) == 0)

            return false;

    return true;

}



int binary_search(ll a[], int n, ll target)

{

    int start = 0;

    int end = n-1;

    while(start <= end) {

        int mid = start + ((end-start)/2);

        if(a[mid]==target)

        {

            return mid;

        }

        else if(a[mid]>target)

        {

            end = mid-1;

        }

        else

        {

            start = mid + 1;

        }

    }

    return -1;

}



void swap(int &x, int &y) {

    int temp = x; 

    x = y; 

    y = temp;

}



ll binpow(ll a, ll b) {

    ll res = 1;

    while (b > 0) {

        if (b & 1)

            res = (res * a);

        a = (a * a);

        b >>= 1;

    }

    return res;

}



ll factorial(ll n)

{

    ll ans = 1;

    for(int i=1; i<=n; ++i)

    {

        ans = ans*i;

    }

    return ans;

}



ll nCr(int n, int r)

{

    if(r>n)

    {

        return 0;

    }

    else if(r==0 || r==n)

    {

        return 1;

    }

    else

    {

        ll dp[n+1][r+1];

        for(int i=0; i<n; ++i)

        {

            for(int j=0; j<=min(i,r); ++j)

            {

                if(j==i || j==0)

                {

                    dp[i][j] = 1;

                }

                else

                {

                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

                }

            }

        }

        return dp[n][r];

    }

}



bool cmp(const pair<int,int> &p1, const pair<int,int> &p2)

{

    if(p1.F == p2.F)

    {

        return p1.S < p2.S;

    }

    return p1.F < p2.F;

}



struct DSU {

    int n;

    int p[26];

    void init(int size)

    {

        n = size;

        for(int i=0; i<n; ++i)

        {

            p[i] = i;

        }

    }

    int get(int x)

    {

        if(p[x]!=x)

        {

            p[x] = get(p[x]);

        }

        return p[x];

    }



    void union_set(int a, int b, map<int,int>& mp)

    {

        for(int i = a; i > b; --i)

        {

            if(mp[i]!=0)

            {

                i = get(i);

                b = get(b);

                mp[i]=0;

                if(i!=b)

                {

                    p[i] = b;

                }

            }

        }

    }

};



int closestToLeft(int a[], int n, int target)

{

    int ans = -1;

    int l = 0;

    int r = n-1;

    while(l <= r)

    {

        int mid = (l+r)/2;

        if(a[mid] <= target)

        {

            ans = mid;

            l = mid + 1;

        }

        else

        {

            r = mid - 1;

        }

    }

    return ans;

}



void solve() {

    int n;

    cin>>n;

    ll k;

    cin>>k;

    string s;

    cin>>s;

    char mx = 'a';

    rep(i,n)

    {

        if(s[i] - 'a' > k)

        {

            k -= mx - 'a';

            int ch = s[i] - k;

            for(char c = s[i]; c > ch; --c)

            {

                for(char &e: s)

                {

                    if(e==c)

                    {

                        e = char(c-1);

                    }

                }

            }

            break;

        }

        else

        {

            if(s[i] > mx)

            {

                mx = s[i];

            }

        }

    }

    

    for(char &e: s)

    {

        if(e <= mx)

        {

            e = 'a';

        }

    }

    

    cout<<s<<"\n";

}



int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0); cout.tie(0);

    int t = 1;

    cin>>t; // comment this line if number of test cases is not given as input

    for(int i=1; i<=t; ++i)

    {

        // cout<<"Case #"<<i<<": ";

        solve();

    }

}