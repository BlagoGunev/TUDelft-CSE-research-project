//#pragma GCC optimize("Ofast")

//#pragma GCC target("avx,avx2,fma")

//#pragma GCC optimization ("unroll-loops")

//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>

#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <cmath>

#include <vector>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <queue>

#include <ctime>

#include <cassert>

#include <complex>

#include <string>

#include <cstring>

#include <chrono>

#include <random>

#include <bitset>

#include <stack>

#include <deque>

#include <iterator>

#include <tuple>

#include <iomanip>

#include <valarray>

#include <limits>

#include <sstream>

#include <fstream>

#include <cassert>

#include <functional>

#include <numeric>

#define in insert

#define pb push_back

#define mp make_pair

#define int long long

#define ll long long

#define fi first

#define double long double

#define se second

#define endl '\n'

#define pii pair<int,int>

#define pdd pair<double,double>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

#define mod 1000000007

#define MAXN  51

#define all(v) v.begin(),v.end()

using namespace std;

/*using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,

tree_order_statistics_node_update>

ordered_set;*/

int spf[MAXN];

int fac[MAXN];

int inv[MAXN];

int pp[MAXN];

void sieve()//sieve

{

   spf[1] = 1;

   for (int i=2; i<MAXN; i++)

       spf[i] = i;

   for (int i=4; i<MAXN; i+=2)

       spf[i] = 2;

   for (int i=3; i*i<MAXN; i+=2)

   {

       if (spf[i]==i)

       {

           for (int j=i*i; j<MAXN; j+=i)

               if (spf[j]==j)

                   spf[j]=i;

       }

   }

}//sieve ends

map<int,int> getfactor(int a)//factor prime

{

   map<int,int> m;

   while(a>1)

   {

       m[spf[a]]++;

       a/=spf[a];

   }

   return m;

}//prime factor ends

int power(int x,int y,int p)

{

   int res = 1;

   if (x == 0||y < 0)

       return 0;

    x = x%p;

   while (y > 0)

   {

       if (y & 1)

           res = (res*x)% p;

       y = y>>1;

       x = (x*x)%p;

   }

   return res;

}

int gcd(int a, int b)

{

   if (a == 0)

       return b;

   return gcd(b % a, a);

}

int inverse(int a, int p)

{

   return power(a, p-2, p);

}

int ncr(int n, int r, int p)

{

   if(r>n)

       return 0;

   return (fac[n]*inv[r] % p *

           inv[n-r] % p) % p;

}

void solve()

{

    int n;

    cin>>n;

    string s[n+1];

    for(int i=1;i<=n;i++)

        cin>>s[i];

    map<int,int> m[n+1];

    int tot[n+1]={0};

    for(int i=1;i<=n;i++)

    {

        int ct=0,mini=0;

        for(auto it:s[i])

        {

            ct+=(it=='(')-(it==')');

            tot[i]+=(it=='(')-(it==')');

            mini=min(mini,ct);

            if(ct<=mini)

                m[i][ct]++;

        }

    }

    int ans=0;

    int dp[(1<<n)];

    for(int mask=0;mask<(1<<n);mask++)

        dp[mask]=-1e18;

    dp[0]=0;

    for(int mask=0;mask<(1<<n);mask++)

    {

        int cur=0;

        for(int i=0;i<n;i++)

            if(mask&(1<<i))

                cur+=tot[i+1];

        ans=max(ans,dp[mask]);

        if(dp[mask]>=0)

        {

            for(int i=0;i<n;i++)

            {

                if(mask&(1<<i))

                    continue;

                if(m[i+1].size()&&m[i+1].begin()->fi+cur<0)

                {

                    ans=max(ans,dp[mask]+m[i+1][-cur]);

                    continue;

                }

                if(m[i+1].find(-cur)!=m[i+1].end())

                    dp[mask|(1<<i)]=max(dp[mask]+m[i+1][-cur],dp[mask|(1<<i)]);

                else dp[mask|(1<<i)]=max(dp[mask],dp[mask|(1<<i)]);

            }

        }

    }

    cout<<ans<<endl;

}

signed main()

{

    fast

    int test=1;

    //cin>>test;

    while(test--)

    {

        solve();

    }

}