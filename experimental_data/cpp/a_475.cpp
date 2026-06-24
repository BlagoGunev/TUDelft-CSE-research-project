#include <bits/stdc++.h>

using namespace std;



#define fr first

#define sc second

#define null NULL

#define mp make_pair

#define pb push_back

#define LN(A) strlen(A)

#define SZ(A) int(A.size())

#define All(A) A.begin(), A.end()

#define rAll(A) A.rbegin(), A.rend()



typedef long long ll;

typedef vector<int> vi;

typedef pair<int, int> ii;

const double EPS = 1e-15, PI = acos(-1);

const int MOD = int(1e9) + 7, MX = int(5e6) + 1;



string S[7];

void solve() {

  S[0] = "+------------------------+",

  S[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)",

  S[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|",

  S[3] = "|#.,,,,,,,,,,,,,,,,,,,,,,|",

  S[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)",

  S[5] = "+------------------------+";

  int k; scanf("%d", &k);

  for(int i = 1; k && i <= 21; i += 2) {

    for(int j = 1; j <= 4 && k; j++) 

      if(S[j][i] == '#')

        S[j][i] = 'O', --k;

  }

  for(int i = 0; i < SZ(S[3]); i++) 

    if(S[3][i] == ',') S[3][i] = '.';

  for(int i = 0; i <= 5; i++) 

    cout << S[i] << "\n";

}



int main() {

#ifndef ONLINE_JUDGE

  freopen("in.txt", "r", stdin);

#else

  // freopen("", "r", stdin);

#endif

  solve();

}