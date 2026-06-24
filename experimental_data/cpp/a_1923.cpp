#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
#define ll long long
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
long long int mod = 1e9+7;
const int N = 1e6+7;
vector<bool>isprime(N, true);

ll bin_expo(ll a, ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if(b & 1)
        {
            ans = ((ans % mod) * (a % mod)) % mod;
            b--;
        }
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return ans % mod;
}

void sort(vector<ll>&v)
{
    sort(v.begin(), v.end());
}

void rsort(vector<ll>&v)
{
    sort(v.begin(), v.end(), greater<int>());
}
ll mul(ll a, ll b)
{
    return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

ll sub(ll a, ll b)
{
    return ((a % mod) - (b % mod)) % mod;
}

ll lcm(ll a, ll b)
{
    return ((a * b) / (__gcd(a,b)));
}

void sieve_of_eratosthenes()
{
    isprime[0] = isprime[1] = false;
    for(int i = 2; i<=N; i++)
    {
        if(isprime[i] == true)
        {
            for(int j = 2*i; j<=N; j+=i)
            {
                isprime[j] = false;
            }
        }
    }
}

void print(vector<ll>&v)
{
    for(auto it : v) cout<<it<<' ';
    cout<<endl;
}

bool ispal(string s)
{
    if(s.size() == 1) return true;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] != s[s.size()-i-1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(int i = 0; i<n; i++)
        {
            cin>>v[i];
        }
        ll last = -1, first = -1;
        for(int i = n-1; i>=0; i--)
        {
            if(v[i] == 1)
            {
                if(last == -1) last = i;
                first = i;
            }
        }
        if(last == -1)
        {
            cout<<0<<endl;
            continue;
        }
        ll ct = 0;
        for(int i = first; i<=last; i++)
        {
            if(v[i] == 0) ct++; 
        }
        cout<<ct<<endl;
    }

    return 0;
}