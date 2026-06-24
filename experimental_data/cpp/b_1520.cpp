#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include "myheader.h"
#endif
using namespace std;
// #pragma GCC optimize("O1")
// #pragma GCC optimize("O2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
void input() {return;}
template<typename T1, typename... T2>
    void input(T1 & x, T2&... args){((cin >> x), input(args...));}
void wrt() { cout << "\n"; return;}
template<typename T1, typename... T2>
    void wrt(T1 x, T2... args){((cout << x << ' '), wrt(args...));}
template<typename T> void inputlst(T & lst, int x, int y)
    { for(int i = x ; i < y; i++ ) cin >> lst[i]; }
template<typename T> void printlst(T & lst, int x, int y)
    { for(int i = x ; i < y; i++ ) cout << lst[i] << ' '; wrt(); }
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define tests int test; cin >> test; while(test--)
#define fora(i, x, y) for (ll i = x; i < y; ++i)
#define ford(i, x, y) for (ll i = x; i >= y; --i)
#define all(lst) lst.begin(), lst.end()
#define rall(lst) lst.rbegin(), lst.rend()
#define ceil(a, b) ((a + b - 1) / (b))
#define sum(lst) accumulate(all(lst), 0ll)
#define CountVal(lst, val) count(all(lst), val)
#define sortlst(lst) sort(all(lst))
#define rsortlst(lst) sort(rall(lst))
#define setbits(n) __builtin_popcount(n)
#define sortarr(x, n) sort(x, x + n)
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vl> vovl;
typedef vector<vi> vovi;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<ll, ll> ml;
typedef map<int, int> mi;
const ll inf = INT64_MAX, MOD = 1e9 + 7, N = 1e5;
int main(int argc, char const *argv[])
{
    boost;
    tests
    {
        ll n, minVal = 9, cnt = 0, ans = 0, temp;
        input(n);
        temp = n;
        while (n)
        {
            cnt++;
            minVal = min(minVal, n % 10);
            n /= 10;
        }
        ans += (cnt - 1) * 9;
        string s;
        while(cnt--){
            s += '1';
        }
        ll r = stoi(s);
        ll temp1 = r;
        while (r <= temp)
        {
            ans++;
            r += temp1;
        }
        wrt(ans);
    }
    return 0;
}