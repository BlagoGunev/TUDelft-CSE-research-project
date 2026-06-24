/*
Created by :- Mayur
Created on :- 2021-11-21 23:25:48
*/
#include <bits/stdc++.h>

using namespace std;

bool bsearch(long long int mid, long long int k, long long int x)
{
  long long int temp = 0;
  temp = (min(mid, k) * (min(mid, k) + 1)) >> 1;
  mid -= min(mid, k);
  long long int n = mid;
  long long int a = k - 1;
  long long int d = -1;
  long long int ans = mid * (2 * a + (n - 1) * d);
  ans >>= 1;
  return ((temp + ans) < x ? true : false);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt = 1;
  std::cin >> tt;
  while (tt--)
  {
    // bsearch on answer
    long long int k, x, s = 1, e;
    cin >> k >> x;
    e = (2 * k) - 1;
    while (s < e)
    {
      long long int mid = (s + e) >> 1;
      if (bsearch(mid, k, x))
      {
        s = mid + 1;
      }
      else
        e = mid;
    }
    cout << s << '\n';
  }
  return 0;
}