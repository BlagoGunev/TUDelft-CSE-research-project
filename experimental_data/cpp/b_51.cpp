#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

#define sz(c) ((int) (c).size ())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fore(i, c) for (typeof ((c).begin ()) i = (c).begin (); i != (c).end (); ++i)

bool readtag(string &s)
{
  s.clear();
  char c;
  while (!feof(stdin) && c != '<') c = getchar();
  while (!feof(stdin) && c != '>') 
  {
    if (isalpha(c) || c == '/') s += c;
    c = getchar();
  }
  return !s.empty();
}

int main ()
{
  string t;
  vector <int> a;
  vector <int> res;
  while (readtag(t))
  {
    if (t == "table")
      a.pb(0);
    else if (t == "/table")
    {
      if (!a.empty()) 
      {
        res.pb(a.back());
        a.pop_back();
      }
    }
    else if (t == "td")
    {
      if (!a.empty()) ++a[sz(a) - 1];
    }
  }
  sort(res.begin(), res.end());
  for (int i = 0; i < sz(res); ++i)
    printf("%d%c", res[i], " \n"[i + 1 == sz(res)]);
  return 0;
}