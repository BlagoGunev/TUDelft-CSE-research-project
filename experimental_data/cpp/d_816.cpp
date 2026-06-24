#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
const int maxn = 200000+5;
const int M = 1000000007;

template<class T>
inline void _read(T& x){
	char ch = getchar(); bool mark = false;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') mark=true;
	for(x=0;isdigit(ch);ch=getchar()) x= x*10+ch-'0';
	if(mark) x=-x;
}

int n,A[maxn],fra[maxn],inv[maxn];

int C(int n,int m){
	return 1ll*fra[n]*inv[m]%M*inv[n-m]%M;
}

int main(){
	//freopen("data.in","r",stdin);
	int i,j; 
	_read(n);
	for(i=0;i<n;i++) _read(A[i]);
	if(n==1){
		cout<<A[0]<<endl;
		return 0;
	}
	inv[0] = inv[1] = fra[1] = fra[0] = 1;
	for(i=2;i<=n;i++){
		fra[i] = 1ll*fra[i-1]*i%M;
		inv[i] = 1ll*(M-M/i)*inv[M%i]%M;
	}
	for(i=2;i<=n;i++) inv[i] = 1ll*inv[i]*inv[i-1]%M;
	int flag = 0;
	if(n&1){
		for(i=0;i<n-1;i++){
			if(i&1) A[i] = A[i]-A[i+1];
			else A[i] = A[i] + A[i+1];
			if(A[i]>=M) A[i]-=M;
			if(A[i]<0) A[i]+=M;
		}
		n--;
	}
	int N = n/2-1,ans=0;
	for(i=0;i<n;i++){
		int cur = 1ll*C(N,i>>1)*A[i]%M;
		//printf("C[%d] = %d\n",i,C(N,i>>1));
		if(N&1){
			if(i&1) ans-=cur;
			else ans+=cur;
		}
		else ans+=cur;
		if(ans>=M) ans-=M;
		if(ans<0) ans+=M;
	}
	cout<<ans<<endl;
	return 0;
}