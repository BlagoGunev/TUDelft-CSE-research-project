#include <bits/stdc++.h>

using namespace std;

#define type(x) __typeof((x).begin())
#define foreach(it, x) for(type(x) it = (x).begin(); it != (x).end(); it++)
#define ends ___ends

typedef long long ll;
typedef pair < int, int > ii;

const int inf = 1e9 + 333;
const ll linf = 1e18 + inf;

const int N = 1e5 + 5;
const int SQRT = 75;

int n, q, ptr;
char str[N];
string s[N];
ll ans[N];
int fin[N], fail[N], trie[N][26];
vector < int > v[N], ends[N];
int x[N], y[N], k[N];
vector < int > ord;
vector < int > qu[N];
 
void build() {
 for(int i = 1; i <= n; i++) {
  int x = 0;
  for(int j = 0; j < s[i].size(); j++) {
   int u = s[i][j];
   if(!trie[x][u]) {
    trie[x][u] = ++ptr;
   }
   x = trie[x][u];
  }
  fin[i] = x;
  ends[x].push_back(i);
 }
 ord.push_back(0);
 for(int it = 0; it < ord.size(); it++) {
  int x = ord[it];
  for(int i = 0; i < 26; i++) {
   if(trie[x][i]) {
    int u = trie[x][i];
    int q = fail[x];
    while(q and !trie[q][i]) {
     q = fail[q];
    }
    if(q != x and trie[q][i])
     q = trie[q][i];
    v[q].push_back(u);
    //printf("fail of %d = %d\n", u, q);
    fail[u] = q;
    ord.push_back(u);
   }
  }
 }
}

vector < pair < ii, int > > sq[N];

void get(int l, int r, int x, int id) {
 int q = 0;
 for(int i = 0; i < s[x].size(); i++) {
  int u = s[x][i];
  while(q and !trie[q][u]) {
   q = fail[q];
  }
  if(trie[q][u])
   q = trie[q][u];
  //printf("id = %d q = %d\n", id, q);
  sq[q].push_back(make_pair(ii(l, r), id));
 }
}

int fen[N];

void up(int x, int k) {
 for(; x < N; x += x & -x)
  fen[x] += k;
}

int get(int x, int y) {
 int res = 0;
 for(; y; y -= y & -y)
  res += fen[y];
 for(x--; x; x -= x & -x)
  res -= fen[x];
 return res;
}

void dfs(int x) {
 foreach(it, ends[x]) {
  int u = *it;
  up(u, 1);
 }
 foreach(it, sq[x]) {
  int l = it -> first.first;
  int r = it -> first.second;
  int i = it -> second;
  ans[i] += get(l, r);
 }
 foreach(it, v[x]) {
  int u = *it;
  dfs(u);
 }
 foreach(it, ends[x]) {
  int u = *it;
  up(u, -1);
 }
}

ll dp[N], cnt[N];

void solve(int x) {
 memset(dp, 0, sizeof(dp));
 memset(cnt, 0, sizeof(cnt));
 int q = 0;
 for(int i = 0; i < s[x].size(); i++) {
  int u = s[x][i];
  while(q and !trie[q][u]) {
   q = fail[q];
  }
  if(trie[q][u])
   q = trie[q][u];
  cnt[q]++;
 }
 for(int i = (int) ord.size() - 1; i >= 0; i--) {
  int x = ord[i];
  cnt[fail[x]] += cnt[x];
 }
 for(int i = 1; i <= n; i++) {
  dp[i] = dp[i - 1] + cnt[fin[i]];
 }
 foreach(it, qu[x]) {
  int i = *it;
  int l = :: x[i];
  int r = :: y[i];
  ans[i] = dp[r] - dp[l - 1];
 }
}

int main() {

 scanf("%d %d", &n, &q);

 for(int i = 1; i <= n; i++) {
  scanf("%s", str);
  s[i] = str;
  for(int j = 0; j < s[i].size(); j++)
   s[i][j] -= 'a';
 }

 build();

 for(int i = 1; i <= q; i++) {
  scanf("%d %d %d", x + i, y + i, k + i);
  if(s[k[i]].size() <= SQRT) {
   get(x[i], y[i], k[i], i);
  }
  else {
   qu[k[i]].push_back(i);
  }
 }

 dfs(0);
 
 for(int i = 1; i <= n; i++) {
  if(qu[i].size()) {
   solve(i);
  }
 }

 for(int i = 1; i <= q; i++) {
  printf("%lld\n", ans[i]);
 }
 
 return 0;

}