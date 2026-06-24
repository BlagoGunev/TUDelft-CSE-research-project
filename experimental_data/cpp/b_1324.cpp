#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define mod 1000000007

int main(){

    ios_base::sync_with_stdio(false);   cout.tie(nullptr);  cin.tie(nullptr);

    int T=1; cin>>T;

    while(T--) {

       int n,mx=0; cin>>n;

       vector<int>v(n);

       vector<vector<int>>freq(5003);

       for(int i=0;i<n;i++){

           cin>>v[i];

           freq[v[i]].push_back(i+1);

           mx=max(mx,v[i]);

       }

       bool f=1;

       for(int i=1;i<=mx;i++){

           if(freq[i].size()>=3){f=0; break;}

           else if(freq[i].size()<=1)continue;

           else{

               if(freq[i][1]-freq[i][0]>1){f=0; break;}

           }

       }

       if(!f)cout<<"YES\n";

       else cout<<"NO\n";





    }

    return 0;

}