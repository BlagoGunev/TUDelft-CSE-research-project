#include <bits/stdc++.h>



using namespace std;



const int N = 310;



typedef pair <int, int> pi;



int n;

int l[N], c[N];

priority_queue <pi, vector <pi>, greater <pi> > pq;

map <int, bool> used;



int gcd(int a, int b) {

  while (a > 0 && b > 0) {

    if (a >= b) {

      a %= b;

    } else {

      b %= a;

    }

  }

  return a + b;

}



int main() {

  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {

    scanf("%d", &l[i]);

  }

  for (int j = 1; j <= n; j++) {

    scanf("%d", &c[j]);

  }

  pq.push(make_pair(0, 0));

  while (!pq.empty()) {

    int cost = pq.top().first;

    int _gcd = pq.top().second;

    pq.pop();

    if (used[_gcd] == true) continue;

    used[_gcd] = true;

    if (_gcd == 1) {

      printf("%d", cost);

      return 0;

    }

    for (int i = 1; i <= n; i++) {

      pq.push(make_pair(cost + c[i], gcd(_gcd, l[i])));

    }

  }

  puts("-1");

  return 0;

}