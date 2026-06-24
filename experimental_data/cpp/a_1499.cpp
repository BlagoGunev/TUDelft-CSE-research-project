// 0 to 4,294,967,295 UN_SIGNED INT SIZE

// transform(s.begin(), s.end(), s.begin(), ::toupper);

// APNA KAM KER ,|,,

//  ******* *     *   ********   *      *

//  *       *     *   *          *    *

//  *       *     *   *          *  *

//  ****    *     *   *          *  *

//  *       *     *   *          *    *

//  *       *******   ********   *      *

#include <bits/stdc++.h>

#define mx INT_MAX

#define mi INT_MIN

#define ll long long int

#define fr(i, a, x) for (int i = a; i < x; ++i)

#define vr(x) vector<ll> x

#define ss second

#define f first

#define all(v) v.begin(), v.end()

#define sz(v) v.size()

#define mk(x, y) make_pair(x, y)

#define MOD 1000000007

#define Integer_MAX_VALUE 0x7fffffff

#define Integer_MIN_VALUE 0x80000000

#define Long_MAX_VALUE 0x7fffffffffffffffL

#define Long_MIN_VALUE 0x8000000000000000L



using namespace std;



int gcd(int a, int b)

{

    while (b != 0)

    {

        a %= b;

        a ^= b;

        b ^= a;

        a ^= b;

    }

    return a;

}



bool isPerfectSquare(long double x)

{



    if (x >= 0)

    {



        long long sr = sqrt(x);

        return (sr * sr == x);

    }

    return false;

}



int lcm(int a, int b)

{



    return a / gcd(a, b) * b;

}



void solve()

{

    int n, k1, k2;

    cin >> n >> k1 >> k2;

    int w, b;

    cin >> w >> b;



    int t = k1 + k2;



    if (t >= 2 * w && (2 * n - t) >= 2 * b)

    {

        cout << "YES" << endl;

    }

    else

    {

        cout << "NO" << endl;

    }

}



int main()

{



    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);



    int t = 1;



    cin >> t;



    while (t--)

    {



        solve();

    }

    return 0;

}