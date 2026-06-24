#include<bits/stdc++.h>

using namespace std;

#define ll long long

#include<string>

ll mod=1e9+7;

ll help(ll m,ll n) 

{

    ll ans=0;

    for(ll bit=61;bit>=0;bit--)

    {

        if((m&(1LL<<bit))!=(n&(1LL<<bit)))

            break;

        else

            ans|=(m&(1LL<<bit));

    }

    return ans;

}

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll t=1;

    cin>>t;

    while(t--)

    {

        ll n;

        cin>>n;

        string s;

        cin>>s;

        int count0=0,count1=0;

        for(ll i=0;i<n-1;i++)

        {

            if(s[i]=='0')

            {

                count0++;

                cout<<(i+2-count0)<<" ";

                count1=0;

            }

            else

            {

                count1++;

                cout<<(i+2-count1)<<" ";

                count0=0;

            }

        }

        cout<<endl;

    }

}