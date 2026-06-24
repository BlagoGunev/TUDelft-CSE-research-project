#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

#ifdef DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

const int MaxN = 100005, MaxC = 0x3F3F3F3F, NA = -1;

pair <int, int> solve (int a, int b)
{
 pair <int, int> res;
 res.first = res.second = 0;
 if (a < 0)
  return res;

 res = solve (a - 1, b & ((1 << (a << 1)) - 1));
 switch (b >> (a << 1))
 {
  case 0:
   swap (res.first, res.second);
   break;
  case 1:
   res.first += (1 << a);
   break;
  case 2:
   res.first += (1 << a);
   res.second += (1 << a);
   break;
  case 3:
   swap (res.first, res.second);
   res.second += (1 << a);
   res.first ^= (1 << a) - 1;
   res.second ^= (1 << a) - 1;
   break;
  default:
   assert (false);
   break;
 }

 return res;
}

int main (void)
{
 int a, b;

 while (scanf (" %d %d", &a, &b) != EOF)
 {
  pair <int, int> k = solve (a, b);
  printf ("%d %d\n", k.first, k.second);
 }

 return 0;
}