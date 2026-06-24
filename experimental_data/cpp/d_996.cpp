#include <bits/stdc++.h>
/*
          _   _     _____    __  __    ____      ______    ______      ___     ______
         /'\_/`\  /\  __`\  /\ \/\ \  /\  _`\   /\__  _\  /\  _  \    /'___\  /\  _  \
        /\      \ \ \ \/\ \ \ \ \ \ \ \ \,\L\_  \/_/\ \/  \ \ \L\ \  /\ \__/  \ \ \L\ \
        \ \ \__\ \ \ \ \ \ \ \ \ \ \ \ \/_\__ \    \ \ \   \ \  __ \ \ \ ,__\  \ \  __ \
         \ \ \_/\ \ \ \ \_\ \ \ \ \_/ \  /\ \L\ \   \ \ \   \ \ \/\ \ \ \ \_/   \ \ \/\ \
          \ \_\\ \_\ \ \_____\ \ `\___/  \ `\____\   \ \_\   \ \_\ \_\ \ \_\     \ \_\ \_\
           \/_/ \/_/  \/_____/  `\/__/    \/_____/    \/_/    \/_/\/_/  \/_/      \/_/\/_/
          __ __        __ __        __ __        __ __        __ __        __ __        __ __
         _\ \\ \__    _\ \\ \__    _\ \\ \__    _\ \\ \__    _\ \\ \__    _\ \\ \__    _\ \\ \__
        /\__  _  _\  /\__  _  _\  /\__  _  _\  /\__  _  _\  /\__  _  _\  /\__  _  _\  /\__  _  _\
        \/_L\ \\ \L_ \/_L\ \\ \L_ \/_L\ \\ \L_ \/_L\ \\ \L_ \/_L\ \\ \L_ \/_L\ \\ \L_ \/_L\ \\ \L_
          /\_   _  _\  /\_   _  _\  /\_   _  _\  /\_   _  _\  /\_   _  _\  /\_   _  _\  /\_   _  _\
          \/_/\_\\_\/  \/_/\_\\_\/  \/_/\_\\_\/  \/_/\_\\_\/  \/_/\_\\_\/  \/_/\_\\_\/  \/_/\_\\_\/
             \/_//_/      \/_//_/      \/_//_/      \/_//_/      \/_//_/      \/_//_/      \/_//_/
*/
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define ld long double
#define readi(x) scanf("%d", & x);
#define readl(x) scanf("%lld", & x);
#define reads(x) scanf("%s", & x);
#define readc(x) scanf("%c", & x);
#define readd(x) scanf("%lf", & x);
#define to__string(x) static_cast < std::ostringstream & > ((std::ostringstream() << std::dec << x)).str()
#define bitcount(n) __builtin_popcountll(n)
#define SIZE(x)(ll) x.size()
#define lp(i, a, n) for (int(i) = (a); (i) <= (int)(n); ++(i))
#define lpd(i, n, a) for (int(i) = (n); (i) >= (a); --(i))
#define pii pair < ll, ll >
#define piii pair < pii, ll >
#define EPS (1e-15)
#define mod 1000000007
#define f first
#define s second

using namespace std;
const int N = 1000;
const int LOGN = (int) log2(N) + 2;
int SQRTN = (int) sqrt(N) + 7;
const ll infi = 1ll << 60;
ll n, m, k, a, b, x, y, ans, arr[N], t;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    io;
    cin >> n;
    n += n;
    lp (i, 1, n) {
        cin >> arr[i];
    }
    lp (i, 1, n) {
        if (arr[i] != arr[i + 1]) {
            ll cur = arr[i], idx = -1;
            lp (j, i + 2, n) {
                if (arr[j] == cur) {
                    idx = j;
                    break;
                }
            }
            while (idx != i + 1) {
                swap(arr[idx], arr[idx - 1]);
                ++ans;
                --idx;
            }
        }
        ++i;
    }
    cout << ans << endl;
    return 0;
}