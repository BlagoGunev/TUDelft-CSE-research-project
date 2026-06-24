#include <bits/stdc++.h>

#include "ext/pb_ds/assoc_container.hpp"

#include "ext/pb_ds/tree_policy.hpp"

using namespace std;

using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE

#include "debug.cpp"

#else

#define debug(x...)

#endif

template<class T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class key, class value, class cmp = std::less<key>>

using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;



#define ll            long long int

#define double        long double

#define INF           9e18



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



const ll MOD = 1e9 + 7;

const ll N = 2e5 + 5;



void solve(int test_case) {

    int n;

    cin >> n;

    vector<int> vect(n);

    vector<vector<int>> ind(n + 2);

    for(int i = 0; i < n; i++) {

        cin >> vect[i];

        ind[vect[i]].push_back(i + 1);

    }



    int cur;

    int state;

    if(ind[0].size() > 0) {

        cur = 0;

        state = 1;

    }

    else {

        cur = n + 1;

        state = 0;

    }



    int cnt = 1;

    set<int> s;

    s.insert(0);

    vector<int> ans(n + 1);

    while(cnt <= n) {

        int last;

        for(auto x: ind[cur]) {

            if(ind[x].size() > 0) {

                last = x;

            }

            if(state == 0) {

                s.insert(x);

            }

        }



        for(auto x: ind[cur]) {

            if(x != last) {

                ans[cnt] = x;

                cnt++;

            }

        }



        if(cnt > n) {

            break;

        }

        ans[cnt] = last;

        cnt++;

        cur = last;

        state = 1 - state;

    }



    cout << *s.rbegin() << "\n";

    for(int i = 1; i <= n; i++) {

        cout << ans[i] << " ";

    }

    cout << "\n";

}



int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    clock_t z = clock();



    int t = 1;

    cin >> t;

    for(int tc = 1; tc <= t; tc++) {

        solve(tc);

    }



    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;

    return 0;

}