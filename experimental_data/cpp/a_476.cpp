#include <bits/stdc++.h>



using namespace std;



int n, m;



int main () {

  cin >> n >> m;

  if (n < m) {

   cout << -1;

  } else {

   cout << (((n + 1) / 2) + m - 1) / m * m;

  }

  return 0;

}