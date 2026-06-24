#include<bits/stdc++.h>
using namespace std;
#define int long long int
void h(){
    string s;cin>>s;
    vector<int> vis(26,0);
    vis[0]=1;
    for(int i=0;i<s.size();i++){
        if(!vis[s[i]-'a']){cout<<"NO"<<endl;return;}
        else{
            int x=s[i]-'a';
            vis[(x+1)%26]=1;
        }
    }
    cout<<"YES"<<endl;
}
signed main(){
    // int t;cin>>t;
    // while(t--){
        h();
    // }
}