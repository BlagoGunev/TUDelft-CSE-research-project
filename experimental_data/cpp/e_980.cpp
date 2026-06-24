# include <bits/stdc++.h>

# define y1 asdjksjkdkjs

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(2e6) + 5;
const int inf = (int)1e9 + 9;

struct bit{
  ll t[N];
  void inc(int x, int y){
    for(; x < N; x += x & -x){
      t[x] += y;
    }
  }
  ll get(int x){
    ll ans = 0;
    for(; x > 0; x -= x & -x){
      ans += t[x];
    }
    return ans;
  }
}st;

int n, k;
int h[N], l[N], r[N], up[N], T, used[N];
vector < int > g[N];

void dfs(int v, int p){
  l[v] = ++T;
  up[v] = p;
  for(int i : g[v]){
    if(i != p){
      h[i] = h[v] + 1;
      dfs(i, v);
    }
  }
  r[v] = ++T;
}

int main(){
  scanf("%d %d", &n, &k);
  k = n - k;
  for(int i = 1; i < n; ++i){
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(n, 0);
  for(int i = 1; i <= n; ++i){
    st.inc(l[i], h[i]);
    st.inc(l[i] + 1, -h[i]);
  }
  used[n] = 1;
  vector < int > ans;
  int now = k - 1;
  int cnt = 1;
  for(int i = n - 1; i >= 1; --i){
    if(used[i]){
      continue;
    }
    int e = st.get(l[i]);
    if(now >= e){
      now -= e;
      int tmp = i;
      vector < int > me;
      while(true){
        if(used[tmp] || !tmp){
          break;
        }

        me.push_back(tmp);
        used[tmp] = 1;
        tmp = up[tmp];
      }
      reverse(me.begin(), me.end());
      for(int i : me){
        st.inc(l[i], -1);
        st.inc(r[i] + 1, 1);
      }
    }
  }
  for(int i = 1; i <= n; ++i){
    if(!used[i]){
      ans.push_back(i);
    }
  }
  for(int i : ans){
    printf("%d ", i);
  }
  return 0;
}