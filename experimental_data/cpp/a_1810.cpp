#include<bits/stdc++.h>
#include<string>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define vi vector<int>v;
#define vpiin vector<pair<int,int>>v(n);
#define vf(i) v[i].first
#define vs(i) v[i].second
#define vvi vector<vector<int>>v;

string bin(ll n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

void pv(vector<ll>v)
{
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
void inline yes()
{
    cout<<"YES"<<endl;
}
void inline no()
{
    cout<<"NO"<<endl;
}

ll lcm(ll a, ll b)
{
    return (a*b)/__gcd(a,b);
}
int main()
{
    int tc;
    cin>>tc;
    rep(i,0,tc)
    { 
        ll n;
        cin>>n;
        ll a[n];
        map<ll,ll>mp;
        rep(j,0,n){
            cin>>a[j];
            if(a[j]<=n)mp[a[j]]=j+1;
        }
        bool f=0;
        for(auto i:mp)
        {
            if(i.second>=i.first)
            {
                //cout<<i.first<<" "<<i.second<<endl;
                yes();
                f=1;
                break;
            }
        }
        if(!f)no();

    }
    
}