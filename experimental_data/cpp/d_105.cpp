// Authored by dolphinigle
// CodeForces 81
// 13 Aug 2011

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))
#define RESET(Z,Y) memset(Z,Y,sizeof(Z))

#define SZ(Z) ((int)Z.size())
#define ALL(W) W.begin(), W.end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-11

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;
typedef vector<ll> vll;

int peta[400][400];
int geodesi[400][400];
int sudah[400][400];
map<int, vector< pair<int,int> >* > miv;
map<int, int> hitung;
set<int> destroyed;
set<int> diluas;

int urut(int pr, int pc, int tr, int tc) {
  if (pr == tr && pc == tc) return 1;
  int kulit = max(abs(tr - pr), abs(tc - pc));
  int dasar = (kulit * 2 - 1) * (kulit * 2 - 1);
  if (tr == pr - kulit) {
    // di atas
    if (tc == pc - kulit) {
      // kiri atas =='
      return (kulit * 2 + 1) * (kulit * 2 + 1);
    }
    int dist = tc - (pc - kulit);
    return dasar + dist;
  }
  dasar += (kulit * 2);
  if (tc == pc + kulit) {
    // di kanan
    int dist = tr - (pr - kulit);
    return dasar + dist;
  }
  dasar += (kulit * 2);
  if (tr == pr + kulit) {
    // di bawah;
    int dist = tc - (pc - kulit);
    return dasar + (kulit * 2 - dist);
  }
  dasar += (kulit * 2);
  if (tc == pc - kulit) {
    // di kiri
    int dist = tr - (pr - kulit);
    return dasar + (kulit * 2 - dist);
  }
  assert(false);
}

int main() {

  int r,c;
  cin >> r >> c;
  FORN(i, r) {
    FORN(j, c) {
      scanf("%d", &(peta[i][j]));
      hitung[peta[i][j]]++;
      miv[peta[i][j]] = new vector< pair<int,int> >(0);
    }
  }

  FORN(i, r) {
    FORN(j, c) {
      scanf("%d", &(geodesi[i][j]));
      if (geodesi[i][j] == -1) continue;
      if (!miv.count(geodesi[i][j])) {
        miv[geodesi[i][j]] = new vector< pair<int,int> >(0);
      }
      miv[peta[i][j]]->push_back(MP(i, j));
    }
  }

  FORN(i, r) FORN(j, c) sudah[i][j] = 0;

  int sr, sc;
  cin >> sr >> sc;
  --sr;
  --sc;

  int luas = hitung[peta[sr][sc]];
  ll score = 0;
  int lastcolor = peta[sr][sc];
  diluas.insert(peta[sr][sc]);

  queue< pair<int,int> > qhell;
  qhell.push(MP(sr, sc));
  sudah[sr][sc] = 1;
  miv[peta[sr][sc]]->erase(find(miv[peta[sr][sc]]->begin(), miv[peta[sr][sc]]->end(), MP(sr, sc)));

  while (true) {
    if (lastcolor == 0) break;
    if (qhell.empty()) break;
    int tr = qhell.front().A;
    int tc = qhell.front().B;
    qhell.pop();
    if (lastcolor == geodesi[tr][tc]) continue;  // no change in color
    score += (ll) luas;
    if (!diluas.count(geodesi[tr][tc])) {
      diluas.insert(geodesi[tr][tc]);
      luas += hitung[geodesi[tr][tc]];
    }
    if (!destroyed.count(lastcolor)) {
      destroyed.insert(lastcolor);
      vector< pair<int, pair<int,int> > > yah;
      if (miv[lastcolor] != 0) {
        FORN(i, (int)miv[lastcolor]->size()) {
          int rr = miv[lastcolor]->operator[](i).A;
          int cc = miv[lastcolor]->operator[](i).B;
          //cout << urut(tr, tc, rr, cc) << " " << r << " " << c << endl;
          yah.PB(MP(urut(tr, tc, rr, cc), MP(rr, cc)));
        }
      }
      sort(ALL(yah));
      FORN(i, SZ(yah)) qhell.push(yah[i].B);
    }
    lastcolor = geodesi[tr][tc];
  }

  cout << score << endl;

  return 0;
}