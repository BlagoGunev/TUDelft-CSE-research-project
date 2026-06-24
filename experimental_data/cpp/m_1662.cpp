// Mahfuz Anam

// Department of Computer Science and Engineering, Jahangirnagar University

// 49th Batch

// Life is a Rhapsody

// Truth Will Prevail



#pragma GCC Optimize ("Ofast")

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#include<bits/stdc++.h>

#define ll long long

#define lb lower_bound

#define ub upper_bound

#define N "\n"

#define pb push_back

#define pob pop_back

#define ff first

#define ss second

#define bb begin()

#define ee end()

#define pi acos(-1)

#define precision(x) fixed<<setprecision(x)

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace __gnu_pbds;

using namespace std;

void solve()

{

    ll n,m,r,w,i,j,x,mxr=0,mxw=0;

    cin>>n>>m;

    while(m--)

    {

        cin>>r>>w;

        mxr=max(mxr,r);

        mxw=max(mxw,w);

    }

    if((mxr+mxw)>n) cout<<"IMPOSSIBLE"<<N;

    else

    {

        n-=(mxr+mxw);

        while(mxr--) cout<<"R";

        while(mxw--) cout<<"W";

        while(n--) cout<<"R";

        cout<<N;

    }

}

int main()

{

    fastio

    ll i,t;

    cin>>t;

    for(i=1;i<=t;i++)

    {

        solve();

    }

}