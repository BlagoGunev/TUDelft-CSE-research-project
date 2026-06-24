//IN THE NAME OF GOD
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#define  pb push_back
#define  S second
#define  F first
#define ra ragham
#define ll long long
using namespace std;
typedef pair<ll,ll> pii ;
typedef pair<char,char> cii ;
//setprecision(8)
//ios_base::sync_with_stdio(false);
//ll a[1100];
ll minn = 1000000000 ;
ll maxx = -10000000 ;
int main()
{
ll n , w ;
cin >> n >> w;
ll s= 0 ;
for(ll y=  0 ;y < n ; y++)
{
    ll i ;
    cin >> i ;
    s+=i;
    minn = min(minn , s);
    maxx = max(maxx , s) ;
}
if(minn > 0)
    minn = 0 ;
if(maxx < 0 )
    maxx = 0 ;
minn *= (-1);
maxx = w-(maxx);;
ll i = maxx-minn+1;
if(i < 0)
    i = 0;
cout<<i;

}