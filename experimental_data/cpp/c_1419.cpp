#include <bits/stdc++.h>

#define int long long

#define endl '\n'

using namespace std;

void solve()

{

    int n,x;cin>>n>>x;

    int a[n],f=0,sum=0,q=0;

    for(int i=0;i<n;i++)

    {

        cin>>a[i];

        f+=(a[i]!=x);

        sum+=x-a[i];

        q|=(a[i]==x);

    }

    if(f==0)cout<<0<<endl;else

    if(sum==0||q)cout<<1<<endl;

    else cout<<2<<endl;

}

int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);cout.tie(nullptr);

    int ut=1;

    cin>>ut;

    while(ut--)solve();

}