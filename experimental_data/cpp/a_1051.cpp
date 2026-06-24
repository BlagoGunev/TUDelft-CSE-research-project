#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i, a, b) for(int (i) = a; (i) < (b);(i)++)

using ll = long long int;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VB = vector<bool>;
using VVB = vector<VB>;

string CHANG(string s){
  int a1, a2, a3, m;
  m = s.size();
  vector<int> h1, h2, h3;
  h1.resize(m);h2.resize(m);h3.resize(m);
  a1 = 0;a2 = 0;a3 = 0;
  for(int i = 0;i < s.size();i++){
    if('a' <= s.at(i) && 'z' >= s.at(i)){
      h1.at(a1) = i ;
      a1++;
    }
    else if('A' <= s.at(i) && 'Z' >= s.at(i)){
      h2.at(a2) = i;
      a2++;
    }

    else{
      h3.at(a3) = i;
      a3++;
    }
  }

  if(a1 > 0 && a2 > 0 && a3 > 0) return s;
  string p = s;
  if(a1 == 0){
    if(a2 == 0){
      p.at(0) = 'a';
      p.at(1) = 'A';
      return p;
    }
    if(a3 == 0){
      p.at(0) = 'a';
      p.at(1) = '1';
    }
    if(a2 > a3){
      p[h2[0]] = 'a';
      return p;
    }
    p[h3[0]] = 'a';
    return p;
  }
  if(a2 == 0){
    if(a3 == 0){
      p[0] = 'A';
      p[1] = '1';
    }
    if(a1 > a3){
      p[h1[0]] = 'A';
      return p;
    }
    else{
      p[h3[0]] = 'A';
      return p;
    }
  }
  if(a3 == 0){
    if(a1 > a2){
      p[h1[0]] = '1';
      return p;
    }
    else{
      p[h2[0]] = '1';
      return p;
    }
  }
}


int main(){
  int n;
  scanf("%d",&n);
  vector<string> S(n);
  REP(i,n) cin >> S.at(i);
  for(int k = 0;k < n;k++){
    cout << CHANG(S.at(k)) << endl;
  }
  return 0;
}