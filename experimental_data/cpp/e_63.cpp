#include <string.h>

#include <algorithm>

#include <bitset>

#include <cassert>

#include <cmath>

#include <complex>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <ctime>

#include <deque>

#include <fstream>

#include <functional>

#include <iomanip>

#include <iostream>

#include <map>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <string>

// #include <unordered_map>

// #include <unordered_set>

#include <utility>

#include <vector>



#define pb push_back

#define pf push_front

#define mp make_pair



using namespace std;

typedef long long LL;

typedef unsigned long long ULL;

typedef pair<int, int> pii;

typedef pair<LL, LL> pll;



inline void EnableFileIO(const string& fileName) {

  if (fileName.empty()) return;

#ifdef ONLINE_JUDGE

  freopen((fileName + ".in").c_str(), "r", stdin);

  freopen((fileName + ".out").c_str(), "w", stdout);

#endif

  return;

}



const int INF = (1 << 30) - 1;

const LL LINF = (1LL << 61) - 1;

const double EPS = 1e-10;

const int N = 20, MSK = 1 << N;



int dp[MSK];

vector<vector<int> > line;



bool dfs(int mask) {

  if(mask==0) return 0;

  if (dp[mask] == -1) {

    bool flag = false;



    for (int i = 0; i < 15; i++) {

      for (int j = 0; j < line[i].size(); j++) {

        int nmask = mask;

        for (int k = j; k < line[i].size(); k++) {

          if ((~nmask) >> line[i][k] & 1) break;

          nmask ^= 1 << line[i][k];



          if (!dfs(nmask)) {

            flag = true;

            break;

          }

        }

        if (flag) break;

      }

      if (flag) break;

    }



    dp[mask] = flag;

  }

  return dp[mask];

}



int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);

  // printf("Hello, world!\n");

  EnableFileIO("");



  line.pb({0, 1, 2}), line.pb({3, 4, 5, 6}), line.pb({7, 8, 9, 10, 11}),

      line.pb({12, 13, 14, 15}), line.pb({16, 17, 18}), line.pb({0, 3, 7}),

      line.pb({1, 4, 8, 12}), line.pb({2, 5, 9, 13, 16}),

      line.pb({6, 10, 14, 17}), line.pb({11, 15, 18}), line.pb({7, 12, 16}),

      line.pb({3, 8, 13, 17}), line.pb({0, 4, 9, 14, 18}),

      line.pb({1, 5, 10, 15}), line.pb({2, 6, 11});



  memset(dp, -1, sizeof dp);

  int stat = 0;

  for (int i = 0; i < 19; i++) {

    char c;

    cin >> c;

    stat <<= 1;

    if (c == 'O') stat ^= 1;

  }



  if (dfs(stat)) {

    cout << "Karlsson" << endl;

  } else {

    cout << "Lillebror" << endl;

  }



  return 0;

}