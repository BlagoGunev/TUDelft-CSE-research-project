#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    int t; 

    cin >> t;

    ll n, x, cnt;

    while(t--){

        cin >> n;

        x = 1;

        cnt = 0;

        //vai ficar na celula (n/2 + 1, n/2 + 1)

        while(x <= n){

            cnt += 4*(x-1)*(x/2);

            x += 2;

        }

        cout << cnt << endl;

    }

    return 0;

}