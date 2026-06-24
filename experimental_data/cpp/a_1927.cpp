#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int a=-1,b=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(c==0 && s[i]=='B')a=i,c=1;
            else if(s[i]=='B')b=i;
        }
        if(a==-1 && b==0)cout<<0<<endl;
        else if(b==0)cout<<1<<endl;
        else cout<<b-a+1<<endl;
    }
}