#include <bits/stdc++.h>

using namespace std;



const int mod = 998244353;

typedef long long ll;

int p[200005];

int main()

{

    int n;cin >> n;

    if(n == 1) puts("3");

    else if(n == 2) puts("5");

    else {

        n += 2;

        ll ans = 4LL*(n/3);

        if(n % 3 == 1) ans += 1;

        if(n % 3 == 2) ans += 3;

        cout <<ans;

    }

    return 0;

}