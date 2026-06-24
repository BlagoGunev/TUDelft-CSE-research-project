/*

ID: armaan48

LANG: C++ 

*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define mod 1000000007

#define mod2 998244353

#define endl '\n' 

#define all(x) x.begin(),x.end()

#define print(x) {for(auto v: x) {cout << v<< ' ';} cout << endl;}



signed main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);cout.tie(NULL);

    int t; cin >> t;

    while (t--){

        int n,k; cin >> n >> k;

        vector<int> air(n+1,INT_MAX);

        vector<int> pos(k);

        for (int &v: pos)

            cin >> v;

        for (int i=0;i<k;i++){

            cin >> air[pos[i]];

        }

        

        vector<int> suffix(n+1);

        int curTemp = INT_MAX;

        for (int i=n;i>=1;i--){

            curTemp = min(curTemp+1,air[i]);

            suffix[i]= curTemp;

        }

        //print(suffix);

        curTemp = INT_MAX;

        

        for (int i=1;i<=n;i++){

            curTemp  = min(curTemp+1,air[i]);

            cout << min(curTemp,suffix[i]) << " ";

            

        }

        cout << endl;

        



        

        

    }

    

    return 0;

}