#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
#include <numeric>
#define all(x) (x).begin(),(x).end()
using namespace std;

using ll = long long;
using ld = long double;

//#define int ll
#define sz(x) ((int)(x).size())

using pii = pair<int,int>;
using tii = tuple<int,int,int>;

const int nmax = 1e6 + 5;
const int inf = 1e9 + 5;
int n, k, m, q;
vector<int> g[nmax];
int v[nmax];

static void testcase() {
   cin >> n >> m;
   cout << max(n, m) + 1 << '\n';
   return;
}

signed main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin >> t;
   for (int i = 0; i < t; i++)
      testcase();
}

/**
      Binecuvanteaza Doamne Ukraina.
-- 
*/