#include<bits/stdc++.h>

using namespace std;







void solve(){

    int n, k;

    cin >> k >> n;

    int inc = 1, x, l, p;

    int r_k = k;

    vector<int> a(k);

    for (int i = 0; i < k; i++){

        if(i == 0){

            a[0] = 1;

            r_k--;

            continue;

        }

        l = a[i - 1] + inc;

        x = n - a[i - 1];

        p = x - inc;

        if(l<=n && inc <= x && p >= (r_k-1)){

            a[i] = l;

            inc++;

            r_k--;

        }else{

            a[i] = a[i - 1] + 1;

            r_k--;

        }

    }

    for (int i = 0; i < k;i++){

        cout << a[i] << " ";

    }

    cout << "\n";

}







int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int t;

    cin >> t;

    while(t--){

        solve();

    }



    return 0;

}