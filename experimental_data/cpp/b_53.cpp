#include <iostream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const double PI = 3.14159265359;
const double EPS = 1e-6;
// const int INF = (1e9);
const ll INF = ((ll)1 << 62);

const ll P = 1e9 + 7;


int fall(ll h, ll w){
  // 4/5 <= h/w <= 5/4
  if (4*w <= 5*h && 4*h <= 5*w) return 0;
  else if(h*4 > 5*w) return 1;
  else return -1;
}


int main(){
  std::ios::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;

  ll H = 1, W = 1, RH = 1, RW = 1;
  ll area = 1;

  //FIXED H
  while(H <= h) {
    // ll w1 = (4*H)/5;


    // ll w2 = (5*H);
    // if(w2 % 4 == 0) w2/=4;
    // else w2 = w2/4 + 1;
    ll l = 1, r = w;
    ll mid;

    while(l <= r){
      mid = l + (r-l)/2;
      // cout << mid << endl;
      if(fall(H, mid) == 0){
        if(mid < w && fall(H, mid+1) == 0) {
          l = mid+1;
        }
        else{
          if(H*mid >= area){
            // cout << H << " " << mid << endl;
            area = H*mid;
            RH = H;
            RW = mid;
          }
          break;
        }
      }
      else if(fall(H, mid) == 1){
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }


    H *= 2;
  }

  //FIXED W
  while(W <= w) {
    ll l = 1, r = h;
    ll mid;

    while(l <= r){
      mid = l + (r-l)/2;
      if(fall(mid, W) == 0){
        if(mid < h && fall(mid+1, W) == 0){
          l = mid+1;
        }
        else{
          if(mid*W > area){
            area = mid*W;
            RH = mid;
            RW = W;
          }
          else if(mid*W == area && mid > RH){
            RH = mid;
            RW = W;
          }
          break;
        }
      }
      else if(fall(mid, W) == 1){
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }


    W *= 2;
  }
  cout << RH << " " << RW << endl;

  return 0;
}