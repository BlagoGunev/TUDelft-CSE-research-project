// Problem: D. Kevin and Numbers
// Author: XZC(L_Wave)
// Language: Cpp/G++20
// Contest: Codeforces - IAEPC Preliminary Contest (Codeforces Round 999, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2061/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Create Time: not 2025-01-20 22:56:45, but 1926-08-17 11:45:14
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), i##ABRACADABRA = (b); i <= i##ABRACADABRA; i++)
#define drep(i, a, b) for (int i = (a), i##ABRACADABRA = (b); i >= i##ABRACADABRA; i--)
using namespace std;
using ll = long long;

int n,m;
multiset<int>A,B;

void solve(){
  A.clear(),B.clear();
  scanf("%d%d",&n,&m);
  rep(i,1,n){
    int x;
    scanf("%d",&x);
    A.insert(x);
  }
  rep(i,1,m){
    int x;
    scanf("%d",&x);
    B.insert(x);
  }
  while (B.size()){
    int x=*B.begin();
    if (!A.size()||x<*A.begin()){
      puts("No");
      return ;
    }
    if (A.count(x)){
      A.erase(A.find(x));
      B.erase(B.begin());
      continue;
    }
    B.erase(B.begin());
    B.insert(x/2);
    B.insert(x-x/2);
  }
  if (!A.size())puts("Yes");
  else puts("No");
}

int main() {
  int tt;
  scanf("%d",&tt);
  while (tt--)solve();
  return 0;
}