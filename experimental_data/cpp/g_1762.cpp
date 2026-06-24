#include <bits/stdc++.h>



using namespace std;



const int N = (int) 3e5 + 7;

int n;

int a[N];

int f[N];



void print(vector<int> v)

{

  cout << " ---> ";

  for (auto &x : v)

  {

    cout << x << " ";

  }

  cout << "\n";

}



signed main()

{

#ifdef ONPC

  freopen ("input.txt", "r", stdin);

#endif // ONPC

#ifndef ONPC

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#endif // ONPC



  int tests;

  cin >> tests;



  for (int tc = 1; tc <= tests; tc++)

  {

    cin >> n;

    for (int i = 1; i <= n; i++)

    {

      f[i] = 0;

    }

    for (int i = 1; i <= n; i++)

    {

      cin >> a[i];

      assert(1 <= a[i] && a[i] <= n);

      f[a[i]]++;

    }



    int maxf = *max_element(f + 1, f + n + 1);

    if (maxf > n + 1 - maxf)

    {

      cout << "NO\n";

      continue;

    }

    cout << "YES\n";

    vector<int> major, minor, sol;

    for (int i = 1; i <= n; i++)

    {

      if (major.empty())

      {

        assert(minor.empty());

        major.push_back(i);

        continue;

      }

      assert(!major.empty());

      if (a[i] == a[major[0]])

      {

        major.push_back(i);

      }

      else

      {

        minor.push_back(i);

      }

      if ((int) major.size() == (int) minor.size())

      {

        /// the last added is a minor

        for (int i = 0; i < (int) major.size() - 1; i++)

        {

          sol.push_back(major[i]);

          sol.push_back(minor[i]);

        }

        sol.push_back(major.back());

        major.clear();

        assert(minor.back() == i);

        minor.clear();

        major.push_back(i);

        minor.clear();

      }

    }

    assert(!major.empty());

    while (!sol.empty() && (int) major.size() > (int) minor.size())

    {

      int i = sol.back();

      if (a[i] == a[major[0]])

      {

        major.push_back(i);

      }

      else

      {

        minor.push_back(i);

      }

      sol.pop_back();

    }

    if ((int) major.size() == 1 + (int) minor.size())

    {

      assert(sol.empty());

    }

    else

    {

      assert((int) major.size() == (int) minor.size());

    }

    sort(major.begin(), major.end());

    sort(minor.begin(), minor.end());

    /*print(sol);

    print(major);

    print(minor);*/

    if ((int) major.size() == (int) minor.size())

    {

      assert((int) major.size() > 0);

      assert((int) minor.size() > 0);

      if (!sol.empty() && a[sol.back()] == a[minor[0]])

      {

        swap(minor, major);

      }

      if (!sol.empty())

      {

        assert(a[sol.back()] != a[minor[0]]);

      }

      assert(a[minor[0]] != a[major[0]]);

      sol.push_back(minor[0]);

      minor.erase(minor.begin());

    }

    assert((int) major.size() == 1 + (int) minor.size());

    for (int i = 0; i < (int) major.size() - 1; i++)

    {

      sol.push_back(major[i]);

      sol.push_back(minor[i]);

    }

    sol.push_back(major.back());

    assert((int) sol.size() == n);

    for (auto &i : sol)

    {

      cout << i << " ";

    }

    cout << "\n";

  }



  return 0;

}



/**



**/