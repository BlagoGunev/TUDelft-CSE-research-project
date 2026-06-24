#include <algorithm>
#include <assert.h>
#include <bitset>
#include <complex>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef pair<LL, PLL> PLPLL;
typedef vector<PLL> VPLL;
typedef vector<std::string> VS;
typedef std::vector<LL>::iterator VLLitr;

#define arjun int main()
#define FOR(i, x, y) for (int i = (x); i < (y); ++i)
#define FORC(i, x, y,in) for (LL i = (x); i < (y); i = i+in)
#define RFOR(i, x, y) for (LL i = (x); i >= (y); i--)
#define FORO(it, c)                                                            \
  for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define pb(e) push_back(e)
#define mp make_pair
#define All(x) x.begin(), x.end()
#define fast                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
#define PI 3.14159265
#define RESET(a, b) memset(a, b, sizeof(a))

template <typename T> T maxm(T a, T b) { return (a > b) ? a : b; }
template <typename T> T minm(T a, T b) { return (a < b) ? a : b; }
template <typename T> T powe(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1)
      x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T> T power(T e, T n, T m) {
  T x = 1, p = e;
  while (n) {
    if (n & 1)
      x = (x * p) % m;
    p = (p * p) % m;
    n >>= 1;
  }
  return x;
}
template <typename T> T InverseEuler(T a, T m) {
  return (a == 1 ? 1 : power(a, m - 2, m));
}
template <typename T> T lcm(T a, T b) { return (a * (b / __gcd(a, b))); }

string StringToUpper(string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);
    return strToConvert;
}

string StringToLower(string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::tolower);
    return strToConvert;
}

LL MAX = (LL)(3*1e18);
LL MOD = (LL)(1e9+7);

#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

arjun {
    fast;
    string s;
    cin>>s;
    int ini = 97;
    int ans = 0;
    FOR(i,0,s.length()){
      ans+=min(abs((int)ini-97) + abs((int)s[i]-122)+1,min(abs(ini-122) + abs((int)s[i]-97)+1,abs((int)s[i] - ini)));
      //cout<<min(abs((int)ini-97) + abs((int)s[i]-122)+1,min(abs(ini-122) + abs((int)s[i]-97)+1,abs((int)s[i] - ini)))<<endl;
      ini = (int)s[i];
    }
    cout<<ans<<endl;
    return 0;  
}