#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<ld> vld;

#define forn(i, n) for(int i = 0; i < int(n); ++i)





int main() {

    ios::sync_with_stdio(0);

    cin.tie(0), cout.tie(0);

    ll  h, m, n, k, k0, t = 1, l, r, w, x, y, z, t1, t2, t3;

    cin >> t;

    string s;

    while (t--) {



        cin>>n;

        vector<int> a(n);

        l=0;

        k=1;

        forn(i, n){

            cin>>a[i];

            l+=a[i];

            if(l<(i)*(i+1)/2)

                k=0;

        }

        cout<<(k?"YES\n":"NO\n");

    }



}