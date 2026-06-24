#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            if(b[i]<a[i]){
                swap(a[i],b[i]);
            }
        }
        int max1=a[n-1],max2=b[n-1];
        sort(a,a+n);
        sort(b,b+n);
        if(a[n-1]==max1 && b[n-1]==max2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}