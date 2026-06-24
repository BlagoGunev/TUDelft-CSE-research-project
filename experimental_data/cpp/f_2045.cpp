#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int val[200200];
 
void solve(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
 
	fill(val, val+k+1, 0);
 
	while(m--){
		int r, c, x;
		scanf("%d %d %d", &r, &c, &x);
		val[r%(k+1)] ^= x % (k+1);
	}
 
	for (int i=0;i<=k;i++) if (val[i]){
		printf("Anda\n");
		return;
	}
 
	printf("Kamu\n");
}
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--) solve();
}