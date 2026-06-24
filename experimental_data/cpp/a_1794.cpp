#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void solve(){
    int n;cin>>n;
    string s,pos;
    int find=0;
    for(int i=1;i<=2*n-2;i++){
        cin>>s;
        if(s.length()==n-1){
            if(!find){
                reverse(s.begin(),s.end());
                pos=s;
                find=1;
            }
            else {
                if(pos != s)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}