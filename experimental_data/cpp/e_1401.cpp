#include<bits/stdc++.h>

#include<unordered_map>

#include<array>

#define ll long long

#define ull unsigned long long

#define all(a) a.begin(),a.end()

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;



const int inf = 0x3f3f3f3f;

const ll INF = 0x3f3f3f3f3f3f3f3f;

const double eps = 1e-8;

const ll mod = 1e9 + 7;

const int N = 1e6 + 5;



int n, m, tot;

ll ans;

struct Line {

    int l, r, id, type, val, h;// 1->水平线

    bool operator < (Line& a) {

        if (h == a.h && type + a.type == 3)

        {

            if (type == 2 && val == 1)

                return 1;

            if (type == 2 && val == -1)

                return 0;

            if (a.type == 2 && val == 1)

                return 0;

            if (a.type == 2 && val == -1)

                return 1;

        }

        if (h == a.h)

            return val > a.val;

        return h < a.h;

    }

}line[N];



struct BIT {

    ll b[1000005];

    ll lowbit(ll x)

    {

        return x & -x;

    }

    void add(ll x, ll val)

    {

        while (x < 1000005)

            b[x] += val, x += lowbit(x);

    }

    ll getsum(ll x)

    {

        ll ans = 0;

        while (x)

            ans += b[x], x -= lowbit(x);

        return ans;

    }

    ll query(ll l, ll r)

    {

        return getsum(r) - getsum(l - 1);

    }

}b;



void solve()

{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)

    {

        cin >> line[++tot].id >> line[tot].l >> line[tot].r;

        line[tot].id++;

        line[tot].l++;

        line[tot].r++;

        line[tot].h = line[tot].id;

        line[tot].type = 1;

        if (line[tot].l == 1 && line[tot].r == 1000001)

            ans++;

    }

    for (int i = 1; i <= m; i++)

    {

        int id, l, r;

        cin >> id >> l >> r;

        id++, l++, r++;

        line[++tot].id = id;

        line[tot].h = l;

        line[tot].val = 1;

        line[tot].type = 2;

        line[++tot].id = id;

        line[tot].h = r;

        line[tot].val = -1;                     

        line[tot].type = 2;

        if (l == 1 && r == 1000001)

            ans++;

    }



    sort(line + 1, line + 1 + tot);

    for (int i = 1; i <= tot; i++)

    {

        if (line[i].type == 2) 

            b.add(line[i].id, line[i].val);

        else

            ans += b.query(line[i].l, line[i].r);

    }

    cout << ans + 1 << '\n';

}



signed main()

{

	IOS;

	int t = 1;

	//cin >> t;

	while (t--)

		solve();

	return 0;

}