// Make the best become better

// No room for laziness

#include<bits/stdc++.h>



#define int long long

#define pb push_back

#define fi first

#define se second

using namespace std;

using ll = long long;

using ld = long double;

using ull = unsigned long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 1e6 + 5;

const int mod = 1e9 + 7;

const ll oo = 1e18;

int n, d1[maxN], d2[maxN];

void ReadInput()

{

    cin >> n;

    for(int i=1; i<=n; i++)

        cin >> d1[i];

    for(int i=1; i<=n; i++)

        cin >> d2[i];

}

bool ok = false;

void chk(int dist)

{

    if(ok) return;

    multiset<int> s1, s2;

    vector<int> res;

    for(int i=1; i<=n; i++)

    {

        s1.insert(d1[i]);

        s2.insert(d2[i]);

    }

    while(!s1.empty() && !s2.empty())

    {

        auto it1 = --s1.end(), it2 = --s2.end();

        pair<int, int> v;

        if(*it1 > *it2) v = {*it1, 1};

        else v = {*it2, 2};

        if(v.fi < dist) break;

        if(v.se == 1)

        {

            s1.erase(s1.find(v.fi));

            if(s2.find(v.fi - dist) == s2.end()) return;

            s2.erase(s2.find(v.fi - dist));

            res.pb(v.fi);

        }

        else

        {

            s2.erase(s2.find(v.fi));

            if(s1.find(v.fi - dist) == s1.end()) return;

            s1.erase(s1.find(v.fi - dist));

            res.pb(-(v.fi - dist));

        }

    }

    if(s1.size() != s2.size()) return;

    while(!s1.empty())

    {

        auto it = s1.begin();

        if(s2.find(dist - *it) == s2.end()) return;

        res.pb(*it);

        s2.erase(s2.find(dist - *it));

        s1.erase(it);

    }

    int p = 0;

    for(int v : res)

        if(v < 0) p = max(p, -v);

    ok = true;

    cout << "YES\n";

    for(int v : res)

        cout << v + p << " ";

    cout << '\n';

    cout << p << " " << p + dist << '\n';

}

void Solve()

{

    ok = false;

    for(int i=1; i<=n; i++)

    {

        chk(abs(d1[i] - d2[1]));

        chk(d1[i] + d2[1]);

    }

    if(!ok) cout << "NO\n";

}

int32_t main()

{

    //freopen("x.inp", "r", stdin);

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    int test;

    cin >> test;

    while(test--)

    {

        ReadInput();

        Solve();

    }

}