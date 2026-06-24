#include <bits/stdc++.h>

#define int long long

#define endl '\n'

using namespace std;

int n,k,a[200005],b[200005];

bool f(int mid)

{

    for(int i=1;i<=n;i++)

    {

        if(a[i]>=mid)b[i]=1;

        else b[i]=-1;

        b[i]+=b[i-1];

    }

    int mn=0,mx=b[k];

    for(int i=k;i<=n;i++)

    {

        mn=min(mn,b[i-k]);

        mx=max(mx,b[i]-mn);

    }

    return mx>0;

}

void solve()

{

    cin>>n>>k;

    for(int i=1;i<=n;i++)cin>>a[i];

    int ans=0;

    for(int i=18;i>=0;i--)

    {

        if(f(ans|(1<<i)))ans|=(1<<i);

    }

    cout<<ans;

}

int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);cout.tie(nullptr);

    int ut=1;

//    cin>>ut;

    while(ut--)solve();

}