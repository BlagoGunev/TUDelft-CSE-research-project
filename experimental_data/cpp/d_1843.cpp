#include<bits/stdc++.h>
using namespace std;

#define ANS cout<<"Answer: ";
#define LOOP cout<<"LOOOOOOP!";
#define show(a)  fo(i,1,n)cout<<a[i]<<" ";
#define DIV cout<<"----------------------------------"<<endl;
#define ___ cout<<endl
#define rt return
#define cst const
#define XJ 0
#define HY 1

#define fo(i,a,b)    for (int i=a;i <= b ; i++)
#define fo_(i,a,b)   for (int i=a;i >= b ; i--)
#define ms(a,b)                     memset(a,b,sizeof(a))
#define all(x)                     (x).begin(), (x).end()
#define sum(x)                     (accumulate(all(x),0))
#define L(x)                                 (x).length()
#define S(x)                              int((x).size())
#define dc(a)                              (int(a-'a')+1)
#define lb(x)                                  ((x)&(-x))
#define pb(x)                             emplace_back(x)


#define V                           vector
typedef long long i64;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<i64, i64>pll;
typedef V<int> VI;
typedef V<pii> VII;
typedef V<string> VS;
typedef V<i64> VL;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<i64, i64>MLL;
typedef map<int, V<int>>MIV;
typedef queue<int>q;
typedef priority_queue<int, vector<int>, greater<int>> pq;

template<class T> void can(T& a) { cin >> a; }
template<class T, class...U>void can(T& a, U&...z) { can(a); can(z...); }
template<typename T> void read(T& a) {
    T x = 0, f = 1;char c = ' ';
    for (;!isdigit(c);c = getchar()) if (c == '-') f = -1;
    for (;isdigit(c);c = getchar()) x = x * 10 + c - '0';
    a = x * f;
}
/*......................*/
void out() { cout << endl; }
template<class T> void print(const T& a) { cout << a << " "; }
template<class T> void out(const T& t) { cout << t << endl; }
template<class T, class...L>void print(const T& a, const L&... b) { print(a);print(b...); }
template<class T, class L>void out(const T& a, const L& b) { print(a);out(b); }
template<class T>void print(const V<T>& vec) { if (vec.empty())return; for (auto x : vec) { print(x); } }
/*.....................*/
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;const double eps = 1e-9;
/*.....................*/
const int nn = 2e5 + 5;
/*.....................*/
int t, n, m;
string s;

vector<int>g[nn];
i64 f[nn];
void d1(int u, int pa)
{
    if (g[u].size() == 1 & u != 1)
        f[u] = 1;
    for (auto v : g[u])
        if (v ^ pa)
        {
            d1(v, u);
            f[u] += f[v];
        }
}
void AmoureuxXJ()
{
    int n;cin >> n;
    fo(i, 1, n)g[i].clear(), f[i] = 0;
    fo(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d1(1, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;cin >> u >> v;
        i64 l = f[u], r = f[v];
        // out("??", l * r);
        out(l* r);

    }

}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int _;
    for (can(_);_--;)
        AmoureuxXJ();
    /*                              ======
       ====       ====                ====
        ====     ====                 ====
         ====   ====                  ====
          ========                    ====
        ====   ====                   ====
      ====        =====     ===       ====
     ====           ====      ============
                                 =====
    */

    return XJ;
}