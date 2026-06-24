#include<bits/stdc++.h>

using namespace std;

#define task "long"

#define pb push_back

#define ll long long

#define fi first

#define se second

#define all(x) x.begin(),x.end()

#define MASK(i) ((1LL)<<(i))

#define GETBIT(x,i) (((x)>>(i))&1)

#define TURNOFF(x,i) ((x)&(~(1<<i)))

#define CNTBIT(x) __builtin_popcount(x)

#define LOG 20

#define MASK(i) ((1LL)<<(i))

#define EL cout << "\n"

#define FU(i, a, b) for(int i=a; i<=b; i++)

#define FD(i, a, b) for(int i=a; i>=b; i--)

#define REP(i, x) for(int i=0; i<x; i++)

//#pragma GCC optimize("Ofast")

//#pragma GCC optimization("unroll-loops, no-stack-protector")

//#pragma GCC target("avx,avx2,fma")

const int MAX = 1e6 + 5, N = 1e6;

const int mod = 1e9 + 7;

const int base = 998244353;

typedef pair<int, int> ii;

void init()

{

    if (fopen(task".inp","r"))

    {

        freopen(task".inp","r",stdin);

        freopen(task".out","w",stdout);

    }

}

void fastio()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

}

int dx[]={0,1,0,-1,1,1,-1,-1};

int dy[]={1,0,-1,0,1,-1,1,-1};

template<class X, class Y> bool maximize(X &x, Y y){ if (x < y) {x = y; return true;} return false;};

template<class X, class Y> bool minimize(X &x, Y y){ if (x > y) {x = y; return true;} return false;};

//void add(int &x, int y) { x += y; if (x>=mod) x-=mod;}

//void sub(int &x, int y) { x -= y; if (x<0) x+=mod;}

int n;

int a[MAX], divisor[MAX], res[MAX], vt[MAX], mn[MAX][LOG+2], lg[MAX];

vector<int> pos[MAX];

char s[MAX];

void read()

{

    cin >> n;

    FU(i, 1, n) cin >> a[i];

    FU(i, 1, n) cin >> s[i];

    FU(i, 1, n)

    {

        while(MASK(lg[i]) <= i) lg[i]++; lg[i]--;

    }

}

void add(int val, int p)

{

    vt[p] = p;

    while(val != 1)

    {

        pos[divisor[val]].pb(p);

        val /= divisor[val];

    }

}

void sub(int val, int p)

{

    if (val == 1)

    {

        vt[p] = p;

        return;

    }

    int  tmp = p;

    while(val != 1)

    {

        if (pos[divisor[val]].empty())

        {

            tmp = 0;

            val /= divisor[val];

            continue;

        }

        tmp = min(tmp, pos[divisor[val]].back());

        pos[divisor[val]].pop_back();

        val /= divisor[val];

    }

    vt[p] = tmp;

}

int getMin(int l, int r)

{

    int k = lg[r-l+1];

    return min(mn[l][k], mn[r - MASK(k) + 1][k]);

}

void sol()

{

    FU(i, 2, N) if (divisor[i] == 0)

    {

        divisor[i] = i;

        if (i > 1000) continue;

        for(int j = i * i; j <= N; j += i) divisor[j] = i;

    }

    FU(i, 1, n)

    {

        if (s[i] == '*') add(a[i], i);

        else sub(a[i], i);

    }

    FU(i, 1, n) mn[i][0] = vt[i];

    for(int j = 1; MASK(j) <= n; j++)

    {

        for(int i = 1; i + MASK(j) - 1 <= n; i++)

        {

            mn[i][j] = min(mn[i][j-1], mn[i + MASK(j-1)][j-1]);

        }

    }

    ll ans = 0;

    FD(i, n, 1)

    {

        int l = i, r = n, res = -1;

        while(l<=r)

        {

            int mid = (l+r)>>1;

            if (getMin(i, mid) >= i)

            {

                res = mid;

                l = mid + 1;

            }

            else r = mid - 1;

        }

        if (res != -1) ans += res - i + 1;

    }

    cout << ans;

}

signed main()

{

    fastio();

    init();

    int T = 1;

    //cin >> T;

    while(T--)

    {

        read();

        sol();

    }

}