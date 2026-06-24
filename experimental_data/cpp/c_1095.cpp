#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main()
{
  int TC = 1;
  //  cin >> TC;
  for (int tc = 1; tc <= TC; ++tc)
    {
      int N, K;
      cin >> N >> K;
      if (K > N || __builtin_popcount(N) > K) cout << "NO" << endl;
      else
        {
          vector<int> bits(32);
          int higher = 0;
          for (int i = 0; i < 32; ++i)
            {
              if (N & (1 << i)) {
                bits[i] = 1;
                higher = i;
              }
            }
          K -= __builtin_popcount(N);
          while (higher && K)
            {
              if (!bits[higher])
                {
                  --higher;
                  continue;
                }
              for (int i = bits[higher]; i > 0; --i)
                {
                  if (K - i >= 0)
                    {
                      bits[higher] -= i;
                      bits[higher - 1] += 2 * i;
                      K -= i;
                      break;
                    }
                }
              --higher;
            }
          if (K) cout << "NO" << endl;
          else
            {
              cout << "YES" << endl;
              for (int i = 0; i < 32; ++i)
                {
                  if (bits[i])
                    {
                      for (int j = 0; j < bits[i]; ++j)
                        {
                          cout << (1 << i) << " ";
                        }
                    }
                }
            }
        }
    }
  return 0;
}