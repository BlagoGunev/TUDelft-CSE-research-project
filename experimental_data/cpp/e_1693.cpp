#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/hash_policy.hpp>

#define fi first

#define se second

 

using namespace std;

using namespace __gnu_pbds;

using ll = long long;

using db = double;

using pii = pair<int, int>;

using pil = pair<int, ll>;

using pli = pair<ll, int>;

using pll = pair<ll, ll>;

using vi = vector<int>;

using vii = vector<pii>;

 

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());



namespace fastIO

{

#define BUF_SIZE 100000

#define OUT_SIZE 100000

#define ll long long

    bool IOerror = 0;

    inline char nc()

    {

        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;

        if (p1 == pend)

        {

            p1 = buf; pend = buf + fread(buf, 1, BUF_SIZE, stdin);

            if (pend == p1) { IOerror = 1; return -1; }

        }

        return *p1++;

    }

    inline bool blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }

    inline void read(int &x)

    {

        bool sign = 0; char ch = nc(); x = 0;

        for (; blank(ch); ch = nc());

        if (IOerror) return;

        if (ch == '-') sign = 1, ch = nc();

        for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';

        if (sign) x = -x;

    }

    inline void read(ll &x)

    {

        bool sign = 0; char ch = nc(); x = 0;

        for (; blank(ch); ch = nc());

        if (IOerror) return;

        if (ch == '-') sign = 1, ch = nc();

        for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';

        if (sign) x = -x;

    }

#undef ll

#undef OUT_SIZE

#undef BUF_SIZE

}; // namespace fastIO



using namespace fastIO;



const int N = 2e5 + 105;



int n;

int a[N];



int fw[N];



void add(int x, int d)

{

    for (; x <= n; x += x & -x)

        fw[x] += d;

}



int ask(int x)

{

    if (x <= 0) return 0;

    int res = 0;

    for (; x; x -= x & -x)

        res += fw[x];

    return res;

}



vector<int> pos[N];



int main()

{

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)

    {

        scanf("%d", &a[i]);

        pos[a[i]].push_back(i);

    }

    ll ans = 0;

    int L = 1, R = n;

    for (int i = n; i; i--)

    {

        if (pos[i].empty()) continue;

        int x = pos[i].front(), y = pos[i].back();

        ans += pos[i].size();

        ans += ask(y) - ask(x - 1);

        if (y < L)

            ans += ask(L - 1) - ask(y),

            R = L - 1, L = x;

        else if (x > R) 

            ans += ask(x) - ask(R),

            L = R + 1, R = y;

        else 

            L = x, R = y;

        for (int x : pos[i]) add(x, 1);

    }

    printf("%lld\n", ans);

}



/* 

6

1 4 2 4 0 2

 */