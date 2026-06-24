#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n; 

        cin >> n;

        vector<int> a(n + 2, 0);

        for(int i = 1; i <= n; i++) cin >> a[i];

        a[n + 1] = 1440;

        int cnt = 0;

        for(int i = 0; i < n + 1; i++){

            if(a[i + 1] - a[i] >= 120) cnt += (a[i + 1] - a[i]) / 120;

        }

        if(cnt >= 2){

            cout << "YES" << endl;

        }else{

            cout << "NO" << endl;

        }

    }

}