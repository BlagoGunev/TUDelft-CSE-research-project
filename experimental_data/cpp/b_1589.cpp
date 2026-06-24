/*
Author:Imy_bisLy
知识点：
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#define ll long long
using namespace std;

const int inf = 0x3f3f3f3f;
//=============================================================
int n, m;
//=============================================================
int read() {
  int s = 0 , f = 0 ; char ch = getchar() ;
  while(!isdigit(ch)) f |= (ch == '-') , ch = getchar();
  while(isdigit(ch)) s = s * 10 + (ch ^ 48) , ch = getchar();
  return f ? -s : s;
}

int main() {
  int T = read();
  while(T--) {
    n = read(), m = read();
    if (n < m) swap(n, m);
    int ans = 0;
    ans += n / 3 * m;
    ans += m / 3 * (n % 3);
    int x = n % 3, y = m % 3;
    if( x < y) swap(x, y);
    if(x == 1 && y == 1) ans++;
    if(x == 2 && y == 1) ans += 1;
    if(x == 2 && y == 2) ans += 2;
    cout << ans <<"\n";
  }
  // system("pause");
  return 0;
}