#include <vector>

#include <iomanip>

#include <memory>

#include <unordered_map>

#include <array>

#include <iostream>

#include <random>

#include <algorithm>

#include <set>

#include <queue>

#include <numeric>

#include <cassert>

#include <map>

#include <list>

#include <bitset>



void setBit(int64_t& v, int i, bool to) {

  if(to) {

    v |= ((int64_t)1 << i);

  }

  else {

    v &= 0xffffffffffffffff ^ ((int64_t)1 << i);

  }

}



bool getBit(int64_t v, int i) {

  return (v >> i) & 1;

}



bool check(int64_t mask, const std::vector<int64_t>& canChoose) {

  for(int i = 0; i < canChoose.size(); i++) {

    if(getBit(mask, i)) {

      if((canChoose[i] & mask) != mask) {

        return false;

      }

    }

  }

  return true;

}





int getValue(const int64_t mask, const std::vector<int>& costs) {

  int ans = 0;

  for(int i = 0; i < costs.size(); i++) {

    if(!getBit(mask, i)) {

      ans += costs[i];

    }

  }

  return ans;

}



void solve() {  

  int n, m;

  std::cin >> n >> m;

  std::vector<int> platforms(n);

  std::vector<int> costs(m);    



  for(auto& v : platforms) {

    std::cin >> v;

    v--;

  }  

  for(auto& v : costs) {

    std::cin >> v;

  }  



  std::vector<int64_t> canChoose(m, 0xffffffffffffffff);

  for(int i = 0; i < n - 1; i++) {

    setBit(canChoose[platforms[i]], platforms[i + 1], false);

    setBit(canChoose[platforms[i + 1]], platforms[i], false);

  }

  setBit(canChoose[platforms[0]], platforms[0], false);

  setBit(canChoose[platforms[n - 1]], platforms[n - 1], false);



  //int best = 1000000000;

  //for(int64_t i = 0; i < (1 << m); i++) {

  //  if(check(i, canChoose)) {

  //    best = std::min(best, getValue(i, costs));

  //  }

  //}





  int64_t numOfBitsFirst = m / 2;

  int64_t firstHalf = ((int64_t)1 << numOfBitsFirst);



  int64_t secondHalfMask = (((int64_t)1 << m) - 1) & (~(firstHalf - 1));



  std::vector<int> dp(firstHalf, 1000000000);

  for(int64_t i = 0; i < dp.size(); i++) {

    if(check(i, canChoose)) {

      dp[i] = std::min(dp[i], getValue(i | secondHalfMask, costs));

    }

    for(int64_t j = 0; j < numOfBitsFirst; j++) {

      if(!getBit(i, j)) {

        int64_t tmp = i;

        setBit(tmp, j, true);

        dp[tmp] = std::min(dp[tmp], dp[i]);

      }

    }

  }



  int best = 1000000000;



  int64_t numOfBitsSecond = m - numOfBitsFirst;

  int64_t secondHalf = ((int64_t)1 << numOfBitsSecond);

  for(int64_t i = 0; i < secondHalf; i++) {

    int64_t v = (i << numOfBitsFirst);    

    if(check(v, canChoose)) {

      int64_t mask = firstHalf - 1;

      for(int64_t j = numOfBitsFirst; j < numOfBitsFirst + numOfBitsSecond; j++) {

        if(getBit(v, j)) {

          mask &= canChoose[j];

        }

      }      

      best = std::min(best, getValue(v | (firstHalf - 1), costs) + dp[mask]);      

    }

  }



  std::cout << best;

}



int main() {  

  #define LOCAL_JUDGE

  #ifndef LOCAL_JUDGE

    freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

  #else

    //freopen("input.txt", "r", stdin);

    //freopen("output1.txt", "w", stdout);

    std::ios_base::sync_with_stdio(false);

    std::cin.tie(nullptr); 

  #endif         

  int t = 1;

  //std::cin >> t;

  for(int i = 0; i < t; i++) {

    solve();

    std::cout << "\n";

  }



  return 0;

}