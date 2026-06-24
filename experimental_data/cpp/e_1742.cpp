#include <bits/stdc++.h>

using namespace std;



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t;

    cin>>t;

    while(t--)

    {

        long long n,q,arr[200005],p[200005]={};

        cin>>n>>q; int max=0;

        for(int i=1;i<=n;i++)

        {

            cin>>arr[i];

               p[i] = p[i-1] + arr[i];

        if (arr[i] > max ) max = arr[i];

        else if (max > arr[i]) arr[i] = max;

        }

        while(q--)

        {

          long long k;

         cin >> k;

         long long ans ;

            int x = upper_bound(arr , arr+n+1 , k) - arr - 1;

            ans = p[x];

         cout << ans << ' ';

        }

        cout<<"\n";

    }



    return 0;

}