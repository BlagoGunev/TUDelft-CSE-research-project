#include<bits/stdc++.h>

#define x first

#define y second

using namespace std;

constexpr int P = 1e9+7;

using i64 = long long;

const int N=4e5+10;

// assume -P <= x < 2P

int norm(int x) {

    if (x < 0) {

        x += P;

    }

    if (x >= P) {

        x -= P;

    }

    return x;

}

template<class T>

T power(T a, i64 b) {

    T res = 1;

    for (; b; b /= 2, a *= a) {

        if (b % 2) {

            res *= a;

        }

    }

    return res;

}

struct Z {

    int x;

    Z(int x = 0) : x(norm(x)) {}

    Z(i64 x) : x(norm(x % P)) {}

    int val() const {

        return x;

    }

    Z operator-() const {

        return Z(norm(P - x));

    }

    Z inv() const {

        assert(x != 0);

        return power(*this, P - 2);

    }

    Z &operator*=(const Z &rhs) {

        x = i64(x) * rhs.x % P;

        return *this;

    }

    Z &operator+=(const Z &rhs) {

        x = norm(x + rhs.x);

        return *this;

    }

    Z &operator-=(const Z &rhs) {

        x = norm(x - rhs.x);

        return *this;

    }

    Z &operator/=(const Z &rhs) {

        return *this *= rhs.inv();

    }

    friend Z operator*(const Z &lhs, const Z &rhs) {

        Z res = lhs;

        res *= rhs;

        return res;

    }

    friend Z operator+(const Z &lhs, const Z &rhs) {

        Z res = lhs;

        res += rhs;

        return res;

    }

    friend Z operator-(const Z &lhs, const Z &rhs) {

        Z res = lhs;

        res -= rhs;

        return res;

    }

    friend Z operator/(const Z &lhs, const Z &rhs) {

        Z res = lhs;

        res /= rhs;

        return res;

    }

    friend std::istream &operator>>(std::istream &is, Z &a) {

        i64 v;

        is >> v;

        a = Z(v);

        return is;

    }

    friend std::ostream &operator<<(std::ostream &os, const Z &a) {

        return os << a.val();

    }

};

vector<Z>fac(N);

vector<Z>invfac(N);

Z cal(int n,int m)

{

  if(m<0||n<m)return 0;

  return invfac[n-m]*invfac[m]*fac[n];

}

Z all(int n,int m)

{

  return invfac[n-m]*fac[n];

}

void solve() 

{

  int n;

  cin>>n;

  vector dp(n+1,vector<Z>(n+1,0));

      vector<Z> inv(n + 1);

    for (int i = 1; i <= n; i++) 

        inv[i] = Z(1) / i;

  vector<vector<int>>adj(n);

  for(int i=0;i<n-1;i++)

  {

    int u,v;

    cin>>u>>v;

    u--,v--;

    adj[u].push_back(v);

    adj[v].push_back(u);

  }

  dp[0][0]=1;

  for(int i=1;i<=n;i++)

      {dp[0][i]=1;

       dp[i][0]=0;

      }

    for(int i=1;i<=n;i++)

      for(int j=1;j<=n;j++)

        {

          dp[i][j]=(dp[i-1][j]+dp[i][j-1])*inv[2];

        }

      Z ans=0;

    vector<Z>sz(n,0);

    vector<Z>dsum(n);

    function<void(int ,int)>dfs=[&](int u,int fa)

    {  

      sz[u]=1;

      for(auto v:adj[u])

      {

        if(v==fa)continue;

        dfs(v,u);

        sz[u]+=sz[v];

      }

    };

    function<void(int,int,int,int)>dfs1=[&](int u,int fa,int d,int root)

    {

      if(u<root)

      {

        for(int i=0;i<=d-1;i++)

          ans+=dsum[i]*inv[n]*(dp[i][d-i]);

      }

      for(auto v:adj[u])

      {

        if(v==fa)continue;

        dsum[d]=sz[u]-sz[v];

        dfs1(v,u,d+1,root);

      }

    };

    for(int i=0;i<n;i++)

    {

      dfs(i,-1);

      dfs1(i,-1,0,i);

    }

    cout<<ans<<"\n";

}

int main()

{

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  solve();

  return 0;

}