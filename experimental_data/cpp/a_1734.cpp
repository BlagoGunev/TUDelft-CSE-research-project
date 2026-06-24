#include <bits/stdc++.h>

using namespace std;

#define int long long 

#define endl "\n"

#define mod 1000000007

typedef pair<int, int> pairs;



int gcd(int a, int b)

{

    return b == 0 ? a : gcd(b, a % b);   

}



void solve()

{

    int n;cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++){cin>>v[i];}

    sort(v.begin(),v.end());

    int ans=INT_MAX;

    for(int i=0;i<n-2;i++){

        int temp=abs(v[i+1]-v[i])+abs(v[i+2]-v[i]);

        ans=min(ans,temp);

        temp=abs(v[i+1]-v[i+2])+abs(v[i+2]-v[i]);

        ans=min(ans,temp);

        temp=abs(v[i+1]-v[i])+abs(v[i+2]-v[i+1]);

        ans=min(ans,temp);

    }

    cout<<ans<<endl;

}

signed main(){

    int t=1;

    cin>>t;

    while(t--){

        solve();

    }

}