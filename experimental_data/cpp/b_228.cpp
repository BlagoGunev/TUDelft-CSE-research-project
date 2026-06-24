#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;
#define rfor(I,A,B) for(int I = A; I < B; ++I)
#define ofor(I,B) rfor(I,0,B)
#define cfor(I,V) ofor(I,V.size())
#define wcin(N) while (cin >> N)
#define out(N) cout << N << endl
#define vout(N) cfor(I,N) cout << N[I] << " "; cout << endl
#define vin(N) cfor(I,N) cin >> N[I]
typedef unsigned long long ulld;
typedef long long lld;
typedef vector<vector<char> > vvi;
vvi a;
vvi b;

void read(vvi& v,int n,int m) {
  v = vvi(n, vector<char>(m));
  ofor(i,n) {
    ofor(j,m) {
      cin >> v[i][j];
      v[i][j] -= 48;
    }
  }
}

int lap(int x, int y) {
  int t = 0;
  int xl = max(0, -x);
  int xu = min((int)a.size(), ((int)b.size())-x);
  int yl = max(0, -y);
  int yu = min((int)a[0].size(), ((int)b[0].size())-y);
  //printf("    %d %d %d %d\n",xl,xu,yl,yu);
  rfor(i,xl,xu) {
    rfor(j,yl,yu) {
      //printf("%d %d %d %d\n",i,i+x,j,j+y);
      t += a[i][j] * b[i+x][j+y];
    }
  }
  return t;
}

int main() {
  int na,ma,nb,mb;
  cin >> na >> ma;
  read(a,na,ma);
  cin >> nb >> mb;
  read(b,nb,mb);
  int m = 0;
  int mx,my;
  for (int x = -51; x < 51; ++x) {
    for (int y = -51; y < 51; ++y) {
      //printf("%d %d\n",x,y);
      int q = lap(x,y);
      if (q > m) {
        m = q;
        mx = x;
        my = y;
      }
    }
  }
  out(mx << " " << my);
  return 0;
}