#include <bits/stdc++.h>

using namespace std;



int main(){

    int t;

    cin >> t;



    while(t--){

        int n, x;

        cin >> n >> x;

        vector<int> h(2 * n);

        for(int i = 0; i< 2*n; i++){

            cin >> h[i];

        }



        sort(h.begin(), h.end());

        int c = 0;

        for(int i = 0; i< n; i++){

            if(h[n+i]-h[i] < x){

                c++;    

            }

        }

        cout << (c>0 ? "NO" : "YES") << "\n";



    }

}