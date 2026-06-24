#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sl(x) scanf("%lld",&x)
#define p printf
double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> sums(n + 1, 0);
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-6) {
            double minSum = 0, mid = left + (right - left) / 2;
            bool check = false;
            for (int i = 1; i <= n; ++i) {
                sums[i] = sums[i - 1] + nums[i - 1] - mid;
                if (i >= k) {
                    minSum = min(minSum, sums[i - k]);
                }
                if (i >= k && sums[i] > minSum) {check = true; break;} 
            }
            if (check) left = mid;
            else right = mid;
        }
        return left;
    }
int main()
 {
    
      int n,p,k;
      cin>>n>>k;
      vector<int>v;
      for(int i=0;i<n;i++)
      {
          cin>>p;
          v.push_back(p);
      }
      std::cout<<std::fixed;
  std::cout << std::setprecision(15)<<findMaxAverage(v,k);

}