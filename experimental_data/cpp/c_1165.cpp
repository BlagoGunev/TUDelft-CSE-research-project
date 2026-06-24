#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pll = pair <llint,llint>;
using pss = pair <string,string>;
using vi = vector <int>;
using vb = vector <bool>;
using vll = vector <llint>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr
// inline functions



int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, i = 0;
    string s, ans;
    cin >> n >> s;

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (ans.empty())
            ans += s[t1], ++i;
        else
        {
            if (i&1 && s[t1] != ans.back())
                ans += s[t1], ++i;
            else if (!(i&1))
                ans += s[t1], ++i;
        }
    }

    n = ans.size();
    if (n&1) ans.pop_back();
    cout << s.size()-ans.size() << '\n' << ans << '\n';






































    return 0;
}