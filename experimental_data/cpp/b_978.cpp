#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char s[1000];
    int i,n;
    cin>>n;
    cin>>s;
    int sum=0,ans=0;
    for(i=0;i<n;i++){
        if(s[i]!='x') sum=0;
        else{
           if(sum<2) sum++;
           else ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}