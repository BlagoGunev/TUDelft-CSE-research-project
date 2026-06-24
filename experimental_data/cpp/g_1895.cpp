#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(42);

struct node
{
  long long x;
  int y;
  int cnt;
  int sum;
  int push;
  node* l;
  node* r;
  node() {};
  node(long long x, int y, int cnt, int sum, int push, node* l, node* r) : x(x), y(y), cnt(cnt), sum(sum), push(push), l(l), r(r) {};
};

typedef node* treap;
typedef pair<treap, treap> ptt;

int getSum(treap t)
{
  return (t ? t->sum : 0);
}

int getCnt(treap t)
{
  return (t ? t->cnt : 0);
}

treap fix(treap t)
{
  if(!t) return t;
  int p = t->push;
  if(p != 0)
  {
    if(t->l) t->l->push += p;
    if(t->r) t->r->push += p;
    t->x += p;
    t->push = 0;
  }
  t->sum = getSum(t->l) + t->cnt + getSum(t->r);
  return t;
}

treap merge(treap a, treap b)
{
  a = fix(a);
  b = fix(b);
  if(!a) return b;
  if(!b) return a;
  if(a->y > b->y)
  {
    a->r = merge(a->r, b);
    return fix(a);
  }
  else
  {
    b->l = merge(a, b->l);
    return fix(b);
  }
}

bool hasKey(treap t, long long x)
{
  t = fix(t);
  if(!t) return false;
  if(t->x == x) return true;
  if(t->x < x) return hasKey(t->r, x);
  return hasKey(t->l, x);
}

ptt splitKey(treap t, long long x)
{
  t = fix(t);
  if(!t) return make_pair(t, t);
  if(t->x < x)
  {
    ptt p = splitKey(t->r, x);
    t->r = p.first;
    return make_pair(fix(t), p.second);
  }
  else
  {
    ptt p = splitKey(t->l, x);
    t->l = p.second;
    return make_pair(p.first, fix(t));
  }
}

long long kthMax(treap t, int k)
{
  t = fix(t);
  if(!t) return -1;
  int sumR = getSum(t->r);
  if(sumR >= k) return kthMax(t->r, k);
  if(sumR + t->cnt >= k) return t->x;
  return kthMax(t->l, k - sumR - t->cnt);
}

int getCntByKey(treap t, long long x)
{
  t = fix(t);
  if(!t) return 0;
  if(t->x == x) return t->cnt;
  if(t->x > x) return getCntByKey(t->l, x);
  return getCntByKey(t->r, x);
}

treap increaseKey(treap t, long long x, int cnt)
{
  t = fix(t);
  if(!t) return t;
  if(t->x == x)
  {
    t->cnt += cnt;
  }
  else if(t->x > x)
  {
    t->l = increaseKey(t->l, x, cnt);
  }
  else
  {
    t->r = increaseKey(t->r, x, cnt);
  }
  return fix(t);
}

treap insert(treap t, long long x, int y, int cnt)
{
  t = fix(t);
  if(!t || t->y < y)
  {
    ptt p = splitKey(t, x);
    treap res = new node(x, y, cnt, cnt, 0, p.first, p.second);
    return fix(res);
  }
  if(t->x > x)
    t->l = insert(t->l, x, y, cnt);
  else
    t->r = insert(t->r, x, y, cnt);
  return fix(t);
}

treap insertMain(treap t, long long x, int cnt)
{
  if(hasKey(t, x))
    return increaseKey(t, x, cnt);
  else
    return insert(t, x, rnd(), cnt);
}

treap eraseKey(treap t, long long x)
{
  t = fix(t);
  if(!t) return NULL;
  if(t->x > x)
  {
    t->l = eraseKey(t->l, x);
    return fix(t);
  }
  if(t->x < x)
  {
    t->r = eraseKey(t->r, x);
    return fix(t);
  }
  treap tnew = merge(t->l, t->r);
  delete t;
  return tnew;
}

ptt splitSum(treap t, int k)
{
  t = fix(t);
  if(!t) return make_pair(t, t);
  if(k == 0) return make_pair(t, treap(NULL));
  long long x = kthMax(t, k);
  int cnt = getCntByKey(t, x);
  t = eraseKey(t, x);
  ptt p = splitKey(t, x);
  k -= getSum(p.second);
  if(k > 0) p.second = merge(new node(x, rnd(), k, k, 0, NULL, NULL), p.second);
  if(k < cnt) p.first = merge(p.first, new node(x, rnd(), cnt - k, cnt - k, 0, NULL, NULL));
  return p;
}

long long minKey(treap t)
{
  t = fix(t);
  if(!t) return 1e18;
  if(t->l) return minKey(t->l);
  return t->x;
}

treap decreaseUpToKLargest(treap t, int k, int& res)
{
  if(!k) return t;
  t = fix(t);
  k = min(k, getSum(t));
  res = k;
  ptt p = splitSum(t, k);
  if(p.second)
  {
    p.second->push--;
    for(int i = 0; i < 2; i++)
    {
        long long x = minKey(p.second);
        int cntMin = getCntByKey(p.second, x);
        p.second = eraseKey(p.second, x);
        if(x != 0 && cntMin != 0)
          p.first = insertMain(p.first, x, cntMin);
    }
  }
  return merge(p.first, p.second);
}

void destroy(treap t)
{
  if(!t) return;
  if(t->l) destroy(t->l);
  if(t->r) destroy(t->r);
  delete t;
}

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long> r(n), b(n);
  for(int i = 0; i < n; i++) cin >> r[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  long long sum = 0;
  for(int i = 0; i < n; i++) sum += r[i] + b[i];
  long long flow = 0;
  treap t = NULL;
  for(int i = 0; i < n; i++)
  {
    long long d = min(r[i], b[i]);
    flow += d;
    r[i] -= d;
    b[i] -= d;
    if(s[i] == '0')
    {
      int add = 0;
      if(r[i] > 1e9) r[i] = 1e9;
      t = decreaseUpToKLargest(t, r[i], add);
      flow += add;
    }
    else
    {
      if(r[i] != 0) t = insertMain(t, r[i], 1);
    }
  }
  cout << sum - flow << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) solve();
}