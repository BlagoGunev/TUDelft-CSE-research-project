#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const int MAXN = 200005;
int str[MAXN]; //input
int _rank[MAXN], pos[MAXN]; //output
bool b2h[MAXN];
int ST[4*MAXN];
 
// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
  return str[a] < str[b];
}
 
void suffixSort(int n){
  //sort suffixes according to their first characters
  for (int i=0; i<n; ++i){
    pos[i] = i;
  }
  sort(pos, pos + n, smaller_first_char);
  //{pos contains the list of suffixes sorted by their first character}
 
  for (int i=0; i<n; ++i){
    ST[i + 2 * MAXN] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
  }
 
  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !ST[j + 2 * MAXN]) j++;
      ST[i + MAXN] = j;
      buckets++;
    }
    if (buckets == n) break;
    //{suffixes are separted in buckets containing strings starting with the same h characters}
 
    for (int i = 0; i < n; i = ST[i + MAXN]){
      ST[i] = 0;
      for (int j = i; j < ST[i + MAXN]; ++j){
        _rank[pos[j]] = i;
      }
    }
 
    ST[_rank[n - h]]++;
    b2h[_rank[n - h]] = true;
    for (int i = 0; i < n; i = ST[i + MAXN]){
      for (int j = i; j < ST[i + MAXN]; ++j){
        int s = pos[j] - h;
        if (s >= 0){
          int head = _rank[s];
          _rank[s] = head + ST[head]++;
          b2h[_rank[s]] = true;
        }
      }
      for (int j = i; j < ST[i + MAXN]; ++j){
        int s = pos[j] - h;
        if (s >= 0 && b2h[_rank[s]]){
          for (int k = _rank[s]+1; !ST[k + 2 * MAXN] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      pos[_rank[i]] = i;
      ST[i + 2 * MAXN] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    _rank[pos[i]] = i;
  }
}

int height[MAXN];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0
void getHeight(int n){
  for (int i=0; i<n; ++i) _rank[pos[i]] = i;
  height[0] = 0;
  for (int i=0, h=0; i<n; ++i){
    if (_rank[i] > 0){
      int j = pos[_rank[i]-1];
      while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
      height[_rank[i]] = h;
      if (h > 0) h--;
    }
  }
}

void build(int n, int b, int e) {
  if(b == e) {
    ST[n] = height[b];
    return;
  }

  int m = (b + e) >> 1;
  build(2 * n, b, m);
  build(2 * n + 1, m + 1, e);
  ST[n] = min(ST[2 * n], ST[2 * n + 1]);
}

int query(int n, int b, int e, int l, int r) {
  if(b == l && e == r) {
    return ST[n];
  }

  int m = (b + e) >> 1;

  if(r <= m) {
    return query(2 * n, b, m, l, r);
  } else if(l > m) {
    return query(2 * n + 1, m + 1, e, l, r);
  }
  return min(query(2 * n, b, m, l, m),
    query(2 * n + 1, m + 1, e, m + 1, r));
}

int getMin(int l, int r, int n) {
  if(l == r + 1) {
    return n - pos[r];
  }
  if(l > r + 1) {
    return 0;
  }
  return query(1, 1, n - 1, l, r);
}

vector<pair<int, pair<int, LL > > > st;

LL solve(const vi &a, const vi &b, int n) {
  int i = 1, j = 0;
  LL res = 0;
  st.clear();
  while(j < b.size()) {
    while(i < a.size() && a[i] <= b[j]) {
      int mn = getMin(a[i - 1] + 1, a[i], n);
      int cnt = 1;
      while(st.size() && st.back().FF >= mn) {
        cnt += st.back().SS.FF;
        st.pop_back();
      }
      LL lastsm = 0;
      if(st.size()) {
        lastsm += st.back().SS.SS;
      }
      st.pb(mp(mn, mp(cnt, cnt * 1LL * mn + lastsm)));
      i++;
    }
    int mn = getMin(a[i - 1] + 1, b[j], n);
    res += mn;
    for(int k = (int)st.size() - 1; k >= 0; k--) {
      if(st[k].FF <= mn) {
        res += st[k].SS.SS;
        break;
      }
      res += st[k].SS.FF * 1LL * mn;;
    }
    j++;
  }
  return res;
}

LL same(const vi &a, const vi & b, int n) {
  int i = 0, j = 0;
  LL res = 0;
  while(i < a.size() && j < b.size()) {
    if(a[i] < b[j]) {
      i++;
    } else if(a[i] > b[j]) {
      j++;
    } else {
      res += n - pos[a[i]];
      i++;
      j++;
    }
  }
  return res;
}

vi a,b;
int main() {
  int n,q;
  S2(n,q);
  string s;
  cin >> s;
  rep(i,0,n) str[i] = s[i] - 'a';
  s.clear();
  suffixSort(n);
  getHeight(n);
  if(n > 1) {
    build(1, 1, n - 1);
  }
  while(q--) {
    int k,l;
    S2(k,l);
    a.clear();
    b.clear();
    while(k--) {
      int x;
      S(x);
      a.pb(_rank[x - 1]);
    }
    while(l--) {
      int x;
      S(x);
      b.pb(_rank[x - 1]);
    }
    sort(all(a));
    sort(all(b));
    if(n == 1) {
      P(1);
      continue;
    }
    cout << solve(a, b, n) + solve(b, a, n) - same(a, b, n) << "\n";
  }
  return 0;
}