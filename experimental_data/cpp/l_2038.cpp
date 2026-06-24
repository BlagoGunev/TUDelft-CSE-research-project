//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
int n,lim=1167;
int main(){
	cin>>n;
	int ans=INF;
	for(int i=0;i<=lim;i++) for(int j=0;j+i<=lim;j++) for(int k=0;k+j+i<=lim;k++){
		int x25=(max(0,n-j-k)+1)/2;
		int x21=max(0,n-i*2-k);
		int x18=(max(0,n-i-j-x21*2)+2)/3;
		ans=min(ans,i+j+k+x18+x21+x25);
	}
	cout<<ans<<'\n';
	return 0;
}