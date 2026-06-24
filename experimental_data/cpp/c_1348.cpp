#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i<(b); ++i)
#define RFOR(i, b, a) for (int i = (b)-1; i>=(a); --i)
#define FILL(a, b) memset(a, b, sizeof(a))

void dout() { cerr << endl; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(ALL(s));
    string ans;
    int i = 0;
    if (s[i + k - 1] != s[0])
    {
        cout << s[i + k - 1] << "\n";
        return;
    }
    cout << s[0];
    if (s[k] != s.back())
    {
        FOR(i, k, SZ(s))
            cout << s[i];
    }
    else
    {
        int cnt = (SZ(s) - 1) / k;
        FOR(i, 0, cnt)
            cout << s.back(); 
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}