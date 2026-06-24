#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll long long int

#define dbg(a,b,c,d) cerr<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;

#define debug cerr<<"Error Found"<<endl;

#define mem(a,b) memset(a,b,sizeof(a))

#define endl "\n"

#define INF 1e18

#define w(t) cin>>t;while(t--)

#define kill(a) {cout<<a<<endl;continue;}

#define pi  2 * acos(0.0)

#define lcm(a, b) (a/__gcd(a,b))*b

int t,ans=0,tot=0;

const int mxn=2e5+2,mod=1e9+7;



signed main()

{

    //fast;

    //w(t)

   // {

        ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e17;

        string s,sr,sa,ss;

        bool f=false,ff=true;

        cin>>n;int ar[n];

        for(i=0;i<n;i++)cin>>ar[i];

        for(i=0;i<n;i++)

        {

            sm=0,cn=0,cn1=0;

            for(j=i-1;j>=0;j--)

            {

                a=cn+1;

                a=(a+ar[j]-1)/ar[j];

                sm+=a;

                cn=a*ar[j];

            }

            for(j=i+1;j<n;j++)

            {

                a=cn1+1;

                a=(a+ar[j]-1)/ar[j];

                sm+=a;

                cn1=a*ar[j];

            }

            //dbg(cn,cn1,sm,mn);

            mn=min(mn,sm);

        }

        cout<<mn<<endl;

   // }

}