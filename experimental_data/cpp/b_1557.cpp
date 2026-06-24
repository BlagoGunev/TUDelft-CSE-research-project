#include<cstdio>
#include<algorithm>
using namespace std;
#define BN long long
template<typename T>void read(T& a) {
	a = 0;
	static char ii, li;
	ii = getchar();
	while(ii > '9' || ii <'0') {
		li = ii;
		ii = getchar();
	}
	while(ii <= '9' && ii >= '0') {
		a = (a<<3) + (a<<1) + (ii ^ 48);
		ii = getchar();
	}
	if(li == '-')a = -a;
	li = ii;
	return;
}
template<typename T, typename ...U>void read(T& a, U& ...b) {
	read(a),read(b...);
}
pair<int, int > nums[100005];
int n, k, ans;
int main(){
	int T;
	read(T);
	while(T--){
		read(n, k);
		ans = 1;
		for(int i = 0; i < n; i++){
			read(nums[i].first);
			nums[i].second = i;
		}
		sort(nums, nums + n);
		for(int i = 1; i < n; i++){
			if(nums[i].second - nums[i - 1].second != 1){
				ans++;
			}
		}
		if(ans > k){
			printf("no\n");
		}else{
			printf("yes\n");
		}
	}
	return 0;
}