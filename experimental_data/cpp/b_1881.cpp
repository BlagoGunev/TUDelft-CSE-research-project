#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        bool flag= false;
        int mini= min({a,b,c});
        if(a%mini ==0 && b%mini==0 && c% mini==0){
           if((a/mini+b/mini+c/mini)/2 + (a/mini+b/mini+c/mini)%2  <=3){
                flag = true;
           } 
        }
        if(flag==true){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}