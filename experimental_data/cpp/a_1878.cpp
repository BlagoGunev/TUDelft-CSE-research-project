#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;

        int x = 0;
        map<int, int>mpp;

        for(int i = 0; i < n; i++){
            cin >> x;
            mpp[x]++;
        }

        if(mpp.find(k) != mpp.end()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
        
    }

    return 0;
}