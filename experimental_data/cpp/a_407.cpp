#include <bits/stdc++.h>

using namespace std;



#define ESP (1e-9)



typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector <ii> vii;

typedef pair<long, long> pll;

typedef vector<ll> vll;

typedef vector <pll> vpll;



const ll c_mod = 1000000007;

#define MOD(a,op,b) (((a) % (c_mod)) op ((b)%(c_mod)))%c_mod

#define tr(c, it)   for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)



template <typename T>

void cinall(T& t)

{

    cin >> t;

}

template<typename T, typename... Args>

void cinall(T& t, Args& ... args) // recursive variadic function

{

    cin >> t;

    cinall(args...);

}

#define INS(T, ...) T __VA_ARGS__;cinall(__VA_ARGS__)



template<typename T>

void coutall(T t)

{

    cout << t << "\n";

}

template<typename T, typename... Args>

void coutall(T t, Args ... args)

{

    cout << t << " ";

    coutall(args...);

}

#define OUT(...) coutall(__VA_ARGS__)



bool validate(int x1, int y1, int x2, int y2, int a, int b)

{

    if (x1 == 0 || y1 == 0 || x2 == 0 || y2 == 0 || x1 == x2 || y1 == y2)

    {

        return false;

    }



    int m1m2 = (y1 * (double)y2) / (x1 * x2);

    if (m1m2 != -1)

    {

        return false;

    }

    return (x1 * x1 + y1 * y1 == a * a) && (x2 * x2 + y2 * y2 == b * b);

}



int main()

{

#ifdef LOCAL

    freopen("input", "r", stdin);

#else

    ios_base::sync_with_stdio(false);

#endif

    INS(int, a, b);

    int x, y, x2, y2;

    for (x = 1; x < a; ++x)

    {

        y = abs((int)sqrt(a * a - x * x));

        if (y * y + x * x == a * a)

        {

            x2 = (int)(b * y / a);

            y2 = (int)(-b * x / a);

            if (validate(x, y, x2, y2, a, b))

            {

                break;

            }

            x2 = (int)(-b * y / a);

            y2 = (int)(b * x / a);

            if (validate(x, y, x2, y2, a, b))

            {

                break;

            }

        }

    }

    if (validate(x, y, x2, y2, a, b))

    {

        OUT("YES");

        OUT(x, y);

        OUT(x2, y2);

        OUT(0, 0);

    }

    else

    {

        OUT("NO");

    }

    return 0;

}