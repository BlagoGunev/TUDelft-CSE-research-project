#include<iostream>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string ans;
        char c=s[0];
        int i=1;
        while(i<s.length()){
            if(s[i]==c){
                ans=ans+c;
                c=s[i+1];
                i+=2;
            }else{
                i++;
            }
        }
        cout<<ans<<endl;
    }
}