#include<bits/stdc++.h>

#define x first

#define y second

#define uid(a, b) uniform_int_distribution<int>(a, b)(eng)

using namespace std;

mt19937_64 eng(time(NULL));

using i64=long long;

template <typename T, class F = function<T(const T&, const T&)>>

class SparseTable {

 public:

  int n;

  vector<vector<T>> mat;

  F func;

 

  SparseTable(const vector<T>& a, const F& f) : func(f) {

    n = static_cast<int>(a.size());

    int max_log = 32 - __builtin_clz(n);

    mat.resize(max_log);

    mat[0] = a;

    for (int j = 1; j < max_log; j++) {

      mat[j].resize(n - (1 << j) + 1);

      for (int i = 0; i <= n - (1 << j); i++) {

        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);

      }

    }

  }

 

  T get(int from, int to) const {

    assert(0 <= from && from <= to && to <= n - 1);

    int lg = 32 - __builtin_clz(to - from + 1) - 1;

    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);

  }

};

void solve()

{     

  int n;

  vector<bool>st(26);

  string ans;

  vector<int>lst(26);

  string s;

  cin>>s;

  n=s.size();

  for(int i=0;i<n;i++)

    lst[s[i]-'a']=i;

  for(int i=0;i<s.size();i++)

  {    int v=s[i]-'a';

      if(st[v])continue;

      while(ans.size()&&ans.back()<s[i]&&lst[(ans.back()-'a')]>i)

      {

        st[ans.back()-'a']=0;

        ans.pop_back();

      }

      ans+=s[i];

      st[v]=true;

  }

  cout<<ans<<"\n";

}

int main()

{

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  int t;

  cin>>t;

  while(t--)

  solve();

  return 0;

}