#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#define ll long long









void solve(){

    

   int n; cin>>n;

   string s; cin>>s;

   

   int cnt{0};

   for (int i{0}; i<n; ++i){

       if (s[i]=='Q') cnt++;

       else if (cnt) cnt--;

   }

   if(cnt) cout<<"No"<<endl;

   else cout<<"Yes"<<endl;

    

   

}



int main() {

    FAST_IO;

    int t; cin>>t;

    while(t--){

        solve();

        

    }

    

    

     

    

    

    

    

    

    

    return 0;

}