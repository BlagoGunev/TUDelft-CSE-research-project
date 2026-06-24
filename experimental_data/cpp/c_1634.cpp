#include<bits/stdc++.h>

using namespace std;

using ll = long long int;

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);cout.tie(0);

    ll t;cin>>t;

    while(t--)

    {

        ll n,m;cin>>n>>m;

        //vector<vector<ll>> v(n, vector<ll>(m, 0));

        if(n%2==0)

        {

            ll odd = 1, even = 2;

            cout<<"YES"<<endl;

            for(ll i=0;i<n;i++)

            {

                for(ll j=0;j<m;j++)

                {

                    if(i%2)

                    {

                        cout<<odd<<" ";

                        odd+=2;

                    }

                    else

                    {

                        cout<<even<<" ";

                        even+=2;

                    }

                }

                cout<<endl;

            }

        }

        else if(n%2 && m==1)

        {

            cout<<"YES"<<endl;

            for(ll i=0;i<n;i++)

                cout<<i+1<<endl;

        }

        else

            cout<<"NO"<<endl;

    }   

}