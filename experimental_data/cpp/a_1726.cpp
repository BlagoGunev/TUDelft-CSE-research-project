#include <bits/stdc++.h>



using namespace std;



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

#ifndef ONLINE_JUDGE

    freopen("in.txt", "r", stdin);

    freopen("out.txt", "w", stdout);

    freopen("error.txt", "w", stderr);

#endif



    int tt;

    cin >> tt;

    while (tt--) {

        int n ;

        cin>>n;

        int a[n];

        for (int i = 0; i < n; ++i) {

            cin>>a[i];

        }

        int ans = -1e7+6;

        for (int i = 1; i < n; ++i) {

            ans = max(ans,(a[i]-a[0]));

        }

        for (int i = 0; i < n; ++i) {

            ans = max(ans,(a[(i-1+n)%n]-a[i]));

        }



        for (int i = 0; i < n - 1; ++i) {

            ans = max(ans,(a[n-1]-a[i]));

        }

        cout<<ans<<endl;









    }



}