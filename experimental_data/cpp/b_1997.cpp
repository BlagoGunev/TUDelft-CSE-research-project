#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define s(a) sort(a.begin(),a.end())
#define fi(n) for(ll i=0;i<n;i++)
#define fj(n) for(ll j=0;j<n;j++)
#define fab(a,b) for(ll i=a;i<b;i++)
#define vvi vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vi vector<ll>
#define vd vector<double>
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define minus cout<<"-1\n"
#define pb push_back
void solve()
{
    ll n;cin>>n;
    string a,b; cin>>a>>b;
    int ct=0;
    for(int i=1;i<n-1;i++)
    {
        if(a[i]=='.' && a[i-1]=='.' && a[i+1]=='.' && b[i-1]=='x' && b[i]=='.' && b[i+1]=='x') ct++;
        else if(b[i]=='.' && b[i-1]=='.' && b[i+1]=='.' && a[i-1]=='x' && a[i]=='.' && a[i+1]=='x') ct++;
    }
    cout<<ct<<endl;
    return;

}

int main()
{
    int t;cin>>t;
    while(t--)
    solve();
    
    return 0;
}