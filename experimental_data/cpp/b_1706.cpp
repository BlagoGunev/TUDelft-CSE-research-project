#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);cout.tie(0);

    int t; cin>>t;

    while(t--)

    {

        int n; cin>>n;

        int a[n];

        vector<vector<int>> v(n+1);

        for(int i=0;i<n;i++)

        {

            cin>>a[i];

            v[a[i]].push_back(i);

        }

        for(int i=1;i<=n;i++)

        {

            int cnt=1;

            if(v[i].size()<=1) cnt=v[i].size();

            else

            {

                for(int j=0;j+1<v[i].size();)

                {

                    for(int k=j+1;k<v[i].size();k++)

                    {

                        if(v[i][k]-v[i][j]==1 || (v[i][k]-v[i][j])%2==1)

                        {

                            cnt++;

                            j=k;

                            //cout<<"hi";

                            break;

                        }

                        j=k;

                    }

                }

            }

            cout<<cnt<<" ";

        }

        cout<<endl;

    }

}