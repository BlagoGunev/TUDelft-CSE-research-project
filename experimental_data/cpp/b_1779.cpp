#include<bits/stdc++.h>

#define ll long long

#define mod 998244353

#define fastread()(ios_base:: sync_with_stdio(false),cin.tie(NULL));

const int N=1e7+10;

using namespace std;

int main()

{

    fastread();

    ll t;

    cin>>t;

    while(t--)

    {

        ll n;

        cin>>n;

        if(n%2==1)

        {

            if(n==3) cout<<"NO"<<endl;

            else

            {

                cout<<"YES"<<endl;

                int k=n/2;

                for(int i=1; i<=n; i++)

                {

                    if(i%2==1) cout<<k-1<<" ";

                    else cout<<-k<<" ";

                }

                cout<<endl;

            }

        }

        else

        {

            cout<<"YES"<<endl;

            for(int i=1; i<=n; i++)

            {

                if(i%2==1) cout<<"5 ";

                else cout<<"-5 ";

            }

            cout<<endl;

        }

    }

}