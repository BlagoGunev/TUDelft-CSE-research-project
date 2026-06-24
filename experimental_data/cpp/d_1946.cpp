#include <bits/stdc++.h>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
//typedef double db;
#define ss second
//#define int ll
#define ff first
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define vl vector<ll>
#define pll pair<ll,ll>
#define vll vector<pll>
#define vd vector<db>
#define pdd  pair<db,db>
#define vdd  vector<pdd>
#define mll map <ll,ll>
#define sl set <ll>
#define sll set <pll>
#define f(i,j,k,l) for(ll i=j;i<k;i+=l)
#define fj(j,m) for(auto j=m.begin();j!=m.end();j++)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define endl "\n"
const db pi=3.14159265359;
const int mod = 1e9+7;
const db EPS = 0.000000001; // 1 e -9
const ll inf = (ll)1e18;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}

int run_case()
{
    ll  u,i,r,y,h,z,e,x,n,j,l,k,p,q,w;
    cin >> k >> n ;
    ll a[k];
    f(i,0,k,1)
    {
        cin >> a[i];
    }
    l=-1;
    f(i,0,30,1)
    {
        if (n & (1<<i))
        {
            p=n;
            p&=(1<<30)-1-(1<<i);
            p|=(1<<i)-1;
            r=0;
            q=0;
            f(j,0,k,1)
            {
                r^=a[j];
                if ((r | p)==p)
                {
                    r=0;
                    q++;
                }
            }
            if (!r)
            {
                l=max(l,q);
            }
        }
    }
    p=n;
    r=0;
    q=0;
    f(j,0,k,1)
    {
        r^=a[j];
        if ((r | p)==p)
        {
            r=0;
            q++;
        }
    }
    if (!r)
    {
        l=max(l,q);
    }
    cout << l << endl;
    return 0;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;cin>>t;
    while(t--){
        run_case();
    }
    return 0;
}