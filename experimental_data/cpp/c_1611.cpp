#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iterator>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <list>
#include <map>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
 
#define watch(x) cout << (#x) << " is " << (x) << endl
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define make_unique(x) sort(ALL((x))); (x).resize(unique(ALL((x))) - (x).begin())
#define min(a,b,...) min({a,b,__VA_ARGS__})
#define max(a,b,...) max({a,b,__VA_ARGS__})
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <char> vc;
typedef vector< vector <int> > vii;
//const int INF = ...;
//const int MOD = (int)(1e9 + 7);


void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i=0;i<n;++i)
        cin >> a[i];
    if (a[n-1]!=n && a[0]!=n) {
        cout << -1;
        return;
    }
    if (a[0]==n) {
        for (int i=n-1;i>=1;--i)
            cout << a[i] << ' ';
        cout << a[0];
        return;
    }
    for (int i=n-2;i>=0;--i)
        cout << a[i] << ' ';
    cout << a[n-1];
}
 
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
        cout << '\n';
    }
}