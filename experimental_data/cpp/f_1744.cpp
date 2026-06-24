#include<bits/stdc++.h>

using namespace std;



const long long Mod = (1e9) + 7;



int main() {

    ios::sync_with_stdio(0);

    cin.tie(0);



    int t;

    cin >> t; 

    while(t--) {

        int n;

        cin >> n;

        vector<int> a(n), pos(n);

        for(int i = 0; i <= n - 1; i++) {

            cin >> a[i];

            pos[a[i]] = i;

        } 

        int l = pos[0];

        int r = pos[0];

        long long ans = 0;

        for(int len = 1; len <= n; len++) {

            int add = (len - 1) / 2;

            l = min(l, pos[add]);

            r = max(r, pos[add]);

            if(r - l + 1 > len) continue;

            int e = len - r + l - 1;

            int up = max(0, l - e);

            int lr = min(l, n - len);

            if(lr < up) continue;

            ans += lr - up + 1;

        }

        cout << ans << '\n';

    }

    return 0;

}