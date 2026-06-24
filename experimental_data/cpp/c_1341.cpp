#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
// #define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); //勿混用
// #define deBug
#define fr(abc, front, end) for (register int abc = (front); abc <= (end); ++abc)
#define rf(abc, front, end) for (register int abc = (end); abc >= (front); --abc)
#define mem(a, b) memset(a, b, sizeof(a))
template<class T> inline void Swap(T &z, T &o) { z^=o, o^=z, z^=o; }
template<class T> inline T Max(const T &z, const T &o) { return z > o ? z : o; }
template<class T> inline T Min(const T &z, const T &o) { return z < o ? z : o; }

#ifdef deBug
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define MAX 0x3f3f3f3f
#define int long long
#define ull unsigned long long
#define eb emplace_back()
#define pii pair<int, int>

namespace DEBUG {
#define debug(...) DEBUG::_debug(#__VA_ARGS__, __VA_ARGS__)
    inline void _debug(){cerr << "-------------------" << endl; }
    template <typename T> inline void _debug(const char* name, T _) 
    {cerr << name << '=' << _ << endl;}
    template <class First, class... Rest>
    inline void _debug(const char* name, First first, Rest... rest)
    { while (*name != ',') cerr << *name++;cerr << '=' << first << ",";
    _debug(name + 1, rest...); }
    template <typename T> ostream& operator<<(ostream& os, const vector<T>& V)
    { os << "[";for (const auto& vv : V) os << vv << ",";os << "]";return os; }
}
#endif
#ifndef IOS
namespace Read{
    static char fff, crh, mmu[40];
    template<class T> inline void rd(T &xxx){ xxx = 0;fff = 0,crh = getchar();
        while (!isdigit(crh)) fff |= (crh == '-'), crh = getchar();
        while (isdigit(crh)) xxx=xxx*10+(crh^48), crh = getchar();
        xxx = (fff?-xxx:xxx); }
    template<class T> inline void pr(T xxx){ if(!xxx){putchar('0');return;}
    static int ppp = 0; if(xxx<0){putchar('-');xxx=-xxx;} 
    do mmu[ppp++]=xxx%10+'0';while(xxx/=10); while(ppp) putchar(mmu[--ppp]); }
    #define Pr(a, b) pr(a), putchar(b)
    #define pu(z) putchar(z)
} using namespace Read;
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const int N = 2e5+10, M = 1e9+7;
int a[N];

inline void solve()
{
    int n; rd(n);
    fr (i, 1, n) rd(a[i]);
    a[0] = a[1];
    fr (i, 1, n) if (a[i] - a[i-1] >= 2) { puts("No"); return ; }
    puts("Yes");
}
signed main()
{
    // IOS
    int t; cin >> t;
    while (t--)
    solve();
    return 0;
}