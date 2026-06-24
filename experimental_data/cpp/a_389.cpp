#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()

{

    ll i,j,k,l,m,n;

    while(cin>>n)

    {

        ll arr[101];

        for(i=0;i<n;i++)

        {

            cin>>arr[i];

        }

        sort(arr,arr+n);

        ll ans=arr[0];

        ll res;

        for(i=1;i<n;i++)

        {

            ans=__gcd(ans,arr[i]);

        }

        cout<<ans*n<<endl;

    }

    return 0;

}