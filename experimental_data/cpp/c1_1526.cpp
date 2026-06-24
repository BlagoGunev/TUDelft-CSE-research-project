#include <bits/stdc++.h>

#define int long long int

#define pb push_back

#define endl "\n"

#define ff first

#define ss second

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);

 

using namespace std;

 

signed main()

{

    fastio()

    

    int n;

    cin >> n;

    

    int a[n];

    for(int i=0;i<n;i++) cin >> a[i];

    

    vector<int> prev(n+1,-1);

    prev[1]=max(prev[1],a[0]),prev[0]=0;

    for(int i=1;i<n;i++)

    {

        vector<int> cur(n+1,-1);

        cur[0]=0;

        for(int j=0;j<=i+1;j++)

        {

            if(j==0) cur[j]=max(a[i],cur[j]);

            else

            {

                cur[j]=max(cur[j],prev[j]);

                if(prev[j-1]>=0) cur[j]=max(cur[j],prev[j-1]+a[i]);

            }

        }

        prev=cur;

    }

    

    for(int k=n;k>=0;k--)

    {

        if(prev[k]>=0)

        {

            cout << k;

            break;

        }

    }



    return 0;

}