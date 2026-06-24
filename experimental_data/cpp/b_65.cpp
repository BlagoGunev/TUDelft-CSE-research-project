#include <bits/stdc++.h>

using namespace std;



int n, a[1024];



bool check(int i, int j) {

  int c = 0;

  while (i) {

    c += ((i % 10) != (j % 10));

    i /= 10, j /= 10;

  }

  return c <= 1;

}



int main() {

  cin >> n;

  for (int i = 1; i <= n; i++) {

    cin >> a[i];

  }

  for (int i = 1; i <= n; i++) {

    int f = 1;

    for (int j = 1000; j <= 2011; j++) {

      if (check(a[i], j) && j >= a[i - 1]) {

        a[i] = j, f = 0;

        break;

      }

    }

    if (f) {

      cout << "No solution";

      return 0;

    }

  }

  for (int i = 1; i <= n; i++) {

    cout << a[i] << endl;

  }

}