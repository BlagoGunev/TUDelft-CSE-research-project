#include <bits/stdc++.h>



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define x0 abc

#define y0 ABC

#define x1 abcd

#define y1 ABCD

#define xn abcde

#define yn ABCDE



#define lb lower_bound

#define ub upper_bound



#define in insert

#define er erase



#define fi first

#define se second

#define mp make_pair



#define pb push_back

#define pob pop_back



#define uns unsigned



#define ld long double

#define ll long long



#define cont continue

#define re return



#define endl '\n'



#define fbo find_by_order

#define ook order_of_key



#define MAXLL 9000000000000000000LL

#define MAXINT 2000000000



#define MINLL -9000000000000000000LL

#define MININT -2000000000



#define OUT cout << "-------" << endl;



#define bpc __builtin_popcount

#define bpcll __builtin_popcountll



#define tm qwerty



using namespace std;



using namespace __gnu_pbds;



mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());



typedef tree < pair <ll, ll>, null_type, less < pair <ll, ll> >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;







ld pi = acos(-1.), E = exp(1.);



ll N, M = 1e9 + 7, D = 5000, T, Q;



vector < pair <ll, ll> > vec;



ll dp[5011][5011], p1, t1, p2, t2, h, s, i, j, val1, val2, ans;



    void solve()

    {

        cin >> p1 >> t1;



        cin >> p2 >> t2;



        cin >> h >> s;



        vec.clear();



        vec.pb({0, 0});



        for (i = 1; i <= h; i++) {

            val1 = t1 - vec.back().fi;

            val2 = t2 - vec.back().se;



            if (val1 < val2)

            vec.pb({0, vec.back().se + val1});

            else if (val1 > val2)

            vec.pb({vec.back().fi + val2, 0});

            else vec.pb({0, 0});

        }



        for (i = 0; i <= h; i++)

            for (j = 0; j <= h; j++) dp[i][j] = MAXLL;



        dp[h][0] = 0;



        for (i = h; i >= 1; i--)

            for (j = 0; j <= h; j++)

                if (dp[i][j] != MAXLL) {

                    val1 = t1 - vec[j].fi;

                    val2 = t2 - vec[j].se;



                    if (val1 < val2)

                    dp[max(i - (p1 - s), 0LL)][j + 1] = min(dp[max(i - (p1 - s), 0LL)][j + 1], dp[i][j] + val1);

                    else dp[max(i - (p2 - s), 0LL)][j + 1] = min(dp[max(i - (p2 - s), 0LL)][j + 1], dp[i][j] + val2);



                    dp[max(i - (p1 + p2 - s), 0LL)][0] = min(dp[max(i - (p1 + p2 - s), 0LL)][0], dp[i][j] + max(val1, val2));

                }



        ans = MAXLL;



        for (i = 0; i <= h; i++) ans = min(ans, dp[0][i]);



        cout << ans << endl;

    }



int main()

{

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);



    ios::sync_with_stdio(0);

    cin.tie(0);



//    cin >> T;



    T = 1;



    while (T--) solve();



    re 0;

}