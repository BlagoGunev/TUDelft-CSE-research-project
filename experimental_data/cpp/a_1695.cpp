#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long

#define lli long long int

#define ld long double

#define ull unsigned long long

#define ulli unsigned long long int

#define PI 3.1415926535897932384626433832795



#define sp ' '

#define pb push_back

#define ppb pop_back

#define pii pair<int, int>

#define pll pair<ll, ll>

#define vi vector<int>

#define vll vector<ll>

#define vpii vector<pii>

#define vpll vector<pll>



#define gcd(a, b) __gcd(a, b);

#define precision(a, b) cout << fixed << setprecision(a) << b << endl

#define incfor(a, b) for (int i = a; i < b; i++)

#define decfor(a, b) for (int i = a; i > b; i--)

#define nincfor(a, b) for (int j = a; j < b; j++)

#define ndecfor(a, b) for (int j = a; j > b; j--)

#define output(n) incfor(0, n) cout << a[i] << sp;

#define input(n) incfor(0, n) cin >> a[i];



const int MAX_N = 1e5 + 5;

const ll MOD = 1e9 + 7;

const ll INF = 1e9;

const ld EPS = 1e-9;



void solve()

{

    ll row, col, mx = -1e11, indexrow, indexcol;

    cin >> row >> col;

    ll a[row][col];

    incfor(0, row)

    {

        nincfor(0, col)

        {

            cin >> a[i][j];

            if (a[i][j] > mx)

            {

                mx = a[i][j];

                indexrow = i, indexcol = j;

            }

        }

    }

    ll x, b, c, d;

    x = indexrow +1;

    b = row - indexrow ;

    b = max(x, b);

    c = indexcol + 1;

    d = col - indexcol;

    d = max(c, d);

    cout << b * d << endl;

}



int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int tc = 1;

     cin >> tc;

    for (int t = 1; t <= tc; t++)

    {

        // cout<<"Case "<<t<<": ";

        solve();

    }

    return 0;

}

/**

 *    author:  lifelessnoob

 **/