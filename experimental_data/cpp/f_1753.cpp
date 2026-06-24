#include <bits/stdc++.h>



using namespace std;



const int N = (int) 1e6 + 7;



unsigned long long C = -1;



struct MexKeeper

{

  int cnt[N];

  unsigned long long mask[N];





  void add(int x)

  {

    x--;

    cnt[x]++;



    mask[x / 64] += (cnt[x] == 1) * (1ULL << (x % 64));

  }



  void del(int x)

  {

    x--;

    cnt[x]--;



    mask[x / 64] -= (cnt[x] == 0) * (1ULL << (x % 64));

  }



  int get()

  {

    int sol = 0;

    while (mask[sol / 64] == -1)

    {

      sol += 64;

    }

    while (cnt[sol])

    {

      sol++;

    }

    return sol + 1;

  }

};



MexKeeper pl;

MexKeeper ng;

int n;

int m;

int k;

int t;



int main()

{

#ifdef ONPC

  freopen ("input.txt", "r", stdin);

#endif // ONPC



#ifndef ONPC

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#endif // ONPC



  cin >> n >> m >> k >> t;

  t++;

  vector<vector<int>> vals(n * m);

  int cu = 0;

  for (int i = 0; i < k; i++)

  {

    int x, y, w;

    cin >> x >> y >> w;

    if (abs(w) > (int) 1e6) continue;

    cu++;

    x--;

    y--;

    int code = x * m + y;

    vals[code].push_back(w);

  }

  vector<pair<int, int>> start_cells;

  for (int i = 0; i < n; i++)

  {

    for (int j = 0; j < m; j++)

    {

      if (min(i, j) == 0)

      {

        start_cells.push_back({i, j});

      }

    }

  }

  int sol = 0;

  auto add = [&] (int i, int j)

  {

    for (auto &val : vals[i * m + j])

    {

      if (val > 0)

      {

        pl.add(val);

      }

      else

      {

        ng.add(-val);

      }

    }

  };

  auto del = [&] (int i, int j)

  {

    for (auto &val : vals[i * m + j])

    {

      if (val > 0)

      {

        pl.del(val);

      }

      else

      {

        ng.del(-val);

      }

    }

  };



  for (auto &start : start_cells)

  {

    int ri = start.first;

    int ci = start.second;

    int l = 0;

    int r = 0;

    int last = min(n - 1 - ri, m - 1 - ci);





    if (t == 2)

    {

      sol += last + 1;

      continue;

    }

/**    for (int k1 = 0; k1 <= last; k1++)

    {

      for (int k2 = k1; k2 <= last; k2++)

      {

        int r1 = ri + k1;

        int c1 = ci + k1;

        int r2 = ri + k2;

        int c2 = ci + k2;

        pl.clr();

        ng.clr();

        for (int r = r1; r <= r2; r++)

        {

          for (int c = c1; c <= c2; c++)

          {

            add(r, c);

          }

        }

        if (pl.get() + ng.get() >= t)

        {

          sol++;

        }

      }

    }



    continue;*/

    add(ri, ci);

    while (1)

    {

      if (pl.get() + ng.get() >= t)

      {

        /// found the first r that works for this l

        sol += last - r + 1;

        {

          for (int j = ci + l; j <= ci + r; j++)

          {

            del(ri + l, j);

          }

          for (int i = ri + l + 1; i <= ri + r; i++)

          {

            del(i, ci + l);

          }

        }

        l++;

        continue;

      }

      if (r == last)

      {

        break;

      }

      {

        for (int i = ri + l; i <= ri + r; i++)

        {

          add(i, ci + r + 1);

        }

        for (int j = ci + l; j <= ci + r + 1; j++)

        {

          add(ri + r + 1, j);

        }

      }

      r++;

    }



    /**

    r + k, c + k

    **/



    for (int i = ri + l; i <= ri + r; i++)

    {

      for (int j = ci + l; j <= ci + r; j++)

      {

        del(i, j);

      }

    }

  }

  cout << sol << "\n";

  return 0;

}