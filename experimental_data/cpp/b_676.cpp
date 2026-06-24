#include <bits/stdc++.h>



#define oo 1000000007

#define OO 1000000000000000007

#define maxN 300005

#define fto(i, x, y) for(int i = (x); i <= (y); ++i)

#define fdto(i, x, y) for(int i = (x); i >= (y); --i)

#define ftoa(i, x, y, a) for(int i = (x); i <= (y); i += a)

#define fdtoa(i, x, y, a) for(int i = (x); i >= (y); i -= a)

#define bug(a) cout << #a << " = " << a << endl;

#define fbug(a, x, y) { cout << #a << ": "; fto(_, x, y) cout << a[_] << ' '; cout << endl; }

#define mp make_pair

#define pb push_back

#define pf push_front

#define ll long long

#define lb lower_bound

#define ub upper_bound

#define ull unsigned long long

#define ii pair<int, int>

#define vi vector<int>

#define vll vector<ll>

#define vii vector<ii>

#define FF first

#define SS second

#define mt make_tuple

#define eb emplace_back



using namespace std;



ll Max() {return -OO;}

ll Min() {return  OO;}



template <typename... Args>

ll Max(ll a, Args... args) {return max(a, Max(args...));}



template <typename... Args>

ll Min(ll a, Args... args) {return min(a, Min(args...));}



int con[16][16], cur[16][16];



int main() {

    #ifndef ONLINE_JUDGE

        freopen("tmp.inp", "r", stdin);

        freopen("tmp.out", "w", stdout);

    #endif // ONLINE_JUDGE



    int n, t;

    scanf("%d%d", &n, &t);





    con[0][1] = 1048576;

    while (t--) {

        fto (i, 1, n) {

            fto (j, 1, i) {

                cur[i][j] += con[i-1][j-1]+con[i-1][j];

                con[i][j] = max(0, cur[i][j]-1048576)/2;

                cur[i][j] = min(cur[i][j], 1048576);

            }

        }

    }



    int res = 0;

    fto (i, 1, n) {

        fto (j, 1, i) {

            if (cur[i][j] == 1048576) ++res;

        }

    }



    printf("%d", res);



    #ifndef ONLINE_JUDGE

        cout << endl;

        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    #endif



    return 0;

}