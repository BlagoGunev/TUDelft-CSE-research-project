#include <cctype>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define ALLOF(s) ((s).begin()), ((s).end())

typedef long long LL;

char field[1234][1234];
int memo[1234][1234][4];

struct State {
  int x, y;
  bool ok;
};

enum DIR {
  NORTH = 0,
  EAST,
  SOUTH,
  WEST
};

int main(void) {
  
  int nRows, nCols;
  scanf("%d %d", &nRows, &nCols);
  REP(i, nRows){
    scanf("%s", field[i]);
  }
  
  State cands[26];
  REP(i, 26)
    cands[i].ok = false;
  
  REP(i, nRows){
    REP(j, nCols){
      char ch = field[i][j];
      if(ch == '#')
	continue;
      memo[i][j][NORTH] = memo[i-1][j][NORTH] + 1;
      memo[i][j][WEST] = memo[i][j-1][WEST] + 1;
      if(isalpha(ch)){
	int idx = ch - 'A';
	cands[idx].x = j;
	cands[idx].y = i;
	cands[idx].ok = true;
      }
    }
  }
  
  for(int i = nRows-1; i >= 0; i--){
    for(int j = nCols-1; j >= 0; j--){
      if(field[i][j] == '#')
	continue;
      memo[i][j][SOUTH] = memo[i+1][j][SOUTH] + 1;
      memo[i][j][EAST] = memo[i][j+1][EAST] + 1;
    }
  }
  
  int nInst;
  scanf("%d", &nInst);
  
  REP(i, nInst){
    char sdir[8];
    int len, dir;
    scanf("%s%d", sdir, &len);
    switch(sdir[0]){
    case 'N':
      dir = NORTH;
      break;
    case 'E':
      dir = EAST;
      break;
    case 'S':
      dir = SOUTH;
      break;
    case 'W':
      dir = WEST;
      break;
    default:
      assert(false);
    }
    
    const int DY[4] = {-1, 0, 1, 0};
    const int DX[4] = {0, 1, 0, -1};
    
    REP(j, 26){
      State& st = cands[j];
      if(st.ok){
	if(memo[st.y][st.x][dir] > len){
	  st.y += DY[dir] * len;
	  st.x += DX[dir] * len;
	}else{
	  st.ok = false;
	}
      }
    }
  }

  int count = 0;
  REP(i, 26){
    if(cands[i].ok){
      cout << (char)(i + 'A');
      count++;
    }
  }
  if(count == 0){
    cout << "no solution" << endl;
  }else{
    cout << endl;
  }
  
  return 0;
}