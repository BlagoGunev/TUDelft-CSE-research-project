#include<bits/stdc++.h>

#define int long long

using namespace std;



void solve()

{

    int a,b;

    cin>>a>>b;

    int arr[a][b];

    for (int i=0;i<a;i++) for (int j=0;j<b;j++) cin>>arr[i][j];

    int sum=0, neg=0;int m=INT_MAX;

    for (int i=0;i<a;i++)

    {

        for (int j=0;j<b;j++)

        {

            if (arr[i][j]<0)

            {

                neg++;

                arr[i][j]*=-1;

            }

            sum+=arr[i][j];

            m=min(m,arr[i][j]);

        }

    }

    if (neg%2==0) cout<<sum<<endl;

    else cout<<sum-2*m<<endl;

}



int32_t main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int T;

    cin>>T;

    while(T--)

    {

        solve();

    }

    return 0;

}