#include<bits/stdc++.h>

#define int long long

using namespace std;



void solve()

{

    int a,b;

    cin>>a>>b;

    int arr[a];

    int flag=0;

    for (int i=0;i<a;i++) cin>>arr[i];

    for (int i=0;i<a;i++)

    {

        if (arr[i]<(b+1)/2) cout<<0<<" ";

        else if (arr[i]==b/2)

        {

            cout<<flag<<" ";

            (flag==0)?flag=1:flag=0;

        }

        else cout<<1<<" ";

    }

    cout<<endl;

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