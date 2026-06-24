#include<bits/stdc++.h>

using namespace std;

#define ll long long

class fenwik_tree

{

public:

    const static int bit_size=200009;

    ll bit[bit_size]={};

    int n;

    fenwik_tree(int x){n=x;}

    void add(int idx ,ll val)

    {

        while(idx<=n)

        {

            bit[idx]+=val;

            idx+=(idx&-idx);

        }

    }

    ll bit_num(int idx)

    {

        ll sum=0;

        while(idx>0)

        {

            sum+=bit[idx];

            idx-=(idx&-idx);

        }

        return sum;

    }

};

int main()

{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)

    {

        int n;cin>>n;

        ll s[n+1];

        fenwik_tree bit(n+1);

        for(int i=1;i<=n;i++)

        {

            cin>>s[i];

        }

        ll ans=0;

        for(int i=n;i>0;i--)

        {

            ans+=bit.bit_num(s[i]);

            bit.add(s[i],1);

        }

        cout<<ans<<'\n';

    }

    return 0;

}