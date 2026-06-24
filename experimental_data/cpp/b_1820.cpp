#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        s+=s;
        int ones=0;
        int ans=0;
    for(int i=0;i<s.length();i++){
       if(s[i]=='1'){
        ones++;
        ans=max(ans,ones);
       }else{
        ones=0;
       }
    }
    if(ones/2==n){
        cout<<n*n<<endl;
        continue;
    }
    int res=0;
    int j=1;
    for(int i=ans;i>=ans/2;i--){
        res=max(i*j,res);
        j++;
    }
    cout<<res<<endl;
    }
}