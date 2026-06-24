#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <algorithm>

using namespace std;
typedef int64_t T;
#define ll long long 
#define pb push_back
const int m = 1e9+7;

const int N = 2e5+10;

void solve(){

    // cout<<"h"<<endl;
    
    int n,k;
    cin>>n>>k;

    map<pair<int,int>,int> mp;

    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            temp.push_back(x);

            pair<int,int> p;
            p = {i,j};

            mp[p] = x;

        }

        v.push_back(temp);
    }

    ll op = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mp[{i,j}] != mp[{n-1-i,n-1-j}]){
                op++;
            }

        }
    }
    op = op/2;

    if(op<=k && n&1){
        cout<<"YES"<<endl;
    }else if(op<=k && n%2==0){
        if((k-op)&1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }

}

int main() {
    

    int t;
    cin >> t;
    while (t--) {
        solve();
          
    }
    return 0;
}

/*
bool cmp(vector<ll> &a,vector<ll> &b){
    if(a[0] != b[0]){
        if(a[0]<b[0]){
            return true;
        }else{
            return false;
        }
    }else{
        if(a[1]>b[1]){
            return true;
        }else{
            return false;
        }
    }
}

*/