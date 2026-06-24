#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define ll long long
#define ld long double
#define rep(i, a, b) for (long long i = a; i <= b; i++)
#define mod 998244353int
#define INF 1e18
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define aint(x) (x).begin (), (x).end ()
#define sz(x) (long long) (x).size ()
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())
#define rank rnk
#define log lg
#define fast                                                                  \
    ios_base::sync_with_stdio (false);                                        \
    cin.tie (NULL);                                                           \
    cout.tie (NULL)
    
using namespace std;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
    
int inv(int x, int m)
{
    return binpow(x,m-2,m);
}
    
int absl(int x)
{
    return x>0?x:-x;
}

// typedef unsigned long long uint;
// struct FastMod {
//     uint b, m;
//     FastMod(uint b) : b(b), m(-1ULL / b) {}
//     uint reduce(uint a) { // a % b + (0 or b)
//     return a - (uint)((__uint128_t(m) * a) >> 64) * b;
//     }
// };

int fast_mod(const int input, const int ceil) {
    // apply the modulo operator only when needed
    // (i.e. when the input is greater than the ceiling)
    return input >= ceil ? input % ceil : input;
    // NB: the assumption here is that the numbers are positive
}

signed main ()
{
    fast;   

    int tst=1;
    // cin>>tst;

    while(tst--)
    {
        int n,k,div;
        cin>>n>>k>>div;

        int ans=0;

        rep(pos,1,n)
        {
            rep(dig,0,k-1)
            {
                vector <vector<int>> dp(n, vector<int>(k));
                dp[0][0]=1;

                rep(i,1,pos-1)
                {
                    rep(cv,0,k-1)
                    if(fast_mod(2*cv,k)!=fast_mod(2*dig,k))
                    rep(sum,0,k-1)
                    {
                        int nexti=fast_mod(sum+cv,k);
                        dp[i][nexti]=fast_mod(dp[i-1][sum]+dp[i][nexti], div);
                    }
                }

                rep(i,pos,n-1)
                {
                    rep(cv,0,k-1)
                    rep(sum,0,k-1)
                    {
                        int nexti=fast_mod(sum+cv,k);
                        dp[i][nexti]=fast_mod(dp[i-1][sum]+dp[i][nexti], div);
                    }
                }

                ans=fast_mod(ans+dp[n-1][dig],div);
            }
        }

        cout<<ans;
    }

    return 0;
}