#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define all(v) (v).begin(), (v).end()

#define popcountll(x) __builtin_popcountll(x)

#define pb push_back

#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef Liucj_2022

#include "../Liucj_2022/debug.h"

#else

#define LOG(...)

#endif // Liucj_2022

// 3 3 7

// 1 2 3 4 5 6 7

//   4 3   4   3   4 2 3   4 2 3   4 2 3   4 2 3   4 2 3   4 2 3   

// 7 2 1   7 2 1   7   1     7 1   6 7 1   6 7 1   6   1   6   1   

// 6 5     6 5     6 5     6 5       5     5       5 7     5   7     



// 只要场上活动的牌数量 > n * m - 2



void solve() {

    int n, m, k;    cin >> n >> m >> k;

    vector<int> a(k);

    for (auto &&x : a)  cin >> x, x --;

    

    int top = k;

    priority_queue<int> pq;

    for (int i = 0; i < k; ++ i) {

        pq.push(a[i]);

        LOG(a[i], pq.size())

        if (pq.size() >= n * m - 2) {

            cout << "TIDAK" << endl;

            return;

        }

        while (pq.size()) {

            auto now = pq.top();

            if (now == top - 1) {

                pq.pop();

                top --;

            }

            else                break;

        }

    }



    cout << "YA" << endl;

}



signed main() {

    ios::sync_with_stdio(false), cin.tie(0);

    #ifdef Liucj_2022

freopen("sample.in", "r", stdin);	   freopen("sample.out", "w", stdout);

    #endif

    int tt = 1;

    cin >> tt;

    while (tt -- ) solve();

    return 0;

}