#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

template<typename T>
void
_dbg(char const* s, const T& t)
{
    cout << s << "=" << t << endl;
}
template<typename T, typename... TA>
void
_dbg(char const* s, const T& t, const TA&... ta)
{
    while (*s != ',')
        cout << *s++;
    cout << "=" << t << ",";
    _dbg(s + 1, ta...);
}
template<typename T1, typename T2>
ostream&
operator<<(ostream& os, const pair<T1, T2>& p)
{
    return os << "{" << p.first << "," << p.second << "}";
}
template<typename T>
ostream&
operator<<(ostream& os, const vector<T>& v)
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it)
        {
            if (it != v.begin())
                os << ",";
            os << *it;
        }
    return os << "}";
}
template<typename T1, typename T2>
ostream&
operator<<(ostream& os, const map<T1, T2>& mp)
{
    os << "{";
    for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it != mp.begin())
                os << ",";
            os << *it;
        }
    return os << "}";
}
template<typename T>
ostream&
operator<<(ostream& os, const set<T>& s)
{
    os << "{";
    for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (it != s.begin())
                os << ",";
            os << *it;
        }
    return os << "}";
}
template<typename T>
ostream&
operator<<(ostream& os, const multiset<T>& s)
{
    os << "{";
    for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (it != s.begin())
                os << ",";
            os << *it;
        }
    return os << "}";
}
template<size_t N>
ostream&
operator<<(ostream& os, const bitset<N>& bs)
{
    os << "{";
    for (size_t i = 0; i < N; ++i)
        {
            cout << bs[i];
        }
    return os << "}";
}

#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define reunique(x) (x).resize(std::unique(all(x)) - (x).begin())
#define forn(x, y) for (ll x = 0; x < (ll)(y); ++x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pss = pair<string, string>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;

using namespace std;

int
gcd(int a, int b)
{
    while (b)
        {
            a %= b;
            swap(a, b);
        }
    return a;
}
void
solve()
{
    int t;
    cin>> t;
    forn(z,t)
    {
        ll ang;
        cin >> ang;
        ll ans = 180/gcd(ang,180);
        double alph = double(ans-2)/ans*180;
        while(alph < ang)
        {
            ++ans;
            alph = double(ans-2)/ans*180;
        }
        cout  << ans << endl;
        
    }

        
        
        
}

int
main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        {
            cout << "test " << i << endl;
            solve();
            cout << endl;
        }
#else
    solve();
#endif
    return 0;
}