#include<bits/stdc++.h>



///TEMPLATE CODES BEGIN

using namespace std;

#define forn(i, n)  for(int i = 0;i < n;i ++)

#define FOR(i, a, b) for(int i = a;i <= b;i ++)

#define mp  make_pair

typedef long long ll;

typedef vector<int> vi;

#define pb push_back

///TEMPLATE CODES END

const int N = 1005;

int a[N];

int dp[N*N];



template<class X, class Y>

void minimize(X & u,Y v)

{

    u = min(u, v);

}

int main()

{

   // freopen("test.inp","r",stdin);

    int n,k;

    scanf("%d %d", &n, &k);

    forn(i, n) scanf("%d", &a[i]);

    sort(a, a + n);

    n = unique(a, a + n) - a;



    int m = a[0];

    forn(i, n) a[i] -= m;



    forn(i, N * N) dp[i] = k + 1;



    dp[0] = 0;



    FOR(i, 1, n - 1)

     FOR(j, a[i], a[i] * k)

     {

        minimize(dp[j], dp[j - a[i]] + 1);

     }

    forn(i, N * N)

     if(dp[i] <= k)

     {

         printf("%d ", i + k * m);

     }

}