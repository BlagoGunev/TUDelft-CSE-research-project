#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main (){
    int n;cin>>n;int ans[n];
    for(int i=0;i<n;i++){
        int a;cin>>a;int arr[a];
        for(int j=0;j<a;j++){
            cin>>arr[j];
        }
        sort(arr,arr+a);
        bool flag=true;int mark;
        for(int j=0;j<a-1;j++){
            if(arr[j]==arr[j+1])flag=true;
            else {flag=false;mark=j;break;}
        }
        if (flag==true) {cout<<-1<<endl;continue;}
        
        vector<int>va;
        vector<int>vb;
        for(int j=0;j<mark+1;j++){
             va.push_back(arr[j]);
            }
        for(int j=mark+1;j<a;j++){
            vb.push_back(arr[j]);
            }
        cout<<va.size()<<" "<<vb.size()<<endl;
        for(int p=0;p<va.size();p++){
            cout<<va[p]<<" ";
        }
        cout<<endl;
        for(int p=0;p<vb.size();p++){
            cout<<vb[p]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}