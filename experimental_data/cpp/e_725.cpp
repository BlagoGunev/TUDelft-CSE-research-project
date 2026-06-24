#include <cstdio>

#include <iostream>

#include <algorithm>

#include <cstdlib>



#define FOR(x, a, b) for (int x = a; x <= b; ++x)

#define FOD(x, a, b) for (int x = a; x >= b; --x)

#define REP(x, a, b) for (int x = a; x < b; ++x)

#define ll long long

#define fi first

#define se second

#define DEBUG(X) { cout << #X << " = " << X << endl; }

#define PR(A, n) { cout << #A << " = "; FOR(_, 1, n) cout << A[_] << " "; cout << endl; }

#define PR0(A, n)  { cout << #A << " = "; REP(_, 0, n) cout << A[_] << " "; cout << endl; }



using namespace std;



void Read(int &n)

{

    int sign = 1; n = 0; char c;

    do

    {

        c = getchar();

    } while (!isdigit(c) && c != '-');

    if (c == '-')

    {

        c = getchar();

        sign = -1;

    }

    do

    {

        n = n * 10 + c - 48;

        c = getchar();

    } while (isdigit(c));

    n *= sign;

}



void Read(ll &n)

{

    int sign = 1; n = 0; char c;

    do

    {

        c = getchar();

    } while (!isdigit(c) && c != '-');

    if (c == '-')

    {

        c = getchar();

        sign = -1;

    }

    do

    {

        n = n * 10ll + c - 48;

        c = getchar();

    } while (isdigit(c));

    n *= sign;

}



void Write(int n)

{

    if (n == 0)

    {

        putchar('0');

        return;

    } else if (n < 0) putchar('-'), n = -n;

    char C[30];

    int d = 0;

    while (n)

    {

        C[++d] = (n % 10) + 48;

        n /= 10;

    }

    FOD(i, d, 1) putchar(C[i]);

}



void Write(ll n)

{

    if (n == 0)

    {

        putchar('0');

        return;

    } else if (n < 0) putchar('-'), n = -n;

    char C[30];

    int d = 0;

    while (n)

    {

        C[++d] = (n % 10ll) + 48;

        n /= 10ll;

    }

    FOD(i, d, 1) putchar(C[i]);

}



const int maxn = 2e5 + 10;



int cnt[maxn], nxt[maxn], P[maxn];

int n, c;



bool Check(int add)

{

    int k = c;

    int act = c;

    bool used = 0;

    while (k)

    {

        int p = nxt[act];

        if (p == 0) break;

        if (p <= add && add <= act && !used)

        {

            used = 1;

            k -= add;

            act = min(add, k);

        } else

        {

            int Hz = min(cnt[p], k / p);

            k -= Hz * p;

            act = min(p - 1, k);

        }

    }

    return k > 0;

}



int main()

{

    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE

    scanf("%d", &c);

    scanf("%d", &n);

    FOR(i, 1, n) scanf("%d", &P[i]), ++cnt[P[i]];

    int lst = 0;

    FOR(i, 1, c)

    {

        if (cnt[i]) lst = i;

        nxt[i] = lst;

    }

    FOR(add, 1, c) if (Check(add))

    {

        printf("%d", add);

        return 0;

    }

    puts("Greed is good");

    return 0;

}