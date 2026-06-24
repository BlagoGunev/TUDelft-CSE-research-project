#include<bits/stdc++.h>

using namespace std;



#define ll long long int



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll T=1;

    cin>>T;

    while(T--)

    {

        ll n;

        cin>>n;

        ll od=0,ev=0;

        for(ll i = 0;i<n;i++)

        {

            ll x;

            cin>>x;

            if(x%2)

            {

                od++;

            }

            else

            {

                ev++;

            }

        }

        ll k = n/2;

        ll f = 0;

        for(ll i = 1;i<=od;i=i+2)

        {

            ll tod = od-i;

            ll tev = k-tod;

            ll rod = 2*tod;

            ll rev = 2*tev;

            if(rev>=0 && rev<=ev && rod>=0 && rod<=od)

            {

                f=1;

                break;

            }

            

        }

        if(f==0)

        {

            cout<<"Alice"<<endl;

        }

        else

        {

            cout<<"Bob"<<endl;

        }

    }

}