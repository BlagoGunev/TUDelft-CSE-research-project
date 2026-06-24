#include <cstdio>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <stack>
#define pb push_back

#define mp make_pair
#define f first
#define s second
#define ll long long

using namespace std;

#define double long double
int main() {
  /*
  ifstream cin("test.in");
  ofstream cout("test.out");
  */

  int N; cin >> N;
  vector <double> P(N + 1);

  for (int i = 1; i <= N; ++i) {
    cin >> P[i];
  }

  sort(P.begin(), P.end());
  reverse(P.begin() + 1, P.end());


  double answer = 0;
  double pcur = 0, pneg = 1.0;

  for (int i = 1; i <= N; ++i) {
    pcur = pcur * (1 - P[i]) + P[i] * pneg;
    pneg *= (1 - P[i]);

    answer = max(answer, pcur);

  }

  cout << setprecision(10) << answer << "\n";
  return 0;
}