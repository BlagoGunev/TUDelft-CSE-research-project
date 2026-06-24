#include<bits/stdc++.h>

#define task ""

#define ll long long

#define ld long double

#define fi first

#define se second

#define pb push_back

using namespace std;

const int MAXN = 1e5 + 5;

const ll INF = 1e18 + 5;



int n;

pair<ll, ll> a[MAXN];



void Input()

{

    cin >> n;

    for (int i = 1; i <= n; i++)

    {

        cin >> a[i].fi >> a[i].se;

    }

}



void Solve()

{

    sort (a + 1, a + n + 1);

    ll maxt = a[1].fi;

    ll ans = 0;

    for (int i = 1; i <= n; i++)

    {

        ans += a[i].se;

        ans += max(0ll, a[i].fi - maxt);

        maxt = max(maxt, a[i].fi + a[i].se);

    }

    cout << ans;

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    //freopen(task".INP","r",stdin);

    //freopen(task".OUT","w",stdout);

    Input();

    Solve();

}