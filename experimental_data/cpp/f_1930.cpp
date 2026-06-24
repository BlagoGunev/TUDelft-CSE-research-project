#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define oo 1000000010
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define getrand(l, r) uniform_int_distribution<int>(l, r)(rng)

const int N = 1000010;
const int K = 22;
int n , k , q;

vector< bool > A , B;


void make(int val , vector< bool > &A){
	if(A[val])
		return;
	A[val] = true;
	for(int i = 0 ;i < k;i++){
		if(((val >> i) & 1) == 1){
			make(val ^ (1 << i) , A);
		}
	}
}



void solve(){
	scanf("%d%d",&n,&q);
	k = 0;
	while((1 << k) <= n) k++;


	A = vector< bool > ((1 << k) , false);
	B = A;

	int last = 0 , val , ans = 0;

	while(q--){
		scanf("%d",&val);
		val = (val + last) % n;

		make(val , A);
		make(val ^ ((1 << k) - 1), B);

		ans = 0;
		for(int i = k - 1;i >= 0;i--){
			if(A[ans ^ (1 << i)] && B[ans ^ (1 << i)])
				ans ^= (1 << i);
		}
		printf("%d ",ans);
		last = ans;
	}
	puts("");

}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	
	return 0;
}