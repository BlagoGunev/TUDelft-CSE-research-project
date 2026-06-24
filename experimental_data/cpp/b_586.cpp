#include<bits/stdc++.h>

using namespace std;

//ios::sync_with_stdio(false); cin.tie(NULL);

int a[55],b[55],c[55];



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(NULL);



    int n,ans=1e9;

    cin>>n;

    for(int i=2;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n-1;i++) cin>>b[i];

    for(int i=1;i<=n;i++) cin>>c[i];

    int sum=0;

    for(int i=2;i<=n;i++){

        sum+=a[i];

        a[i]=sum;

    }

    sum=0;

     for(int i=n-1;i>=1;i--){

         sum+=b[i];

        b[i]=sum;

    }

    for(int i=1;i<n;i++){

        for(int j=i+1;j<=n;j++){

            sum=a[i]+b[i]+c[i]+a[j]+b[j]+c[j];

            ans=min(ans,sum);

        }

    }

    cout<<ans;

    return 0;

}