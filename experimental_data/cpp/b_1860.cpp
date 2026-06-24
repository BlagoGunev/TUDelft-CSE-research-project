#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <math.h>

using namespace std;

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int q;
  cin >> q;
  for(int w = 0; w < q; ++w){
    long long int m, k, a, b;
    cin >> m >> k >> a >> b;
    long long int ot = 0;
    if(m % k > a){
        ot += m%k - a;
        m -= m%k;
        a = 0;
    }else{
        a -= m%k;
        m -= m%k;
    }
    a -= a%k;
    m -= a;
    m /= k;
    if(m > 0){
       if(b > m){
        cout << ot << "\n";
       }else{
        ot += m - b;
        cout << ot << "\n";
       }
    }else{
       cout << ot << "\n";
    }
  }
  return 0;
}