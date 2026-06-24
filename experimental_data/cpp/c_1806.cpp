#include <bits/stdc++.h>
 
using namespace std;

namespace ACM
{
    #define NO return cout << "NO\n", void()
    #define YES return cout << "YES\n", void()

    typedef long long ll;        
    typedef unsigned long long ull; 
    typedef double db;
    typedef pair<int, int> pii;
    typedef pair<ll, ll> pll;
    typedef pair<ull, ull> pull;    
    typedef vector<int> vi;
    typedef vector<ll> vl;
    typedef vector<pii> vii;
    typedef map<int, int> mii;
    const int INF = 0x3f3f3f3f;
    const db eps = 1e-6;
    
    //__int128
    // ostream& operator<<(ostream& os, __int128_t T) { if (T<0) {os<<"-"; T = -T;} if (T>=10) os<<T/10; return os<<int(T%10);}
    // istream& operator>>(istream& os, __int128_t &T) { T=0; __int128 f=1; char ch; cin >> ch; if (ch=='-'){f=-1; cin >> ch;} while(ch>='0'&&ch<='9') { T=T*10+ch-'0'; cin.get(ch); } T*=f; return os;}
    istream & operator>> (istream &in, pii &A){ return in >> A.first >> A.second; }
    ostream & operator<< (ostream &out, pii &A){ return out << A.first << ' ' << A.second; }

    //算法
    ll ksm(ll a, ll b, const ll& mod) {ll ans = 1; a %= mod; if(a==0)return 0; while(b){if (b&1) ans = ans*a%mod; a = a*a%mod; b >>= 1;} return ans;} //快速幂
    inline ll inv(const ll& x, const ll& p) {return ksm(x, p - 2, p);}   //求逆元, p为模
    inline ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
    inline ll lcm(ll a, ll b) {return a * b / gcd(a, b);}
    inline int lowbit(const int& x) {return x & -x;} //返回二进制最低为1时
};
using namespace ACM;
/*************************************************/
const int N = 4e5 + 10;
int n, a[N], m;

void solve()
{
    ll res = 0;
    cin >> n;
    m = n << 1;
    for (int i = 1; i <= m; ++i) cin >> a[i];

    if (n == 1) res = abs(a[2] - a[1]);
    else 
    {
        for (int i = 1; i <= m; ++i) res += abs(a[i]);
        if (n == 2)
        {
            ll temp = 0;
            for (int i = 1; i <= m; ++i) temp += abs(2 - a[i]);
            res = min(res, temp);
        }
        if (n % 2 == 0)
        {
            ll temp = 0;
            sort(a + 1, a + m + 1);
            for (int i = 1; i <= m - 1; ++i) temp += abs(a[i] + 1);
            temp += abs(n - a[m]);
            res = min(res, temp);
        }
    }
    cout << res << '\n';
}   
 
int main(void)
{
    ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
*
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/