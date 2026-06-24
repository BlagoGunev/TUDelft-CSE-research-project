#include <bits/stdc++.h>

using namespace std;

long long power(long long a,long long b,long long mod) {

    long long res=1;

    while(b>0) {

        if(b&1)

            res=(res*a)%mod;

        a=(a*a)%mod;

        b>>=1;

    }

    return res;

}

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    long long test;

    cin >> test;

    while(test--) {

        long long x1;

        cin >> x1;

        long long y1;

        cin >> y1;

        long long z1;

        cin >> z1;

        long long x2;

        cin >> x2;

        long long y2;

        cin >> y2;

        long long z2;

        cin >> z2;

        long long res=0;

        long long em = min(z1,y2);

        res+=(em*2);

        z1-=em;

        y2-=em;

        if(z1==0) {

            z2-=x1;

            z2=max(z2,0LL);

            res-=z2*2;

        } else {

            z2-=z1;

            z2-=x1;

            z2=max(z2,0LL);

            res-=z2*2;

        }

        cout << res << '\n';

    }

    return 0;

}