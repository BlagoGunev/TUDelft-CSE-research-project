#include <bits/stdc++.h>

#define pb push_back

#define mp make_pair

#define f first

#define s second

#define fore(i, n) for(int i = 0; i < n; i++)

#define lop(i, n) for(int i = 1; i <= n; i++)

#define ops(i, n) for(int i = n - 1; i >= 0; i--)

#define forall(it, g)  for(typeof(g.begin()) it = g.begin(); it != g.end(); it++)

#define PI  3.141592653589793

#define mod  1000000007

#define inf 2000000000

#define INF -2000000000000000

#define modulo 1000000009

#define MH 1234533333333337

#define MH2 7779845079489377

#define enter endl

//ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using namespace std;

typedef vector <int> vi;

typedef vector <pair <int,int > >vp;

typedef long long int ll;

typedef unsigned long long ull;

typedef pair<int, int> pp;

typedef pair<int, ll> ppil;

typedef pair<ll, ll> ppl;

const int M = 100005;

int sum[M];

ll sq(int a, int b)

{

        return 1LL * (a - b) * (a - b);

}

int main()

{

        int n;

        scanf("%d", &n);

        lop(i, n)

        {

                int x;

                scanf("%d", &x);

                sum[i] = sum[i - 1] + x;

        }

        set<pair<ll, int> > ys;

        double ans = 1e12;

        ll dist;

        int idx = 1;

        lop(i, n)

        {

                ll x = sum[i];

                while(idx < i && i - idx > ans)

                {

                        ys.erase(mp(sum[idx], idx));

                        idx++;

                }

                set<pair<ll, int> > :: iterator it1 = ys.lower_bound(mp(x - ans - 1, -1)),

                it2 = ys.upper_bound(mp(x + ans + 1, n + 5));

                while(it1 != it2)

                {

                        pp pr = *it1;

                        ll a = sq(i, pr.s);

                        ll b = sq(x, pr.f);

                        double d = sqrt(a + b);

                        if(ans > d)

                        {

                                ans = d;

                                dist = a + b;

                        }

                        it1++;

                }

                ys.insert(mp(sum[i], i));

        }

        printf("%I64d", dist);

        return 0;

}