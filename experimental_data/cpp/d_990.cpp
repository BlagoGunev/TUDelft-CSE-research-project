#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define in(x) scanf("%lld", &x)
#define mp(x, y) make_pair(x, y)
#define ld long double
#define mod 1000000007
#define fl(i, A, B) for(i = A; i < B; ++i)
#define um unordered_map < ll, ll >
#define us unordered_set <ll>
#define vll vector<ll>
#define pll pair<ll, ll>
#define all(a) a.begin(), a.end()
#define rep(i,a, b) for(ll i = a; i < b; ++i)
#define debug() cout << "Hello ! Debug"


int main()
{

    ll n, a, b;
    in(n);
    in(a);
    in(b);

    if(a != 1 && b != 1)
    {
        cout << "NO";
        return 0;
    }

    if(a == 1 && b == 1 && n < 4 && n > 1)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;

    bool complement = false;

    if(a == 1)
    {
        complement = true;
        swap(a, b);
    }

    ll len = n - a + 1;
    vector<vll> graph(n + 1);

    for(ll i = 2; i <= len; ++i)
    {
        graph[i - 1].push_back(i);
    }

    vector< string> ans(n, string(n, '0'));

    rep(i, 1, graph.size())
    {
        rep(j, 0, graph[i].size())
        {
            ll node = i;
            ll child = graph[i][j];
            ans[node - 1][child - 1] = '1';
            ans[child - 1][node - 1] = '1';
        }
    }

    if(complement)
    {
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                if(i == j)
                    continue;

                if(ans[i][j] == '0')
                    ans[i][j] = '1';
                else
                    ans[i][j] = '0';
            }
        }
    }

    rep(i, 0, n)
    {
        cout << ans[i] << endl;
    }

    return 0;
}