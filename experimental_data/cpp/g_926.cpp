#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int main()
{
 ios::sync_with_stdio(0);
 int n, od = 0, ev = 0; cin >> n;
 for (int i = 0; i < n; i++)
 {
  int x; cin >> x;
  ev += (x % 2 == 0);
  od += (x % 2 == 1);
 }
 if (od <= ev)cout << od;
 else
 {
  cout << ev + ((od - ev) / 3);
 }
 return 0;
}