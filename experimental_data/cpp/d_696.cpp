#include <bits/stdc++.h>



#define pb push_back

#define pp pop_back

#define mp make_pair

#define ld long double

#define f first

#define s second

#define ll long long



using namespace std;



const int N = 1e5 + 5;



const int mod = 1e9 + 7;



int n, m, a[N], sz = 1, c[N], qh, qt, q[N];



ll len, ans;



string s[N];



struct tree

{

  int to[26], aut[26], link;

  tree()

  {

    memset(to, 0, sizeof to);

    memset(aut, 0, sizeof aut);

  }

} T[N];



void add(int id)

{

  int u = 1;

  for (auto i : s[id])

  {

    int &to = T[u].to[i - 'a'];

    if (!to) to = ++sz;

    u = to;

  }

  c[u] += a[id];

}



void build()

{

  q[qt++] = 1;

  T[1].link = 1;

  while(qh < qt)

  {

    int v = q[qh++];

    c[v] += c[T[v].link];

    for (int ch = 0;ch < 26;ch++)

    {

      if (T[v].to[ch])

      {

        int x = T[v].to[ch];

        T[v].aut[ch] = x;

        if (v == 1) T[x].link = 1;

        else T[x].link = T[T[v].link].aut[ch];                 

        q[qt++] = x;

      }

      else

      {

        if (v == 1) T[v].aut[ch] = 1;

        else T[v].aut[ch] = T[T[v].link].aut[ch];

      }     

    }

  }

}



struct matrix

{

  int n, m;

  ll a[234][234];

  matrix()

  {

    n = m = 0;

    memset(a, 0, sizeof a);

  }

  matrix(int _n, int _m)

  {

    n = _n;

    m = _m;

    for (int i = 1;i <= n;i++)  

      for (int j = 1;j <= m;j++)

        a[i][j] = (ll) -1e18;

  }

  void out()

  {

    cout << "n = " << n << " m = " << m << endl;

    for (int i = 1;i <= n;i++)

    {

      for (int j = 1;j <= m;j++) cout << a[i][j] << " ";

      cout << endl;

    }

  }

};



int main()

{

  ios_base::sync_with_stdio(0);

	

  clock_t start = clock();



  cin >> n >> len;

  for (int i = 1;i <= n;i++) cin >> a[i];



  for (int i = 1;i <= n;i++)

  {

    cin >> s[i];    

    add(i);

  }

  build();



  matrix A(1, sz);

  A.a[1][1] = c[1];



  matrix B(sz, sz);

  for (int v = 1;v <= sz;v++)

  {

    for (int ch = 0;ch < 26;ch++)

    {

      int to = T[v].aut[ch];

      B.a[v][to] = c[to];

    }

  }



  for (len;len > 0;len >>= 1)

  {

    if (len & 1)

    {

      matrix c(A.n, B.m);

      for (int i = 1;i <= c.n;i++)

        for (int j = 1;j <= c.m;j++)

          for (int k = 1;k <= A.m;k++)

            c.a[i][j] = max(c.a[i][j], A.a[i][k] + B.a[k][j]);

      A = c;

    }

    matrix c(B.n, B.m);

    for (int i = 1;i <= c.n;i++)

      for (int j = 1;j <= c.m;j++)

        for (int k = 1;k <= B.m;k++)

          c.a[i][j] = max(c.a[i][j], B.a[i][k] + B.a[k][j]);

    B = c;

  } 



  for (int i = 1;i <= sz;i++) ans = max(ans, A.a[1][i]);



  cout << ans << endl;



  double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;

//  cout << "Time: " << fixed << setprecision(10) << duration << endl;

	

  return 0;

}