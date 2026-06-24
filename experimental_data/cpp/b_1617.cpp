#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define endl "\n"

#define all(x) x.begin(),x.end()

const int MOD = 998244353, SZ=1e6+10;

void solve(){

    int n;

    cin >> n;

    if(n%2){

        n /= 2;

        if(n%2)

            cout << n-2 << ' ' << n+2 << " 1\n";

        else

            cout << n-1 << ' ' << n+1 << " 1\n";

    }

    else

        cout << n/2 << ' ' << n/2-1 << " 1\n";

}

int main()

{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test;

    cin >> test;

    while(test--){

        solve();

    }

    return 0;

}