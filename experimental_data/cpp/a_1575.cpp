#include <bits/stdc++.h>
using ll = long long;
using std::cin;
using std::cout;
using std::endl;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;

void solve([[maybe_unused]] int CASE)
{
  int n, m;
  cin >> n >> m;
  std::vector<std::string> vs(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> vs[i];
  }
  std::vector<int> iota(n);
  std::iota(iota.begin(), iota.end(), 0);
  std::sort(iota.begin(), iota.end(), [&](auto i, auto j)
            {
              const auto &s = vs[i];
              const auto &t = vs[j];
              for (int k = 0; k < m; ++k)
              {
                if (s[k] != t[k])
                {
                  if (k & 1)
                    return s[k] > t[k];
                  else
                    return s[k] < t[k];
                }
              }
              return true;
            });
  for (int i = 0; i < n; ++i)
  {
    cout << iota[i] + 1 << " \n"[i + 1 == n];
  }
}

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int kkt = 1;
  // cin >> kkt;
  for (int jupi = 1; jupi <= kkt; jupi++)
    solve(jupi);
  return 0;
}