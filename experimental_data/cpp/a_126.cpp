#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef long double real;

#ifdef DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

using namespace std;

const int MaxN = 1000006, NA = -1, MaxC = 0x3F3F3F3F;

int64 t0, t1, t2, x1, x2;

int main (void)
{
 int64 y1, y2, zp, zq, ry1, ry2, rzp, rzq;
 while (scanf (" " INT64 " " INT64 " " INT64 " " INT64 " " INT64 ,
  &t1, &t2, &x1, &x2, &t0) != EOF)
 {
// t1 y1 + t2 y2 >= t0 (y1 + y2)
// y1 (t1 - t0) >= y2 (t0 - t2)
// y2 (t2 - t0) >= y1 (t0 - t1)
  if (t0 == t2)
  {
   if (t1 == t2)
    printf (INT64 " " INT64 "\n", x1, x2);
   else
    printf ("0 " INT64 "\n", x2);
   continue;
  }
  ry1 = ry2 = 0;
  rzp = 1, rzq = 0;
  for (y1 = 0; y1 <= x1; y1++)
  {
   y2 = (y1 * (t0 - t1) + (t2 - t0) - 1) / (t2 - t0);
//   assert (y2 >= 0);
   if (0 <= y2 && y2 <= x2)
   {
    zp = t1 * y1 + t2 * y2;
    zq = y1 + y2;
    if (zp * rzq < rzp * zq || (zp * rzq == rzp * zq && ry1 + ry2 < y1 + y2))
    {
     rzp = zp;
     rzq = zq;
     ry1 = y1;
     ry2 = y2;
    }
   }
  }
  if (ry1 + ry2 == 0)
  {
   ry1 = 0;
   ry2 = x2;
  }
  assert (ry1 + ry2 > 0);
  printf (INT64 " " INT64 "\n", ry1, ry2);
 }
 return 0;
}