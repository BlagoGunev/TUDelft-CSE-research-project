#include <bits/stdc++.h>

#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;

const int MAXN = 256;

vector<pair<int, int>> edges;
int A[MAXN], B[MAXN];
int N;
int wo[8];
bool used[MAXN];
bool CT[MAXN];

bool bit(int x, int p)
{
  return x & (1 << p);
}

void solve()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      int x;
      cin >> x;
      A[i] += (x << j);
    }
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      int x;
      cin >> x;
      B[i] += (x << j);
    }
  }

  for (int i = 0; i < N; i++)
  {
    if (A[i] == 0)
    {
      used[i] = true;
    }
    B[i] &= A[i];
  }

  fill(wo, wo + 8, -1);
  used[0] = true;
  wo[7] = 0;
  int cnt = 1;

  while (cnt < N)
  {
    vector<int> V;
    for (int i = 1; i < 8; i++)
    {
      if (wo[i] != -1)
      {
        V.push_back(i);
      }
    }
    vector<int> dp(8, -1);
    for (int msk = 0; msk < (1 << sz(V)); msk++)
    {
      int cur = 0;
      for (int i = 0; i < sz(V); i++)
      {
        if (bit(msk, i))
        {
          cur |= V[i];
        }
      }
      if (dp[cur] == -1 || __builtin_popcount(dp[cur]) > __builtin_popcount(msk))
      {
        dp[cur] = msk;
      }
    }

    // cout << "X: ";
    // for (int i = 0; i < N; i++)
    // {
    //   int x;
    //   if (!used[i])
    //     x = -1;
    //   else if (CT[i])
    //     x = B[i];
    //   else
    //     x = A[i];
    //   cout << ' ' << x;
    // }
    // cout << '\n';
    // cout << "dp: ";
    // for (int x = 1; x <= 7; x++)
    // {
    //   cout << ' ' << (dp[x] == -1 ? -1 : __builtin_popcount(dp[x]));
    // }
    // cout << '\n';

    bool done = false;
    for (int val = 1; val <= 7; val++)
    {
      if (dp[val] == -1)
      {
        continue;
      }
      vector<int> group;
      int victim = -1;
      set<int> S;

      for (int i = 0; i < N; i++)
      {
        if (A[i] == val && !used[i])
        {
          group.push_back(i);
          if (B[i] == 0 || B[i] == A[i] || wo[B[i]] != -1 || S.count(B[i]))
          {
            victim = i;
          }
          S.insert(B[i]);
        }
      }
      if (group.empty())
      {
        continue;
      }

      if (victim != -1)
      {
        for (int j = 0; j < sz(V); j++)
        {
          if (bit(dp[val], j))
          {
            edges.push_back({wo[V[j]], victim});
          }
        }
        CT[victim] = false;
        wo[A[victim]] = victim;

        for (int x : group)
        {
          used[x] = true;
          if (x != victim)
          {
            edges.push_back({victim, x});
            CT[x] = true;
            wo[B[x]] = x;
          }
        }
      }
      else
      {
        for (int x : group)
        {
          for (int j = 0; j < sz(V); j++)
          {
            if (bit(dp[val], j))
            {
              edges.push_back({wo[V[j]], x});
            }
          }
          CT[x] = true;
          used[x] = true;
          wo[B[x]] = x;
        }
      }
      done = true;
      break;
    }
    if (!done)
    {
      break;
    }
  }

  for (int i = 0; i < N; i++)
  {
    if (!used[i])
    {
      cout << "Impossible\n";
      return;
    }
  }

  cout << "Possible\n";

  for (int i = 0; i < N; i++)
  {
    cout << CT[i] << " \n"[i == N - 1];
  }

  cout << sz(edges) << '\n';
  for (auto [u, v] : edges)
  {
    cout << u + 1 << ' ' << v + 1 << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt = 1;
  // cin >> tt;

  while (tt--)
  {
    solve();
  }

  return 0;
}