#include <iostream>
#include <bits/stdc++.h>
#define Kirlos ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
#define pb(k) push_back(k)
#define fi first
#define se second
#define endl '\n'
#define mp(x,y) make_pair(x,y)
#define MOD 998244353
#define all(x) x.begin(), x.end()
#define PI acos(-1)
#define sin(x) sin((x)*PI/180)
#define cos(x) cos((x)*PI/180)
#define tan(x) tan((x)*PI/180)
#define Ones(x) __builtin_popcountll(x)

using namespace std;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>vec;
    ll num=1;
    while(vec.size()!=n)
    {
        cout<<num<<" ";
        vec.pb(num);
        num+=2;
    }
    cout<<endl;
}

int main()
{
    Kirlos
    ll t;
    //t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}