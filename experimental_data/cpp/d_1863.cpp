#include<bits/stdc++.h>

using namespace std;

const int N = 505;

char c[N][N], ok[N][N];

int n, m, cntx[N], cnty[N], sumx[N], sumy[N], tx[N], ty[N], T;

void S(){
  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    cntx[i] = 0;
    tx[i] = 0;
    sumx[i] = 0;
  }
  for(int i = 1; i <= m; ++i){
    cnty[i] = 0;
    ty[i] = 0;
    sumy[i] = 0;
  }
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cin >> c[i][j];
      cntx[i] += c[i][j] == 'U';
      cnty[j] += c[i][j] == 'L';
    }
  }
  for(int i = 1; i <= n; ++i){
    if(tx[i] > cntx[i] || tx[i] % 2 != cntx[i] % 2){
      cout << "-1\n";
      return;
    }
    if(i == n && cntx[i] != tx[i]){
      cout << "-1\n";
    }
    sumx[i] = (cntx[i] - tx[i]) % 2 + tx[i]; //涂成黑色
    tx[i + 1] += (tx[i] - cntx[i]) % 2;
  }
  for(int i = 1; i <= m; ++i){
    if(ty[i] > cnty[i] || ty[i] % 2 != cnty[i] % 2){
      cout << "-1\n";
      return;
    }
    if(i == m && cnty[i] != ty[i]){
      cout << "-1\n";
    }
    sumy[i] = (cnty[i] - ty[i]) % 2 + ty[i]; //涂成黑色
    ty[i + 1] += (ty[i] - cnty[i]) % 2;
  }
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      ok[i][j] = '.';
    }
  }
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(c[i][j] == 'U'){
        if(sumx[i] > 0){
          ok[i][j] = 'B';
          ok[i + 1][j] = 'W';
          sumx[i]--;
        }
        else{
          ok[i][j] = 'W';
          ok[i + 1][j] = 'B';
          sumx[i]++;
        }
      }
    }
  }
  for(int i = 1; i <= m; ++i){
    for(int j = 1; j <= n; ++j){
      if(c[j][i] == 'L'){
        if(sumy[i] > 0){
          ok[j][i] = 'B';
          ok[j][i + 1] = 'W';
          sumy[i]--;
        }
        else{
          ok[j][i] = 'W';
          ok[j][i + 1] = 'B';
          sumy[i]++;
        }
      }
    }
  }
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cout << ok[i][j];
    }
    cout << '\n';
  }
}

int main(){
  for(cin >> T; T--; S()){
  }
  return 0;
}