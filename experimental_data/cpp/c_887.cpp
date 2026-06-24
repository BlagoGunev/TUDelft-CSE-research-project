/*
Codeforces 444, Division 2, Problem C: Solution for cube
*/

/* theprof, Nov 3, 2017 */

/*
*/


#include <bits/stdc++.h>

using namespace std;

#define n 24
#define f 6

int a[n];
bool face[f];

void set_face(int i) {
  if ((a[i] == a[i+1]) && (a[i] == a[i+2]) && (a[i] == a[i+3]))
    face[i/4] = true;
}

bool rotate(int i1, int j1, int k1, int i2, int j2, int k2, int i3, int j3, int k3, int i4, int j4, int k4) {
  if ((a[i1] != a[i1+k1]) || (a[i2] != a[i2+k2]) || (a[i3] != a[i3+k3]) || (a[i4] != a[i4+k4]))
    return false;
  if ((a[j1] != a[j1+k1]) || (a[j2] != a[j2+k2]) || (a[j3] != a[j3+k3]) || (a[j4] != a[j4+k4]))
    return false;
  if (((a[i1] != a[j2]) || (a[i2] != a[j3]) || (a[i3] != a[j4]) || (a[i4] != a[j1])) && ((a[i1] != a[j4]) || (a[i2] != a[j1]) || (a[i3] != a[j2]) || (a[i4] != a[j3])))
    return false;
  return true;
}

int main() {
  int i;
  
  for (i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }

  for (i=0; i<n; i=i+4)
    set_face(i);

  if (face[0] && face[2]) {
    if (rotate(4, 6, 1, 12, 14, 1, 20, 22, 1, 16, 18, 1)) {
      cout << "YES" << endl;
      return 0;
    }
  }

  if (face[1] && face[5]) {
    if (rotate(2, 0, 1, 16, 17, 2, 8, 10, 1, 13, 12, 2)) {
      cout << "YES" << endl;
      return 0;
    }
  }

  if (face[3] && face[4]) {
    if (rotate(0, 1, 2, 4, 5, 2, 8, 9, 2, 21, 20, 2)) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}