#include <bits/stdc++.h>
#define long long long
#define forip(n) for (long i = 1; i <= n; i++)
#define forjp(n) for (long j = 1; j <= n; j++)
#define fori(n) for (long i = 0; i < n; i++)
#define forj(n) for (long j = 0; j < n; j++)
#define rofi(n) for (long i = n - 1; i >= 0; i--)
#define rofj(n) for (long j = n - 1; j >= 0; j--)
using namespace std;
/* REQUIRED */ const long N = 2e3 + 4;

// #define TEST
#ifdef TEST
#define sep cout << "---------\n"
#define say(n) cout << n << ' ';
#define sayln(n) cout << n << '\n';
#define val(n) cout << #n << " = " << n << ' ';
#define valln(n) cout << #n << " = " << n << '\n'
#else
#define sep
#define say(n)
#define sayln(n)
#define val(n)
#define valln(n)
#endif

// 无权树 G
// s(v, u) 是树的 v -> u 路径组成的字符串
// 要在树中找到最大子回文串？？

// 只能 n^2
int t, n;
char s[N];
vector<int> e[N];

// 数据读入
inline void read() {
  cin >> n >> s;
  forip(n) e[i].clear();
  fori(n - 1) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
}

// 如果候选 s1 包含 s2，那么 s2 可忽略
// 但这样 s 有非常多种组合方式

// 以每个节点为根都可以建立字典树
// 目标就变成找到任意两个字典树之间的最长匹配串
// 优化成只用叶子结点建立字典树没有意义
// 但匹配串可以断裂

// 对于单个字符串
// 可以 dp 在 n^2 时间内找到最大回文子序列
// 但对于整个树来说有非常多种回文子序列

// HINT // 整体使用 dp

// dp[i][j] 指从 i 到 j 的路径的最大回文子序列长度
int dp[N][N];

// 起初 dp[i][i] 都是 1
// 对于所有长度为 k 的边，
// 如果两头相同，则结果为去头去尾边结果 + 2
// 否则结果为其包含的两个长度为 k - 1 的边结果的最大值

// HINT // 以每个点为根 dfs 出路径缩窄数组 go
// go[i][j] 表示从 i 到 j 的路径的第二个点
int go[N][N];

// TAKEAWAY // 有复杂度剩余时不妨想下如何最简单地用掉
// 例如本题中随机取一个为根时，有 n 的剩余复杂度
// 如果想(最近公共祖先，就是复杂的用法
// 如果想以每个节点为根遍历一次
// 或者只预处理出根到其他点的数据
// 就是简单的用法

// path[i] 包含长度为 i 的所有路径
vector<pair<int, int>> path[N];

// 每个测试点之后要清除 path
inline void clear_path() { forip(n) path[i].clear(); }

// 对一个节点 dfs
inline void dfs(int root, int fa, int x, int len) {
  path[len].emplace_back(root, x);
  go[x][root] = fa;
  for (int x1 : e[x])
    if (x1 != fa)
      dfs(root, x, x1, len + 1);
}

// 对每个节点 dfs
inline void dfs_all() { forip(n) dfs(i, 0, i, 1); }

// 对每个长度的路径分别 dp
// 这点我在第一次提示后就想对了
inline void do_dp() {
  forip(n) {
    for (auto p : path[i]) {
      int u = p.first, v = p.second;
      if (i == 1) {
        dp[u][v] = 1;
      } else if (i == 2) {
        dp[u][v] = 1 + (s[u - 1] == s[v - 1]);
      } else {
        dp[u][v] = dp[go[u][v]][go[v][u]] + 2 * (s[u - 1] == s[v - 1]);
        dp[u][v] = max(dp[u][v], dp[go[u][v]][v]);
        dp[u][v] = max(dp[u][v], dp[u][go[v][u]]);
      }
      val(u);
      val(v);
      val(i);
      val(go[u][v]);
      val(go[v][u]);
      val(dp[u][v]);
      val(s[u]);
      valln(s[v]);
    }
  }
}

// 获取答案
inline int ans() {
  int f = 0;
  forip(n) forjp(n) f = max(f, dp[i][j]);
  return f;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  fori(t) {
    read();
    clear_path();
    dfs_all();
    do_dp();
    cout << ans() << endl;
  }
  return 0;
}