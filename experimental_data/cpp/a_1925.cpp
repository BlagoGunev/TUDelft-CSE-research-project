#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t-->0){
    int n,k;
    cin>>n>>k;
   string init="abcdefghijklmnopqrstuvwxyz";
   string sub=init.substr(0,k);
   while(n-->0){
    cout<<sub;
   }
   cout<<endl;
    }
}