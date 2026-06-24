#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define oo 1000000010
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define getrand(l, r) uniform_int_distribution<int>(l, r)(rng)

const int N = 100010;

int n , arr[N];

long long sum[N];

long long dp[N];

bool check(long long mid){
	dp[n] = 0;
	int j = n - 1;
	deque < int > dq;

	for(int i = n - 1;i >= 0;i--){
		while(j > i && sum[j + 1] - sum[i + 1] > mid) j--;

		while((int)dq.size() > 0 && dq.back() > j + 1) dq.pop_back();
		if(j + 1 == n){
			dp[i] = arr[i];
		}
		else{
			dp[i] = arr[i] + dp[dq.back()];
		}
		while((int)dq.size() > 0 && dp[i] <= dp[dq.front()]) dq.pop_front();
		dq.push_front(i);
	}
	for(int i = 0 ;i < n && sum[i] <= mid;i++){
		if(dp[i] <= mid)
			return true;
	}
	return false;
}

void solve(){
	scanf("%d",&n);
	for(int i = 0 ;i < n;i++){
		scanf("%d",&arr[i]);
		sum[i + 1] = sum[i] + arr[i];
	}
	long long low = 1, high = (long long)n * oo , mid , res = (long long)n * oo;
	while(high >= low){
		mid = (low + high) / 2;
		if(check(mid))
			res = mid , high = mid - 1;
		else
			low = mid + 1;
	}
	printf("%lld\n",res);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}