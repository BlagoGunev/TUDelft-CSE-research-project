#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);
using namespace std;


int main() {

    fastio()
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        long long int p = 1;
        int even = 0;
        for (int i = 0; i < n; ++i)
        {
            /* code */cin >> a[i];
            if (a[i] % 2 == 0) even++;
        }

        int ans = INT_MAX;


        if (k == 4 ) {
            if (even == 0) ans = 2;
            else if (even == 1) ans = 1;
            else ans = 0;
        }


        for (int i = 0; i < n; ++i)
        {
            /* code */
            int s = a[i] % k;
            if (s == 0) ans = 0;
            ans = min(ans, k - s);
        }





        cout << (ans) << endl;



    }

}