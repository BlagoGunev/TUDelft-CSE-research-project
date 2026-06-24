#include <bits/stdc++.h>

using namespace std;



#define ll long long

#define ar array 



const int MOD = 1e9+7;

const ll INF = 1e18;



int main() 

{

    int t;

    cin >> t;

    for(int i = 0; i < t; ++i) {

        int a, b;

        cin >> a >> b;

        if(a==0) {

            cout << 1 << "\n";

        }

        else

            cout << 2*b+a+1 << "\n";

    }

}