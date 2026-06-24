#include <bits/stdc++.h>



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



typedef long long ll;

typedef vector<int> vi;

typedef vector<int>::iterator vit;

typedef vector<vector<int>> vii;

typedef pair<int, int> pii;

typedef tuple<int, int, int> tiii;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;



#define REP(i, a, b) for (int i = a; i < b; i++)

#define REPP(i, a, b) for (int i = a; i >= b; i--)

#define PB push_back

#define MP make_pair

#define MT make_tuple

#define F first

#define S second

#define sq(a) ((a) * (a))

#define v(t) vector<t>

#define all(v) v.begin(), v.end()



#define duration(a) std::chrono::duration_cast<std::chrono::milliseconds>(a).count()

#define timeNow() std::chrono::high_resolution_clock::now()



void run()

{

    int n, m; cin >> n >> m;

    vii grid(n, vi(m)), sgrid(n);

    REP(i, 0, n) {

        REP(j, 0, m) { cin >> grid[i][j]; }

        sgrid[i] = grid[i];

        sort(all(sgrid[i]));

    }

    vi inv(n);

    REP(i, 0, n) {

        int id1 = -1, id2 = -1;

        REP(j, 0, m) {

            inv[i] += grid[i][j] != sgrid[i][j];

            if (grid[i][j] != sgrid[i][j]) {

                if (id1 == -1) id1 = j;

                else id2 = j;

            }

        }

        if (inv[i] > 2) {

            cout << -1 << '\n';

            return;

        }

        else if (inv[i] == 2) {

            REP(i, 0, n) { swap(grid[i][id1], grid[i][id2]); }

            if (grid == sgrid) { cout << id1 + 1 << ' ' << id2 + 1 << '\n'; }

            else cout << "-1\n";

            return;

        }

    }

    cout << "1 1\n";

}



int main()

{

    cin.tie(NULL);

    ios_base::sync_with_stdio(false);



#ifndef ONLINE_JUDGE

    freopen("temp/input.txt", "r", stdin);

    freopen("temp/output.txt", "w", stdout);

#endif



    int t = 1;

    cin >> t;

    REP(i, 1, t + 1) {

        // cout << "Case #" << i << ": ";

        run();

        // cout << '\n';

    }

}