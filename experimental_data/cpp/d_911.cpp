#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << "  - " << #x << ": " << x << endl;
#define debugs(x, y) cerr << "  - " << #x << ": " << x << "         " << #y << ": " << y << endl;
#define sep() cerr << "--------------------" << endl;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)x.size()
#define fi first
#define se second
#define mp make_pair

typedef long long ll;

int readInt () {
 bool minus = false;
 int result = 0;
 char ch;
 ch = getchar();
 while (true) {
  if (ch == '-') break;
  if (ch >= '0' && ch <= '9') break;
  ch = getchar();
 }
 if (ch == '-') minus = true; else result = ch-'0';
 while (true) {
  ch = getchar();
  if (ch < '0' || ch > '9') break;
  result = result*10 + (ch - '0');
 }
 if (minus)
  return -result;
 else
  return result;
}
const int N = 1505;
int a[N], tree[2 * N];

int n;
void add(int idx, int v){
 for(int i = idx; i <= n; i += i & (-i)){
  tree[i] += v;
 }
 
}
int get(int idx){
 int r = 0;
 for(int i = idx; i > 0; i -= i & (-i))
  r += tree[i];
 return r;
}


int main(){
 //ios::sync_with_stdio(false);
 n = readInt();
 for(int i = 0; i < n; i++)
  a[i] = readInt();

 int res = 0;
 for(int i = n - 1; i >= 0; i--){
  add(a[i], 1);
  res += get(a[i] - 1);
 }
 int x = res & 1;

 int m = readInt();
 while(m--){
  int l = readInt(), r = readInt();
  int s = (r - l + 1) / 2;
  if(s & 1) x ^= 1;
  if(x == 1) puts("odd");
  else puts("even");
 }
 return 0;
}