#include<bits/stdc++.h>
using namespace std  ;
int main( ) {
    int t;cin >> t;
    while(t--){
        int n, k;
        cin >>n  >> k;
        string sol = "" ;
        for(int i=0;i<n;i++) {
            sol += (char)(i%k + 'a') ;
        }
        cout << sol << '\n' ;
    }
    return 0;
}