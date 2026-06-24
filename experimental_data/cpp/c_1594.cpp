#include <bits/stdc++.h>

using namespace std;

#define int long long int



void solve()

{

    //cout<<"--------------------------------"<<endl;

    int n; char x; string s; cin>>n>>x>>s;

    bool flag1=true,flag2=true;

    if(s[n-1]!=x){flag2=false;}

    for(int i=0;i<n-1;i++){

        if(s[i]!=x){flag1=false;break;}}



    if(flag1&& flag2){cout<<0<<endl;return;}



    bool fla=true;

    for(int i=1;i<=n;i++){

        fla=true;

        for(int j=i;j<=n;j+=i){

            if(s[j-1]!=x){fla=false;break;}}

        if(fla){

            cout<<1<<endl<<i<<endl;return;

        }

    }

    cout<<2<<endl<<n-1<<" "<<n<<endl;



}



int32_t main()

{

   ios_base::sync_with_stdio(false);

   int t; cin>>t;

   while(t--){solve();}

   //solve();

}