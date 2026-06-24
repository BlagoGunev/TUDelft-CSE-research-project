#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define int long long



using namespace std;

using namespace __gnu_pbds;



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;



void erase(ordered_multiset &s, int v) {int rank = s.order_of_key(v); auto it = s.find_by_order(rank); s.erase(it);}



const int MOD = 1e9 + 7;



void solve() {

    int n, m;

    cin >> n >> m;

    vector<int> a(n);

    int ans = 0;

    for (int &x : a) {

        cin >> x;

        ans += x;

    }

    ans++;

    sort(a.begin(), a.end());



    int l = 0, r = n - 1;

    bool turn = false;

    while (l < r) {

        if (a[l] + a[r] <= m) {

            if (!turn) {

                r--;

            } else {

                l++;

            }

            turn = !turn;

        } else {

            r--;

            ans++;

        }

    }

    cout << ans;

}   



int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    solve();

    return 0;

}