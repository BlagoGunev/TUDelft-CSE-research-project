//I am very very hardworking!
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

//#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

const int N = int(1e5)+10;
const int B = 400;
double add[B], mul[B], vals[N], sum[B];
int n, L[B], R[B], BLOCK[N];
void updateBlock(int b){
  b =  BLOCK[b];
  FOR(i, L[b], R[b]){
    vals[i] = vals[i] * mul[b] + add[b];
  }
  mul[b] = 1;
  add[b] = 0;
}
void ADD(int l, int r, double v){
  trace(l, r, v, "add");
  updateBlock(l);
  updateBlock(r);
  FOR(i, l, min(r + 1, R[BLOCK[l]])){
    trace(i, vals[i], v);
    vals[i] += v;
    sum[BLOCK[i]] += v;
  }
  if(BLOCK[l] == BLOCK[r])return;
  FOR(i, L[BLOCK[r]], r + 1){
    vals[i] += v;
    sum[BLOCK[i]] += v;
  }
  FOR(i, BLOCK[l] + 1, BLOCK[r]){
    add[i] += v;
    sum[i] += v * (R[i] - L[i]);
  }
}
void mult(int l, int r, double v){
  trace(l, r, v, "mul");
  updateBlock(l);
  updateBlock(r);
  FOR(i, l, min(r + 1, R[BLOCK[l]])){
    trace(i, vals[i], v);
    sum[BLOCK[i]] -= vals[i];
    vals[i] = vals[i] * v;
    sum[BLOCK[i]] += vals[i];
  }
  if(BLOCK[l] == BLOCK[r])return;
  FOR(i, L[BLOCK[r]], r + 1){
    sum[BLOCK[i]] -= vals[i];
    vals[i] = vals[i] * v;
    sum[BLOCK[i]] += vals[i];
  }
  FOR(i, BLOCK[l] + 1, BLOCK[r]){
    mul[i] = mul[i] * v;
    add[i] = add[i] * v;
    sum[i] = sum[i] * v;
  }
}
double query(int l, int r){
  trace("query", l, r);
  double ret = 0;
  FOR(i, l, min(r + 1, R[BLOCK[l]])){
    //trace(i, vals[i], mul[BLOCK[i]], add[BLOCK[i]]);
    ret += vals[i] * mul[BLOCK[i]] + add[BLOCK[i]];
  }
  trace(ret);
  if(BLOCK[l] == BLOCK[r])return ret;
  FOR(i, L[BLOCK[r]], r + 1){
    ret += vals[i] * mul[BLOCK[i]] + add[BLOCK[i]];
  }
  FOR(i, BLOCK[l] + 1, BLOCK[r]){
    ret += sum[i];
  }
  trace(ret);
  return ret;
}
int main()
{
  int n, q;
  si(n);si(q);
  REP(i, B){
    L[i] = R[i] = -1;
    add[i] = 0;
    mul[i] = 1;
    sum[i] = 0;
  }
  REP(i, n){
    BLOCK[i] = i / B;
    if(L[BLOCK[i]] == -1)L[BLOCK[i]] = i;
    R[BLOCK[i]] = i + 1;
 }
  REP(i, n){
    int x;si(x);
    ADD(i, i, x);
  }
  while(q--){
    int t;si(t);
    if(t == 1){
      int l1, r1, l2, r2;
      scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
      l1--;r1--;l2--;r2--;
      double sum = query(l2, r2);
      double sum2 = query(l1, r1);
      double p = (r2 - l2 + 1.0);
      sum /= p;
      mult(l2, r2, (p - 1) / p);
      p = (r1 - l1 + 1.0);
      sum2 /= p;
      mult(l1, r1, (p - 1) / p);
      ADD(l1, r1, sum / (r1 - l1 + 1));
      ADD(l2, r2, sum2 / (r2 - l2 + 1));
    }
    else {
      int l, r;
      si(l);si(r);
      l--;r--;
      printf("%.10lf\n", query(l, r));
    }
  }



	return 0;
}