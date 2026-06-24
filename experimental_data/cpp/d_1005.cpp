/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include<bits/stdc++.h>
#define ll          long long
#define pll         vector< pair<ll ,ll> >
#define vll         vector<ll>
#define vi          vector<int>
#define hell        1000000007
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define pb          push_back
#define F           first
#define S           second
#define mp          make_pair
#define all(v)      v.begin(), v.end()
#define lb          lower_bound  //value not less than(>=)
#define ub          upper_bound  //value greater than(>)
#define bs          binary_search
#define pcont(v)    for(auto it:v) cout<<it<<" ";cout<<endl
#define ret(x)      return cout << x,0;
#define pi          pair<ll,pair<ll,ll> >
#define endl        '\n'
ll const MAX = 1e5+5;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    ll n=s.length();

    ll ans=0;
    ll i=0;
    ll prev=0;
    ll d[3]={0};
    while(i<n)
    {
        ll temp[3]={0};
        rep(j,0,3)
        {
            if(d[j]==1)
            {
                temp[(j+(s[i]-'0'))%3]=1;
            }
        }
        d[(s[i]-'0')%3]=1;
        rep(j,0,3) if(temp[j]==1) d[j]=1;

        if(d[0]==1)
        {
            rep(j,0,3) d[j]=0;
            ans++;
        }
        i++;
    }
    cout << ans;
}