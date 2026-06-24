#include<bits/stdc++.h>

#define int long long

#define pb push_back

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);

using namespace std;



void sol()

{

    int n, cnt=0; cin>>n; int a[n], b[n], c[n];

    for (int i = 0; i < n; i++)

    {

        cin>>a[i]; b[i]=a[i];c[i]=a[i];

    }

    int ans[n][3];

    sort(c, c+n);

    for (int i = 0; i < n; i++)

    {

        int cn=0;

        for (int j = i; j < n; j++)

        {

            if(b[j]==c[i] && j==i) break;

            if(b[j]==c[i] && j!=i) 

            {

                cnt++;

                b[i]=c[i];

                for (int k = i; k < j; k++)

                {

                    b[k+1]=a[k];

                }

                ans[cnt-1][0]=i+1, ans[cnt-1][1]=j+1, ans[cnt-1][2] = j-i;

                for (int i = 0; i < n; i++)

                {

                    a[i]=b[i];

                }

                break;

            }

        }

        for (int i = 0; i < n; i++)

        {

            if(b[i]==c[i]) cn++;

        }

        if(cn==n) break;

    }

    cout<<cnt<<'\n';

    for (int i = 0; i < cnt; i++)

    {

        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<'\n';

    }

    

}



signed main()

{

    fastio()



    int t;

    cin>>t;

    // t=1;

    while(t--) sol();

    return 0;

}