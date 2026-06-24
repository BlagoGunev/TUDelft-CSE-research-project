#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include <cstdlib>
#include<math.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define fi first
#define se second
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mp make_pair
ll min(ll a,ll b)
{
    if(a<b)
    return a;
    return b;
}
int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll i,j,m=INT_MAX;
    for(j=0;j<n-3;j++)
    {
                ll a=abs(s[j]-'A');
                ll b=abs(s[j+1]-'C');
                ll c=abs(s[j+2]-'T');
                ll d=abs(s[j+3]-'G');
                ll x=min(a,26-a)+min(b,26-b)+min(c,26-c)+min(d,26-d);
                if(x<m)
                m=x;
                //cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    }
    cout<<m;
}