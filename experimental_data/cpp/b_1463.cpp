#include<bits/stdc++.h>



#define iamspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl "\n"

#define modd 998244353

typedef long long ll;

using namespace std;

ll n, r, m, t, k, i, j, sum, cnt, cnt2, x, y, z, c, d, mx, mn = INT64_MAX, ans;

string s, sk;





int main() {

    iamspeed



    for (cin >> t; t--;) {

        cin >> n;

        ll a[n];

        cnt = 0, cnt2 = 0;

        for (i = 0; i < n; i++) {

            cin >> a[i];

            i % 2 ? cnt += a[i] : cnt2 += a[i];

        }

        mx = a[i];

        for (i = 0; i < n; i++) {

            if (i % 2 && cnt2 <= cnt)cout << a[i] << " ";

            else if (i % 2 == 0 && cnt2 > cnt)cout << a[i] << " ";

            else cout << "1 ";

        }

        cout << endl;

    }



    return 0;

}