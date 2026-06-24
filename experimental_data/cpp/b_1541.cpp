#include <bits/stdc++.h>

auto solve() -> decltype(auto){
         int n;
         std::cin >> n;
         std::vector<int> A(n);

         for(int i = 0;i < n;i++){
                  std::cin >> A[i];
         }

         int64_t ans = 0;

         for(int i = 0;i < n;i++){
                  const int me = A[i],idx = i + 1;
                  const int low = idx + 1,high = idx * 2 - 1;

                  int start = low / me * me;

                  if(start < low){
                           start += me;
                  }

                  for(int j = start;j <= high;j += me){

                           int thatidx = j - idx;

                           int need = j / me;

                           if(A[thatidx-1] == need) ans++;
                          
                  }
         }

         std::cout << ans << '\n';
}

int32_t main(void){
         std::ios::sync_with_stdio(false);std::cin.tie(0);
	uint32_t tcs = 1;
	std::cin >> tcs;
	for(uint32_t i = 1;i <= tcs;i++) solve();
}