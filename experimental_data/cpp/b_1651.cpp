#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t = 0;
    cin>>t;
    while(t--){
        long long n =0;
        cin>>n;
        long long p = 0;

        vector<long long> v;
        for(long long i=0; i<n; i++){
            if(pow(3,i) <1e9){
                v.push_back(pow(3, i));
                p++;
            }
        }
       if(p==n){
           cout << "YES\n";
           for(long long i=0; i<n; i++){
               cout << v[i] << " ";
               cout << endl;
           }
       }
       else{
           cout << "NO\n";
       }
        
        
    }
}