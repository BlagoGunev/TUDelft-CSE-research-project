#include <bits/stdc++.h>
using namespace std;
#define int long long 

int MSBPowerTwo(int n) {
    int index = 0, count = 0;
	while(n != 0) {
		count++;
		if(n % 2 == 1) {
			index = count;
			
		}
		n /= 2;
	}
	return (1 << (index - 1));
}

bool sieve(int x){
	const int N=1e7 + 10;
	vector<bool> isPrime(N,1);
	vector<int> lp(N,0), hp(N,0);
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<N;i++){
		if(isPrime[i]==true){
			lp[i]=hp[i]=i;
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=false;
				hp[j]=i;
				if(lp[j]==0){
					lp[j]=i;
				}
			}
		}
	}
	return isPrime[x];
}
int binExp(int a, int b, int M){
	int ans=1;
	while(b){
		if(b&1){
			ans=(ans*1LL*a)%M;
		}
		a=(a*1LL*a)%M;
		b>>=1;
	}
	return ans;
}
void solve() {
	int a,b,c;
	cin>>a>>b>>c;

	unordered_map<int,int> m;
	m[1]=1;
	m[2]=11;
	m[3]=111;
	m[4]=1111;
	m[5]=11111;
	m[6]=111111;
	m[7]=1111111;
	m[8]=11111111;
	m[9]=111111111;

	int gc=m[c];
	int x=gc,y=gc;
	while(to_string(x).size()!=a){
		x=x*2;
	}
	while(to_string(y).size()!=b){
		y=y*3;
	}
	cout<<x<<" "<<y<<endl;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
 
	int t=1;
	cin>>t;
	while(t--){
		// google(i);
		solve();
	}
 	return 0;
	
}