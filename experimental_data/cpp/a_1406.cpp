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

    k=0;

    l=0;

    h=0;

    while (t--) {

        cin>>n;

        vll a(n);

        k=0;

        forn(i, n) {

            cin >> a[i];

        }

        std::sort(a.begin(), a.end());

        l=0;

        k=1;

        while(k<n ){

            if(a[k]==l && a[k-1]==l)

                ++l;

            ++k;

        }

        r=0;

        k=0;

        while(k<n ){

            if(a[k]==r)

                ++r;

            ++k;

        }

        cout<<l+r<<'\n';

    }



}