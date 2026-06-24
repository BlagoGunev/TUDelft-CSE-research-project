#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define ALL(x) begin(x),end(x)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
//freopen(name".in", "r", stdin);
//freopen(name".out", "w", stdout);
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
s<<"[ ";
for (auto it : c) s << it << " ";
s<<"]";
return s;
}

int main(){
  long long n,m;
  while(cin >> n >> m){
    while(n!=0 && m!=0){
      if(n >= 2*m){
        n %= 2*m;
      }
      else if(m >= 2*n){
        m %= 2*n;
      }
      else{
        break;
      }
    }
    cout <<  n << " " << m << endl;
  }
}