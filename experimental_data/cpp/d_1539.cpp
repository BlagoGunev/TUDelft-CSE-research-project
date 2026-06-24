//author: Ausp3x

 

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

typedef long long             lng;

typedef unsigned int          uint;

typedef unsigned long long    ulng;

using namespace std;

using namespace __gnu_pbds;



void solve() {

    int n;

    cin >> n;

    pair<lng, lng> shopping_list[n];

    for (auto &[b, a] : shopping_list) {

        cin >> a >> b;

    }

    sort(shopping_list, shopping_list + n, greater<pair<lng, lng>>());

    int l = 0, r = n - 1;

    lng ans = 0, items_bought = 0;

    while (l <= r) {

        while (items_bought < shopping_list[r].first && l <= r) {

            lng cur = min(shopping_list[l].second, max(shopping_list[r].first - items_bought, 0ll));

            ans += 2 * cur;

            items_bought += cur;

            shopping_list[l].second -= cur;

            if (shopping_list[l].second == 0) {

                l++;

            }

        }

        while (items_bought >= shopping_list[r].first && l <= r) {

            ans += shopping_list[r].second;

            items_bought += shopping_list[r].second;

            r--;

        }

    }   

    cout << ans;



    return;

}

 

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

   

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif



    int t = 1;

    // cin >> t;

    while (t--) {

        solve();

    }



    return 0;

}