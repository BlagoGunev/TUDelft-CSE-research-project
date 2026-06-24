#include <cmath>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
       bool arr[4]={};
    int n;
    cin >> n;
    
    while (n--) {
        int x, y;
        cin >> x >> y;
        
        if (x > 0) {
            arr[0] = true;
        }
        if (x < 0) {
            arr[1] = true;
        }
        if (y > 0) {
            arr[2] = true;
        }
        if (y < 0) {
            arr[3] = true;
        }
    }
    int c=0;
    for(int i=0;i<4;i++){
        if(arr[i]==true){
            c++;
        }
    }
    if(c==4){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}
    return 0;
}