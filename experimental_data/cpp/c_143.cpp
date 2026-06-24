#include <bits/stdc++.h>

using namespace std;



#ifdef LOCAL_CHECK

#define trace(x) cerr << #x << ": " << x << " ";

#define trnl cerr << "\n";

#else

#define trace(x) {}

#define trnl {}

#endif

typedef long long lolo;

typedef unsigned long long ulolo;

typedef pair<int, int> pii;

#define F(i,a,b) for(int i=(a);i<(b);++i)

#define R(i,n) F(i,0,n) 

#define FD(i,n) for(int i=(n-1);i>=0;--i)

#define SZ(x) ((int)(x).size())

#define ALL(x) (x).begin(),(x).end()

#define fi first

#define se second

#define M_PI           3.14159265358979323846



const int INF = 1e9 + 23;

const int MOD = 1e9 + 9;

const int N = 1e5 + 10;



int main()

{

  ios_base::sync_with_stdio(0);

  int n;

  cin >> n;

  lolo mn = INF * 1LL * INF, mx = 0;

  for (int a = 1; a*1LL*a*a <= n; ++a) if (n%a == 0) {

    for (int b = 1; b*1LL*b <= n/a; ++b) if ((n/a)%b == 0) {

      int c = n/a / b;

      int arr[] = {a, b, c};

      do {

        lolo v = (arr[0]+1) * 1LL * (arr[1]+2) * (arr[2]+2);

        mn = min(mn, v-n);

        mx = max(mx, v-n);

      } while (next_permutation(arr, arr + 3));

    }

  }

  cout << mn << " "  << mx << "\n";

}

// g++ -W -Wall -Wextra -pedantic -std=c++0x -o p main.cpp