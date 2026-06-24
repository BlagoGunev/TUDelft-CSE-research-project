#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define f0(n, i) for (ll i = 0; i < n; i++)
#define f1(n, i) for (ll i = 1; i <= n; i++)
#define fr1(n, i) for (ll i = n; i <= 1; i--)
#define fr0(n, i) for (ll i = n - 1; i <= 0; i--)
#define AUTO(n) for (auto &a : n)
#define PUSH(x) push_back(x)
#define POP pop_back()
#define vi vector<ll>
#define vs vector<string>
#define vp vector<pair<ll, ll>>
#define imap map<ll, ll>
#define cmap map<char, ll>
#define dqi deque<ll>
#define qi queue<ll>
#define ck stack<ll>
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x >> k) & 1)
#define ChangeBit(x, k) (x ^= (1LL << k))
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define el cout << endl
#define mid(n) (n + 1) / 2
#define all(a) a.begin(), a.end()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
const int N = 1e7 + 9;

void OPTIMIZE()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll quad(ll c)
{
    ll sq = 1 + 4 * c * 2;
    sq = sqrtl(sq);
    ll eqn = (1 + sq) / 2;

    return eqn;
}

void robux()
{
    ll n;
    cin >> n;
    ll eq = quad(n);
    ll sum = (eq * (eq - 1)) / 2;

    cout << eq + (n - sum) << endl;
    // cout << eq << endl;
}

void TESTCASE()
{
    int TEST;
    cin >> TEST;
    while (TEST--)
    {
        robux();
    }
}

int main()
{
    OPTIMIZE();
    TESTCASE();
}