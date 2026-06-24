#include <bits/stdc++.h>
#define mod 1000000007
#define MOD 1000000007
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MAXN 100009 
#define pi 3.1415926535897932384626

using namespace std;

ll power(ll x, ll y) { ll ans = 1; x %= MOD; while (y) {if (y & 1)ans = (x * ans) % MOD; x = (x * x) % MOD; y >>= 1;} return ans;}
ll modInv(ll n) { return power(n, MOD - 2);}



void solve()
{
    ll n, i;
    cin>>n;

    string s, t;
    cin>>t>>s;

    ll ans=0;

    for(i=0; i<n; i++)
    {
        if(t[i]=='0')
        {
            if(s[i]=='1')
            {
                ans++;
                s[i]='0';
            }
        }
        else
        {
            int flag=0;
            if(i-1>=0)
            {
                if(s[i-1]=='1')
                {
                    ans++;
                    s[i-1]='0';
                    flag=1;
                }
            }
            if(flag==0)
            {
                if(i+1<n)
                {
                    if(s[i+1]=='1')
                    {
                        ans++;
                        s[i+1]='0';
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastio
    ll t=1; 
    cin>>t;

    while(t--)
    {
        solve();
    }
}