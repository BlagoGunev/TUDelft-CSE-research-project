#include <bits/stdc++.h>

using namespace std;

#define ll long long



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll t, k, n;

    cin>>t;

    while (t--)

    {

        cin >>n;

        string s;

        cin>>s;

        ll tot_odd_at_odd=0;

        ll tot_eve_at_eve=0;

        for (ll i = 0; i < n; i++)

        {

            //cin>>s[i];

            if((s[i]-'0')%2==0 and (i+1)%2==0){

                tot_eve_at_eve++;

            }

            else if((s[i]-'0')%2!=0 and (i+1)%2!=0){

                tot_odd_at_odd++;

            }

        }

        if(n%2==0){

            if(tot_eve_at_eve>0){

                cout<<2<<"\n";

            }

            else{

                cout<<1<<"\n";

            }

        }        

        else{

            if(tot_odd_at_odd>0){

                cout<<1<<"\n";

            }

            else{

                cout<<2<<"\n";

            }

        }

    }

    return 0;

}