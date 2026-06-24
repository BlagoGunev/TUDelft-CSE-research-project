#include <bits/stdc++.h>

using namespace std;



#define ll                  long long

#define PI                  3.1415926535897932384626

#define MOD                 1000000007

#define vi                  vector<int>

#define vll                 vector<long long>

#define vb                  vector<bool>

#define vs                  vector<string>

#define vvi                 vector<vector<int> >

#define pii                 pair<int,int>

#define pll                 pair<ll,ll>

#define vpii                vector<pair<int, int> >

#define vpll                vector<pair<ll,ll> >

#define pb                  push_back

#define mp                  make_pair

#define fastread()          (ios_base:: sync_with_stdio(false),cin.tie(NULL));













int main()

{

    fastread() 

    

    

    ll t;

    cin>>t;

    while(t--)

    {

        ll a[3];

        for(int i=0;i<3;i++)

        cin>>a[i];

        

        ll ans=0;

        for(int i=0;i<3;i++)

        {

            if(a[i]>0)

            {

                ans++;

                a[i]--;

            }

        }

        

        sort(a,a+3,greater<int>());

        if(a[0]>0 and a[1]>0)

        {

            ans++;

            a[0]--;

            a[1]--;

        }

        

        if(a[0]>0 and a[2]>0)

        {

            ans++;

            a[0]--;

            a[2]--;

        }

        

        if(a[1]>0 and a[2]>0)

        {

            ans++;

            a[1]--;

            a[2]--;

        }

        

        if(a[0]>0 and a[1]>0 and a[2]>0)

        ans++;

        

        cout<<ans<<endl;

        

        

        

        

        

        

        

        

        

        

    }

  

    

   

   

    return 0;

}